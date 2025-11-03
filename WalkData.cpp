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
#include "WalkData.h"
#include <iostream>

using namespace std;

WalkData::WalkData()
{
	name = "No name";
	totalMiles = 0;
}

WalkData::WalkData(const string& itemName)
{
	name = itemName;
	totalMiles = 0;
}

WalkData::WalkData(const string& itemName, double itemMiles)
{
	name = itemName;
	totalMiles = itemMiles;
}

WalkData::~WalkData()
{
	//cout << "Calling base class destructor" << endl;
}

string WalkData::getName() const
{
	return name;
}

double WalkData::getTotalMiles() const
{
	return totalMiles;
}

void WalkData::setName(const string& newName)
{
	name = newName;
}

void WalkData::setTotalMiles(double miles)
{
	//Prevent setting negative miles
	if (miles > 0) totalMiles = miles;
	else totalMiles = 0;
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
