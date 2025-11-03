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
	while (getline(file, s))
	{
		string name = "";
		int field = 1;
		Person* p = new Person("temp");
		allParticipants.addNode(p, 0);
		for (unsigned int i = 0; i < s.length(); i++) //Comparing .length() gives a warning if i isn't an unsigned int
		{
			if (isspace(s[i]))
			{
				//Record ID
				if (field == 1)
				{
					int id = stoi(s.substr(0, i));
					s = s.substr(i + 1, s.length() - i);
					p->setUserId(id);
					i = 0;
					field++;
				}
				//Record name
				else if (field == 2 || field == 3)
				{
					name += s.substr(0, i);
					s = s.substr(i, s.length() - i + 1);
					if (field == 3) p->setName(name);
					i = 0;
					field++;
				}
				//Record Old Towne data
				else if (field == 4)
				{
					double ot = stod(s.substr(1, i));
					s = s.substr(i, s.length() - i + 1);
					if (ot > 0) recordWalk(OldTowne, p, ot);
					i = 0;
					field++;
				}
				//Record El Modena data
				else if (field == 5)
				{
					double em = stod(s.substr(1, i));
					s = s.substr(i, s.length() - i + 1);
					if (em > 0) recordWalk(ElModena, p, em);
					i = 0;
					field++;
				}
				//Record Orange Hills data
				else if (field == 6)
				{
					double oh = stod(s.substr(0, i));
					s = s.substr(i + 1, s.length() - i + 1);
					if (oh > 0) recordWalk(OrangeHills, p, oh);
					i = 0;
					field++;
				}
				//Record Santiago Creek data
				else if (field == 7)
				{
					double sc = stod(s.substr(0, i));
					s = s.substr(i + 1, s.length() - i + 1);
					if (sc > 0) recordWalk(SantiagoCreek, p, sc);
					i = 0;
					field++;
				}
				//Record Villa Park & North El Camino Real data
				else if (field == 8)
				{
					double vp = stod(s.substr(0, i));
					s = s.substr(i, s.length() - i);
					if (vp > 0) recordWalk(VillaPark, p, vp);
					double ec = stod(s.substr(1, s.length() - 1));
					if (ec > 0) recordWalk(NorthElCamino, p, ec);
				}
			}
		}
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

void ChallengeManager::removeCity(const string& name)
{
	Node* allCitiesLocation = allCities.findNode(name);
	if (auto h = dynamic_cast<Hood*>(allCitiesLocation->getData()))
	{
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
				currentPerson->setTotalMiles(currentPerson->getTotalMiles() - currentLog->getMiles());

				//Remove the person's entry from the city's walking log
				Node* entryToRemove = currentPerson->getList().findNode(h->getName());
				currentPerson->getList().removeNode(entryToRemove);
			}
			currentLog = currentLog->getNext();
		}
		allCities.removeNode(allCitiesLocation);
		delete h;
	}
}

void ChallengeManager::getPersonStats(const string& name) const
{
	Person* p = findPerson(name);
	cout << "\n====" << p->getName() << "'s statistics====\nTotal miles walked: " << p->getTotalMiles() <<
		"\nTotal neighborhoods visited: " << p->getList().getNodeCount() << endl;
	p->printMinMaxWalks();
	cout << "=====================\n" << endl;
}

Person* ChallengeManager::findPerson(const string& name) const
{
	Person* p = dynamic_cast<Person*>(allParticipants.findNode(name)->getData());
	if (!p) cout << "Error: participant \"" << name << "\" was not found in manager!" << endl;
	return p;
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

void ChallengeManager::recordWalk(Hood* h, Person* p, double milesWalked) const
{
	if (milesWalked < 0)
	{
		cout << "==>You must record a walk longer than zero miles" << endl;
		return;
	}

	//Update person's neighborhoods walking log
	Node* currentCity = p->getList().findNode(h->getName());

	//Find the city in their walking history, or create a new log if they've never walked there
	if (currentCity) currentCity->setMiles(currentCity->getMiles() + milesWalked);
	else p->getList().addNode(h, milesWalked);

	//Add the person's activity to the corresponding city's walking history
	Node* currentPerson = h->getList().findNode(p->getName());

	//Find the participant in the city's walking activity, or create a new log if they've never walked there
	if (currentPerson) currentPerson->setMiles(currentPerson->getMiles() + milesWalked);
	else h->getList().addNode(p, milesWalked);

	//Update both the city's and person's mile totals
	p->setTotalMiles(p->getTotalMiles() + milesWalked);
	h->setTotalMiles(h->getTotalMiles() + milesWalked);
	if (milesWalked == 1) cout << "Recorded " << p->getName() << "'s walk of " << milesWalked << " mile in " + h->
		getName() << endl;
	else cout << "Recorded " << p->getName() << "'s walk of " << milesWalked << " miles in " + h->getName() << endl;
}
