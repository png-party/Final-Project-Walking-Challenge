/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
	https://www.geeksforgeeks.org/cpp/how-to-read-from-a-file-in-cpp/
	https://www.hlsl.co.uk/blog/2017/12/1/c-noexcept-and-move-constructors-effect-on-performance-in-stl-containers
	https://www.geeksforgeeks.org/cpp/if-memory-allocation-using-new-is-failed-in-c-then-how-it-should-be-handled/
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
						 * The .insert() method returns an iterator which has a pair
						 * object  with two 
						 * Set the Person* pointer to hold the memory address of the
						 * value of the person object that was just created
						 */
						p = &personMap.insert({name, Person(name, userId) }).first->second;
						
						//Modify the person object's instance variables with the data we collected
						//if (insertedKeyValue) p = insertedKeyValue.first->second;
						//else break;
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
		if (Node* newUser = new (nothrow) Node(*p))
		{
			allParticipants.addNode(newUser);
		}
		else {
			cout << "Memory allocation failed!" << endl;
			break;
		}
	
	}
}

void ChallengeManager::createPerson(const string& name)
{
	cout << "Creating participant \"" << name << "\"..." << endl;
	if (Node* newUser = new (nothrow) Node(Person(name, lastId)))
	{
		allParticipants.addNode(newUser);
		lastId++;
	}
	else cout << "Memory allocation failed!" << endl;

}

void ChallengeManager::addPerson(const string& name)
{
	cout << "Adding participant \"" << name << "\"..." << endl;

	/* returns a pair: {first = iterator, second = boolean for success} */
	auto inserted = personMap.insert({name, Person(name, lastId)});
	lastId++;
	if (inserted.second) cout << "==>Participant \"" << name << "\" was successfully added!" << endl;
	else  cout << "==>Participant \"" << name << "\" could not be added" << endl;

}

void ChallengeManager::addCity(const string& name)
{
	cout << "Adding city \"" << name << "\"..." << endl;
	if (getCityIndex(name) == -1)
	{
		allCities.push_back(name);
		cout << "==>City \"" << name << "\" was successfully added!" << endl;
	}
	else cout << "===>That city already exists!" << endl;
}

void ChallengeManager::deletePerson(const string& name)
{

	cout << "Removing \"" << name << "\"..." << endl;
	/* Returns # of elements removed (either 0 or 1) */
	if (personMap.erase(name) == 1) cout << "==>Participant \"" << name << "\" was successfully removed!" << endl;
	else cout << "==>Participant \"" << name << "\" could not be found and removed" << endl;
}

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
		if ((int)p->getList().size() - 1 >= cityIndex)
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

void ChallengeManager::createCity(const string& name)
{
	cout << "Creating city \"" << name << "\"..." << endl;
	if (getCityIndex(name) == -1) allCities.push_back(name);
	else cout << "That city already exists!" << endl;
}

void ChallengeManager::removePerson(const string& name)
{
	cout << "Removing \"" << name << "\"..." << endl;
	if (allParticipants.removeNode(name)) cout << "==>Participant \"" << name << "\" was found and removed!" << endl;
	else cout << "==>Participant \"" << name << "\" could not be found and removed" << endl;
	allParticipants.removeNode(name);
}

bool ChallengeManager::removeCity(const string& cityName)
{
	cout << "Removing \"" << cityName << "\"..." << endl;
	int i = getCityIndex(cityName);
	if (i == -1) //Exit if index wasn't found
	{
		cout << "==>Neighborhood \"" << cityName << "\" was not found!" << endl;
		return false;
	}

	//Remove city from people's data
	Node* current = allParticipants.getFirst();
	if (current)
	{
		while (current)
		{
			Person* p = current->getData();
			//Only modify people who have indexes affected by removing the city
			if ((int)p->getList().size() - 1 >= i)
			{
				//Update their total miles
				p->setTotalMiles(p->getTotalMiles() - p->getList()[i]);
				//Remove index from their list
				p->getList().erase(p->getList().begin() + i);
			}
			current = current->getNext();
		}
	}
	
	//Remove entry from list of cities
	allCities.erase(allCities.begin() + i);
	cout << "==>Neighborhood \"" << cityName << "\" was found and removed!" << endl;
	return true;
} 

void ChallengeManager::clearParticipants()
{
	cout << "Clearing all participants..." << endl;
	allParticipants.clear();
}

void ChallengeManager::getPersonStatsMap(const string& name)
{
	auto p = personMap.find(name);
	if (p == personMap.end()) cout << "==>Requested person wasn't found!" << endl;
	p->second.printStats(allCities);
}

void ChallengeManager::printPersonMap() const
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
		return;
	}
	p->second.printPersonList(allCities);
}

void ChallengeManager::getPersonStats(const string& name) const
{
	Person* p = getPerson(name);
	p->printStats(allCities);
} 

void ChallengeManager::printMostActive() const
{
	cout << "Looking for most active participant..." << endl;
	Person* p = allParticipants.getFirst()->getData();
	Node* current = allParticipants.getFirst();
	if (!p || !current)
	{
		cout << "==>No one has participated in the challenge yet!" << endl;
		return;
	}
	
	while (current)
	{
		if (current->getData()->getTotalMiles() > p->getTotalMiles())
		{
			p = current->getData();
		}
		current = current->getNext();
	}
	if (p->getTotalMiles() >= 0) cout << "==>Participant " << p->getName() << " has walked the most miles with a total of " << p->getTotalMiles() <<
		" miles walked!" << endl;
	else cout << "==>No one has recorded a walk longer than 0 miles yet!" << endl;
} 

void ChallengeManager::printAllParticipants() const
{
	cout << "\n======================Today's Walking Challenge=====================" << endl;
	int i = 1;
	Node* current = allParticipants.getFirst();
	if (!current) cout << "No one has participated in the challenge yet!" << endl;
	else
	{
		while (current)
		{
			cout << "\t" << i << ".) " << current << endl;
			i++;
			current = current->getNext();
		}
	}
	cout << "====================================================================" << endl;
}

int ChallengeManager::getCityIndex(const string& name) const
{
	for (int i = 0; i < (int)allCities.size(); i++)
	{
		if (allCities[i] == name) return i;
	}
	return -1;
}

Person* ChallengeManager::getPerson(const string& name) const
{
	return allParticipants.findNode(name)->getData();
}

