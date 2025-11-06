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
		cout << p.getTotalMiles() << endl;
		allParticipants.addNode(new Node(p));
	}
}

void ChallengeManager::createPerson(const string& name)
{
	Node* newUser = new Node(Person(name));
	allParticipants.addNode(newUser);
}

void ChallengeManager::createCity(const string& name)
{
	if (getCityIndex(name) == -1) Person::allCities.push_back(name);
	else cout << "That city already exists!" << endl;
}

void ChallengeManager::removePerson(const string& name)
{
	allParticipants.removeNode(name);
}

/*This is const because it doesn't actually modify anything from CM*/
bool ChallengeManager::removeCity(const string& cityName) const
{
	cout << "Removing \"" << cityName << "\"..." << endl;
	int i = getCityIndex(cityName);
	if (i == -1) //Exit if index wasn't found
	{
		cout << "==>Neighborhood \"" << cityName << "\" was not found" << endl;
		return false;
	}
	//Remove entry from list of cities
	Person::allCities.erase(Person::allCities.begin() + i);

	//Remove city from people's data
	Node* current = allParticipants.getFirst();
	while (current)
	{
		Person* p = current->getData();
		//Only modify people who have indexes affected by removing the city
		if (p->getList().size() - 1 >= i)
		{
			p->getList().erase(p->getList().begin() + i);
		}
		current = current->getNext();
	}
	cout << "==>Neighborhood \"" << cityName << "\" was found and removed!" << endl;
	return true;
}

void ChallengeManager::getPersonStats(const string& name) const
{
	Person* p = getPerson(name);
	cout << "\n====" << p->getName() << "'s statistics====\nTotal miles walked: " << p->getTotalMiles() <<
		"\nTotal neighborhoods visited: " << p->getList().size() << endl;
	p->printMinMaxWalks();
	cout << "=====================\n" << endl;
}

void ChallengeManager::printMostActive() const
{
	Person* p = allParticipants.getFirst()->getData();
	if (!p)
	{
		cout << "No one has participated in the challenge yet!" << endl;
	}
	Node* current = allParticipants.getFirst();
	while (current)
	{
		if (current->getData()->getTotalMiles() > p->getTotalMiles())
		{
			p = current->getData();
		}
		current = current->getNext();
	}
	cout << "Participant " << p->getName() << " has walked the most miles with a total of " << p->getTotalMiles() <<
		" miles walked!" << endl;
}


int ChallengeManager::getCityIndex(const string& name)
{
	for (int i = 0; i < Person::allCities.size(); i++)
	{
		if (Person::allCities[i] == name) return i;
	}
	return -1;
}

Person* ChallengeManager::getPerson(const string& name) const
{
	return allParticipants.findNode(name)->getData();
}

