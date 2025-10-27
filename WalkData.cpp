/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#include "WalkData.h"
#include <iostream>

using namespace std;

WalkData::WalkData()
{
	name = "No name";
	totalMiles = 0;
	cout << "Creating walking activity log..." << endl;
}

WalkData::WalkData(string itemName)
{
	name = itemName;
	totalMiles = 0;
	cout << "Creating walking activity log..." << endl;
}

WalkData::WalkData(string itemName, int itemMiles)
{
	name = itemName;
	totalMiles = itemMiles;
	cout << "Creating walking activity log..." << endl;
}
WalkData::~WalkData()
{
	cout << "Calling base class destructor" << endl;
}

string WalkData::getName() const
{
	return name;
}

int WalkData::getTotalMiles() const
{
	return totalMiles;
}

void WalkData::setName(string newName)
{
	name = newName;
}

void WalkData::setTotalMiles(int miles)
{
	totalMiles = miles;
}

void WalkData::writeToStream(ostream& out) const
{
	out << "Name: " << getName() << ", Miles: " << getTotalMiles() << endl;
}

ostream& operator<<(ostream& out, WalkData* walkDataLog)
{
	walkDataLog->writeToStream(out);
	return out;
}