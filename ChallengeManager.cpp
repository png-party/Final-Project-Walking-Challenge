/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
    https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#include "ChallengeManager.h"

#include <fstream>
#include <iostream>

using namespace std;

ChallengeManager::ChallengeManager()
{
	cout << "Challenge Manager created." << endl;
}

ChallengeManager::~ChallengeManager()
{
	cout << "Challenge Manager destroyed." << endl;
}

void ChallengeManager::loadData(const ifstream& file)
{
	if (!file.is_open())
	{
		cout << "Error: could not open file" << endl;
		return;
	}
	Hood* OldTowne = new Hood("Old Towne");
	Hood* ElModena = new Hood("El Modena");
	Hood* OrangeHills = new Hood("Orange Hills");
	Hood* SantiagoCreek = new Hood("Santiago Creek");
	Hood* VillaPark = new Hood("Villa Park");
	Hood* NorthElCamino = new Hood("North El Camino Real");

	allCities.addNode(OldTowne, 0);
	allCities.addNode(ElModena, 0);
	allCities.addNode(OrangeHills, 0);
	allCities.addNode(SantiagoCreek, 0);
	allCities.addNode(VillaPark, 0);
	allCities.addNode(NorthElCamino, 0);
	string s;
	while (getLine(file, s))
	{
		String name = "";
		int id;
		int totalMiles;
		int field = 1;
		for (int i = 0; i < s.length(); i++)
		{
			if (field == 1 && isspace(s[i]))
			{
				id = stoi(s.substr(0, i));
				s = s.substr(i - 1, str.length());
				field++;
			}
			else if (field == 2 || field == 3 && isspace(s[i]))
			{
				name += s.substr(0, i);
				s = s.substr(i - 1, str.length());
				field++;
			}
			else if (field == 3 && isspace(s[i]))
			{
				//
			}
		}
	}
}





	void ChallengeManager::createPerson(const string & name)
	{
		auto newUser = new Person(name);
		allParticipants.push_back(newUser);
	}

	void ChallengeManager::createCity(const string & name)
	{
		auto newCity = new Hood(name);
		allCities.push_back(newCity);
	}

	void ChallengeManager::removePerson(const string & name)
	{
		for (int i = 0; i < allParticipants.size(); i++)
		{
			if (allParticipants[i]->getName() == name)
			{
				Person* p = allParticipants[i];
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
						if (currentCity->getTotalMiles() - currentLog->getMiles() > 0)
						{
							currentCity->setTotalMiles(currentCity->getTotalMiles() - currentLog->getMiles());
						}
						else currentCity->setTotalMiles(0);

						//Remove the person's entry from the city's walking log
						Node* entryToRemove = currentCity->getList().findNode(p->getName());
						currentCity->getList().removeNode(entryToRemove);
					}
				}
				delete p;
				allParticipants.erase(allParticipants.begin() + i);
				return;
			}
		}
	}

	void ChallengeManager::removeCity(const string & name)
	{
		for (int i = 0; i < allCities.size(); i++)
		{
			if (allCities[i]->getName() == name)
			{
				Hood* h = allCities[i];
				cout << "Neighborhood \"" << name <<
					"\" was found\nRemoving the city from participants' walking activity..." << endl;

				//Traverse the city's walking data list to find people who walked there
				Node* currentLog = h->getList().getFirst();
				while (currentLog)
				{
					//Get the pointer to the corresponding person
					if (auto currentPerson = dynamic_cast<Person*>(currentLog->getData()))
					{
						//Remove the miles that person walked in that city
						if (currentPerson->getTotalMiles() - currentLog->getMiles() > 0)
						{
							currentPerson->setTotalMiles(currentPerson->getTotalMiles() - currentLog->getMiles());
						}
						else currentPerson->setTotalMiles(0);

						//Remove the person's entry from the city's walking log
						Node* entryToRemove = currentPerson->getList().findNode(h->getName());
						currentPerson->getList().removeNode(entryToRemove);
					}
				}
				delete h;
				allCities.erase(allCities.begin() + i);
				return;
			}
		}
	}

	void ChallengeManager::lookUpPerson(const string & name) const
	{
		Person* p = findPerson(name);
		cout << "\n====" << p->getName() << "'s statistics====\nTotal miles walked: " << p->getTotalMiles() <<
			"\nTotal neighborhoods visited: " << p->getList().getNodeCount() << endl;
		p->printMinMaxWalks();
	}


	void ChallengeManager::recordWalk(Hood * h, Person * p, int milesWalked) const
	{
		Hood* h = findCity(h->getName());
		Person* p = findPerson(personName);

		//Verify that the user is trying to record data for valid locations/people
		if (!h || !p)
		{
			cout << "Make sure to create the neighborhoods/people first!" << endl;
			return;
		}

		if (milesWalked <= 1)
		{
			cout << "You must record a walk one mile or greater" << endl;
		}

		//Update person's neighborhoods walking log
		Node* currentCity = p->getList().findNode(cityName);

		//Find the city in their walking activity, or create a new log if they've never walked there
		if (currentCity) currentCity->setMiles(currentCity->getMiles() + milesWalked);
		else p->getList().addNode(h, milesWalked);

		//Add the person's activity to the corresponding city's walking log
		Node* currentPerson = h->getList().findNode(personName);

		//Find the participant in the city's walking activity, or create a new log if they've never walked there
		if (currentPerson) currentPerson->setMiles(currentPerson->getMiles() + milesWalked);
		else h->getList().addNode(p, milesWalked);

		//Update both the city's and person's mile totals
		p->setTotalMiles(p->getTotalMiles() + milesWalked);
		h->setTotalMiles(h->getTotalMiles() + milesWalked);
		cout << "Recorded " << personName << "'s walk in " << cityName << endl;
	}

	Person* ChallengeManager::findPerson(const string & name) const
	{
		Person* p = allParticipants.findNode(name)->getData();
		if (!p) cout << "Error: participant \"" << name << "\" was not found in manager!" << endl;

		return p;
	}


	Hood* ChallengeManager::findCity(const string & name) const
	{
		for (Hood* h : allCities)
		{
			if (h->getName() == name) return h;
		}
		cout << "Error: neighborhood \"" << name << "\" was not found in manager!" << endl;
		return nullptr;
	}

