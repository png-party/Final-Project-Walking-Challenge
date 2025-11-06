/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
    https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
    https://www.geeksforgeeks.org/cpp/how-to-read-from-a-file-in-cpp/
    https://www.hlsl.co.uk/blog/2017/12/1/c-noexcept-and-move-constructors-effect-on-performance-in-stl-containers
    https://cppscripts.com/cpp-delete-copy-constructor
*/
#include "ChallengeManager.h"
#include "Person.h"

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

ChallengeManager::ChallengeManager()
{
	cout << "Challenge Manager created." << endl;
}

ChallengeManager::~ChallengeManager()
{
	//Delete all of the memory from people objects
	Node* p = allParticipants.getFirst();
	while (p)
	{
		delete p->getData();
		p = p->getNext();
	}

	//Delete all of the memory from hood objects
	Node* h = allCities.getFirst();
	while (h)
	{
		delete h->getData();
		h = h->getNext();
	}
	cout << "Challenge Manager destroyed." << endl;
}

void ChallengeManager::loadData(ifstream& file)
{
	if (!file.is_open())
	{
		cout << "Error: could not open file" << endl;
		return;
	}
	//These objects are created based on data.txt
	string s;
	while (getline(file, s))
	{
		string name;
		int field = 1;
		Person p = Person("temp");
		for (unsigned int i = 0; i < s.length(); i++) //Comparing .length() gives a warning if i isn't an unsigned int
		{
			if (isspace(s[i]))
			{
				//Record ID
				if (field == 1)
				{
					int id = stoi(s.substr(0, i));
					s = s.substr(i + 1, s.length() - i);
					p.setUserId(id);
					i = 0;
					field++;
				}
				//Record name
				else if (field == 2 || field == 3)
				{
					name += s.substr(0, i);
					s = s.substr(i, s.length() - i + 1);
					if (field == 3) p.setName(name);
					i = 0;
					field++;
				}
				//Record Old Towne data
				else if (field == 4)
				{
					double ot = stod(s.substr(1, i));
					s = s.substr(i, s.length() - i + 1);
					if (ot > 0) p.recordWalk(0, ot);
					i = 0;
					field++;
				}
				//Record El Modena data
				else if (field == 5)
				{
					double em = stod(s.substr(1, i));
					s = s.substr(i, s.length() - i + 1);
					if (em > 0) p.recordWalk(1, em);
					i = 0;
					field++;
				}
				//Record Orange Hills data
				else if (field == 6)
				{
					double oh = stod(s.substr(0, i));
					s = s.substr(i + 1, s.length() - i + 1);
					if (oh > 0) p.recordWalk(2, oh);
					i = 0;
					field++;
				}
				//Record Santiago Creek data
				else if (field == 7)
				{
					double sc = stod(s.substr(0, i));
					s = s.substr(i + 1, s.length() - i + 1);
					if (sc > 0) p.recordWalk(3, sc);
					i = 0;
					field++;
				}
				//Record Villa Park & North El Camino Real data
				else if (field == 8)
				{
					double vp = stod(s.substr(0, i));
					s = s.substr(i, s.length() - i);
					if (vp > 0) p.recordWalk(4, vp);
					double ec = stod(s.substr(1, s.length() - 1));
					if (ec > 0) p.recordWalk(5, ec);
				}
			}
		}
		allParticipants.addNode(p);
	}
}

void ChallengeManager::createPerson(const string& name)
{
	Person* newUser = new Person(name);
	allParticipants.addNode(newUser, 0);
}

void ChallengeManager::createCity(const string& name)
{
	Hood* place = new Hood(name);
	allCities.addNode(place, 0);
}

void ChallengeManager::removePerson(const string& name)
{
	Node* allParticipantsLocation = allParticipants.findNode(name);
	if (auto p = dynamic_cast<Person*>(allParticipantsLocation->getData()))
	{
		cout << "Person \"" << name <<
			"\" was found\nRemoving the person's walking activity from their neighborhoods..." << endl;

		//Traverse the person's walking data list to find the neighborhoods they walked in
		Node* currentLog = p->getList().getFirst();
		while (currentLog)
		{
			//Get the pointer to the corresponding neighborhood
			if (auto currentCity = dynamic_cast<Hood*>(currentLog->getData()))
			{
				//Remove the person's contributed miles from the city
				currentCity->setTotalMiles(currentCity->getTotalMiles() - currentLog->getMiles());

				//Remove the person's entry from the city's walking log
				Node* entryToRemove = currentCity->getList().findNode(p->getName());
				currentCity->getList().removeNode(entryToRemove);
			}
			currentLog = currentLog->getNext();
		}
		allParticipants.removeNode(allParticipantsLocation);
		delete p;
	}
}

bool ChallengeManager::removeCity(const string& cityName)
{
	cout << "Removing \"" << cityName << "\"..." << endl;
	for (unsigned int i = 0; i < Person::allCities.size(); i++)
	{
		if (Person::allCities[i] == cityName)
		{
			//Remove entry from list of cities
			Person::allCities.erase(Person::allCities.begin() + i);

			//Remove city from people's data
			Node* current = allParticipants.getFirst();
			while (current)
			{
				Person* p = current->getData();
				//Only modify people who have recorded a walk at that location
				if (p->getList().size() - 1 >= i)
				{
					p->getList().erase(p->getList().begin() +i);
				}
				current = current->getNext();
			}
			cout << "==>Neighborhood \"" << cityName << "\" was found and removed!" << endl;
			return true;
		}
	}
	cout << "==>Neighborhood \"" << cityName << "\" was not found" << endl;
	return false;
}

void ChallengeManager::getPersonStats(const string& name) const
{
	Person* p = findPerson(name);
	cout << "\n====" << p->getName() << "'s statistics====\nTotal miles walked: " << p->getTotalMiles() <<
		"\nTotal neighborhoods visited: " << p->getList().size() << endl;
	p->printMinMaxWalks();
	cout << "=====================\n" << endl;
}


/*Returns the person in the challenge with the most amount of miles walked
 * There is also a method in the Hood class to get the top walker in
 * a specific city, too
 */
Person* ChallengeManager::getMostActive() const
{
	Person* p = dynamic_cast<Person*>(allParticipants.getFirst()->getData());
	if (!p)
	{
		cout << "No one has participated in the challenge yet!" << endl;
		return p;
	}
	Node* current = allParticipants.getFirst();
	while (current)
	{
		if (current->getData()->getTotalMiles() > p->getTotalMiles())
		{
			p = dynamic_cast<Person*>(current->getData());
		}
		current = current->getNext();
	}
	cout << "Participant " << p->getName() << " has walked the most miles with a total of " << p->getTotalMiles() <<
		" miles walked!" << endl;
	return p;
}


Hood* ChallengeManager::findCity(const string& name) const
{
	Hood* h = dynamic_cast<Hood*>(allCities.findNode(name)->getData());
	if (!h) cout << "Error: neighborhood \"" << name << "\" was not found in manager!" << endl;
	return h;
}

