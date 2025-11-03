/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#include "Hood.h"
#include <iostream>

using namespace std;

Hood::Hood(const string& cityName) : WalkData(cityName)
{
	hoodList = LinkedList();
	cout << "Creating neighborhood object" << endl;
}

Hood::~Hood()
{
	cout << "Calling derived class destructor" << endl;
}

LinkedList& Hood::getList()
{
	return hoodList;
}

void Hood::logWalk(const string& personName, int miles)
{
	Node* current = hoodList.getFirst();
	//Check if we're adding the first node
	if (!current)
	{
		while (current)
		{
			if (current->getData()->getName() == personName)
			{
				current->getData()->setTotalMiles(current->getData()->getTotalMiles() + miles);
				totalMiles += miles;
				return;
			}
			current = current->getNext();
		}
	}
	else
	{
		while (current)
		{
			if (current->getData()->getName() == personName)
			{
				current->getData()->setTotalMiles(current->getData()->getTotalMiles() + miles);
				totalMiles += miles;
				return;
			}
			current = current->getNext();
		}


		WalkData* newPerson = new WalkData(personName, miles);
		hoodList.addNode(newPerson);
		totalMiles += miles;
	}
}

WalkData* Hood::getTopWalker() const
{
	Node* current = hoodList.getFirst();
	if (!current)
		return nullptr;

	Node* topWalker = current;
	current = current->getNext();

	while (current)
	{
		if (current->getData()->getTotalMiles() > topWalker->getData()->getTotalMiles())
		{
			topWalker = current;
		}
		current = current->getNext();
	}

	return topWalker->getData();
}


void Hood::printHoodList() const
{
	cout << "\n===The City of " << name << "'s Walking getData()===" << endl;
	cout << "" << totalMiles << " Total Miles Logged:" << endl;
	Node* current = hoodList.getFirst();
	int count = 1;
	while (current)
	{
		cout << "\n\t" << count << ".) Person: " << current->getData()->getName()
			<< ", Miles Logged: " << current->getData()->getTotalMiles() << endl;
		current = current->getNext();
		count++;
	}
}

void Hood::writeToStream(ostream& out) const
{
	out << "Location: " << getName() << " Total Miles Logged: " << getTotalMiles() << endl;
}

ostream& operator<<(ostream& out, const Hood& city)
{
	city.writeToStream(out);
	return out;
}