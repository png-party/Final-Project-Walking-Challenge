/*
Christiandior Falucho, Nicole Sirbu, Mohamed Ziq, Nicholas Donaldson
CMPR 131 - Fall 2025
November 22nd, 2025
Final Project #2
Collaboration:
	https://en.cppreference.com/w/cpp/container/unordered_map.html
	https://en.cppreference.com/w/cpp/utility/pair.html
	https://www.geeksforgeeks.org/cpp/different-ways-to-initialize-an-unordered_map-in-cpp/
	https://www.geeksforgeeks.org/cpp/traversing-a-map-or-unordered_map-in-cpp-stl/
*/
#include "ChallengeManager.h"
#include "Person.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
ChallengeManager::ChallengeManager()
{
	cout << "Challenge Manager created." << endl;
	lastId = 151;
}

void ChallengeManager::loadData(ifstream& file)
{
	if (!file.is_open())
	{
		cout << "Error: could not open file" << endl;
		return;
	}
	/* The participants' data is based on the selected text file,
	 * but their recorded cities are based on the six given cities
	 * from the assignment */
	string s;
	while (getline(file, s))
	{
		string name;
		int userId;
		Person* p = nullptr;
		
		int field = 1;
		
		for (int i = 0; i < (int) s.length(); i++)
		{
			if (isspace(s[i]))
			{
				//Record ID
				if (field == 1)
				{
					userId = stoi(s.substr(0, i));
					s = s.substr(i + 1, s.length() - i);
					i = 0;
					field++;
				}
				//Record name
				else if (field == 2 || field == 3)
				{
					name += s.substr(0, i);
					s = s.substr(i, s.length() - i + 1);
					if (field == 3)
					{
						/* Insert a person object into the unordered map,
						 * using their name as the key to generate the position.
						 *
						 * The .insert() method returns a pair object with two variables,
						 * the first is the iterator pointing to the key-value
						 * the second is a boolean indicating if it was successful
						 *
						 * If second is true, then set the Person* pointer to hold the memory address of the
						 * value of the person object that was just created
						 */
						auto temp = personMap.insert({ name, Person(name, userId) });
						if (!temp.second) {
							cout << "\n==>Failed to insert \"" << name << ",\" participant might be a duplicate" << endl;
							continue; //Skip the rest of the iteration if it fails
						}
						p = &temp.first->second; //Otherwise keep going and store the memory address of the person object
					}
					i = 0;
					field++;
				}
				//Record Old Towne data
				else if (field == 4)
				{
					double ot = stod(s.substr(1, i));
					s = s.substr(i, s.length() - i + 1);
					if (ot > 0) p->recordWalk(0, ot, allCities);
					i = 0;
					field++;
				}
				//Record El Modena data
				else if (field == 5)
				{
					double em = stod(s.substr(1, i));
					s = s.substr(i, s.length() - i + 1);
					if (em > 0) p->recordWalk(1, em, allCities);
					i = 0;
					field++;
				}
				//Record Orange Hills data
				else if (field == 6)
				{
					double oh = stod(s.substr(0, i));
					s = s.substr(i + 1, s.length() - i + 1);
					if (oh > 0) p->recordWalk(2, oh, allCities);
					i = 0;
					field++;
				}
				//Record Santiago Creek data
				else if (field == 7)
				{
					double sc = stod(s.substr(0, i));
					s = s.substr(i + 1, s.length() - i + 1);
					if (sc > 0) p->recordWalk(3, sc, allCities);
					i = 0;
					field++;
				}
				//Record Villa Park & North El Camino Real data
				else if (field == 8)
				{
					double vp = stod(s.substr(0, i));
					s = s.substr(i, s.length() - i);
					if (vp > 0) p->recordWalk(4, vp, allCities);
					double ec = stod(s.substr(1, s.length() - 1));
					if (ec > 0) p->recordWalk(5, ec, allCities);
				}
			}
		} 
	}
}

/* Adding participants now takes O(1) on average
 * Previously, with the linked list, the program needed to
 * traverse the entire list to check that the added person
 * wasn't a duplicate before it could append the person to
 * the end of the list. Now the unordered map checks for
 * duplicate keys while inserting at the specific position */
void ChallengeManager::addPerson(const string& name)
{
	cout << "Adding participant \"" << name << "\"..." << endl;

	/* Returns a pair: {first = key-value iterator, second = boolean for success} */
	auto inserted = personMap.insert({name, Person(name, lastId)});
	if (inserted.second) {
		cout << "==>Participant \"" << name << "\" was successfully added!" << endl;
		lastId++;
	}
	else cout << "==>Participant \"" << name << "\" could not be added" << endl;
}

void ChallengeManager::addCity(const string& name)
{
	cout << "Adding city \"" << name << "\"..." << endl;
	if (getCityIndex(name) == -1)
	{
		allCities.push_back(name);
		cout << "==>City \"" << name << "\" was successfully added!" << endl;
	}
	else cout << "==>That city already exists!" << endl;
}

/* Deleting a participant now takes O(1) on average instead of O(n)
 * because the program no longer needs to look through every single node
 * for the corresponding person. */
void ChallengeManager::deletePerson(const string& name)
{
	cout << "Removing \"" << name << "\"..." << endl;
	/* Returns # of elements removed (either 0 or 1) */
	if (personMap.erase(name) == 1) cout << "==>Participant \"" << name << "\" was successfully removed!" << endl;
	else cout << "==>Participant \"" << name << "\" could not be found and removed" << endl;
}

/* Deleting a city still takes O(n) for getting the valid city index
 * and O(n) to check if every participant needs to have their vector
 * containing their walking data modified once the city is removed,
 * but now traversing is more convenient with a for each loop */
void ChallengeManager::deleteCity(const string& name)
{
	cout << "Removing \"" << name << "\"..." << endl;

	int cityIndex = getCityIndex(name);
	if (cityIndex == -1) //Exit if index wasn't found
	{
		cout << "==>City \"" << name << "\" was not found!" << endl;
		return;
	}
	for (auto current : personMap)
	{
		//Access person object within the pair
		Person* p = &current.second;
		//Only modify people who have indexes affected by removing the city
		if ((int) p->getList().size() - 1 >= cityIndex)
		{
			//Update their total miles
			p->setTotalMiles(p->getTotalMiles() - p->getList()[cityIndex]);
			//Remove index from their list
			p->getList().erase(p->getList().begin() + cityIndex);
		}
	}
	allCities.erase(allCities.begin() + cityIndex);
	cout << "==>City \"" << name << "\" was found and removed!" << endl;

}

/* Removing all of the participants still takes O(n)
 * for both linked lists and unordered maps, so the
 * new implementation didn't change the time complexity */
void ChallengeManager::clearParticipants()
{
	cout << "Clearing all participants..." << endl;
	if (personMap.empty())
	{
		cout << "==>The unordered map is already empty.\n";
	}else{
		personMap.clear();
	}
}

/* Since unordered maps are good for searching quickly,
 * getting a person's stats now takes O(1) on average */
void ChallengeManager::getPersonStats(const string& name)
{
	auto p = personMap.find(name);
	if (p == personMap.end()) cout << "==>Requested person wasn't found!" << endl;
	else p->second.printStats(allCities);
}

void ChallengeManager::printAllPersons() const
{
	cout << "\n======================Today's Walking Challenge=====================" << endl;
	int count = 1;
	for (auto i : personMap)
	{
		cout << "\t" << count << ".) " << i.second << endl;
		count++;
	}
	cout << "====================================================================" << endl;
}

Person* ChallengeManager::getPersonObject(const string& name)
{
	return &personMap.find(name)->second;
}

/* Logging a walk is now faster since getting the relevant person now takes O(1) on
 * average. However, we still need to traverse the allCities vector to make sure the
 * city is valid before attempting to log the walk */
bool ChallengeManager::logWalk(const string& personName, const string& cityName, double miles)
{
	auto p = personMap.find(personName);
	if (p ==  personMap.end())
	{
		cout << "==>Participant \"" << personName << "\" was not found" << endl;
		return false;
	}
	int i = getCityIndex(cityName);
	if (i == -1) //Exit if index wasn't found
	{
		cout << "==>Neighborhood \"" << cityName << "\" was not found" << endl;
		return false;
	}
	p->second.recordWalk(i, miles, allCities);
	return true;
} 

void ChallengeManager::printPersonWalks(const string& personName) const
{
	auto p = personMap.find(personName);
	if (p == personMap.end())
	{
		cout << "==>Participant \"" << personName << "\" was not found" << endl;
	}
	else p->second.printPersonList(allCities);
}

void ChallengeManager::printMostActive() const
{
	cout << "Finding the most active participant..." << endl;
	double most_active_total_miles = 0;
	string most_active_person = "";
	if (personMap.empty())
	{
		cout << "==>No one has participated in the challenge yet!" << endl;
		return;
	}

	for(const auto& person: personMap){
		if(person.second.getTotalMiles() > most_active_total_miles)
		{
			most_active_total_miles = person.second.getTotalMiles();
			most_active_person = person.first;
		}
	}
	if (most_active_total_miles > 0) cout << "==>The most active person is: " << most_active_person << " with a total of " << most_active_total_miles << " miles recorded! " << endl;
	else cout << "==>No participant has recorded a walk longer than 0 miles!" << endl;
} 

int ChallengeManager::getCityIndex(const string& name) const
{
	for (int i = 0; i < (int) allCities.size(); i++)
	{
		if (allCities[i] == name) return i;
	}
	return -1;
}

