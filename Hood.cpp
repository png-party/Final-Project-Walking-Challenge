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

Hood::Hood()
{
	cout << "Creating a default neighborhood object" << endl;
}

Hood::Hood(const string& cityName) : WalkData(cityName)
{
	cout << "Creating neighborhood object" << endl;
}

Hood::Hood(const Hood& other)
{
	name = other.name;
	totalMiles = other.totalMiles;
	hoodList = LinkedList(other.hoodList);
}

Hood& Hood::operator=(const Hood& other)
{
	if (this != &other)
	{
		name = other.name;
		totalMiles = other.totalMiles;
		hoodList = LinkedList(other.hoodList);
	}
	else cout << "Attempting self-assignment!" << endl;
	return *this;
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
	while (current)
	{
		if (current->data->getName() == personName)
		{
			current->data->setTotalMiles(current->data->getTotalMiles() + miles);
			totalMiles += miles;
			return;
		}
		current = current->next;
	}

	WalkData* newPerson = new WalkData(personName, miles);
	hoodList.addNode(newPerson);
	totalMiles += miles;
}

WalkData* Hood::getTopWalker() const
{
	Node* current = hoodList.getFirst();
	if (!current)
		return nullptr;

	Node* topWalker = current;
	current = current->next;

	while (current)
	{
		if (current->data->getTotalMiles() > topWalker->data->getTotalMiles())
		{
			topWalker = current;
		}
		current = current->next;
	}

	return topWalker->data;
}

void Hood::printHoodList() const
{
	cout << "\n===The City of " << name << "'s Walking Data===" << endl;
	cout << "" << totalMiles << " Total Miles Logged:" << endl;
	Node* current = hoodList.getFirst();
	int count = 1;
	while (current)
	{
		cout << "\n\t" << count << ".) Person: " << current->data->getName()
			<< ", Miles Logged: " << current->data->getTotalMiles() << endl;
		current = current->next;
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