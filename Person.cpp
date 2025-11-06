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

#include "Person.h"
#include "ChallengeManager.h"
#include <vector>
#include <iostream>

using namespace std;
int Person::lastId = 150;
vector<string> Person::allCities = { "Old Towne", "El Modena", "Orange Hills", "Santiago Creek", "Villa Park Area", "North El Camino Real" };

Person::Person()
{
	name = "No name";
	totalMiles = 0;
	userId = -1;
}

Person::Person(const string& personName)
{
	name = personName;
	totalMiles = 0;
	userId = lastId;
	lastId++;
}

Person::Person(const string& personName, int identity)
{
	name = personName;
	totalMiles = 0;
	userId = identity;
}

string Person::getName() const
{
	return name;
}

double Person::getTotalMiles() const
{
	return totalMiles;
}

int Person::getUserId() const
{
	return userId;
}

vector<double>& Person::getList() 
{
	return personList;
}


void Person::setName(const string& newName)
{
	name = newName;
}

void Person::setTotalMiles(double miles)
{
	//Prevent setting negative miles
	if (miles > 0) totalMiles = miles;
	else totalMiles = 0;
}

void Person::setUserId(int identity)
{
	userId = identity;
}



void Person::printPersonList() const
{
	if (personList.empty())
	{
		cout << name << " has not logged any walks! " << endl;
		return;
	}
	cout << "\n===" << name << "'s Walking Data===" << endl;
	cout << "" << totalMiles << " Total Miles Logged:" << endl;
	for (unsigned int i  = 0; i < personList.size(); i++)
	{
		cout << "\n\t" << i+1 << ".) Location: " << allCities[i] << ", Miles Logged: " << personList[i] << endl;
	}
}

void Person::printMinMaxWalks() const
{
	unsigned int largestIndex = 0;
	unsigned int smallestIndex = 0;
	for (unsigned int i = 0; i < personList.size(); i++)
	{
		if (personList[i] > personList[largestIndex])  largestIndex = i;
		else if (personList[i] < personList[smallestIndex]) smallestIndex = i;
	}
	
	cout << name << "has walked the most miles in " << allCities[largestIndex] << " with a total of " << personList[largestIndex] << " miles recorded" << endl;
	cout << "In addition, " << name << " has walked the least miles in " << allCities[smallestIndex] <<
		" with a total of " << personList[smallestIndex] << " miles recorded" << endl;
}

void Person::printStats() const
{
	cout << "\n====" << name << "'s statistics====\nUserID:" << userId << "\nTotal miles walked: " << totalMiles <<
		"\nTotal neighborhoods visited: " << personList.size() << endl;
	printMinMaxWalks();
	cout << "=====================\n" << endl;
}

void Person::recordWalk(unsigned int cityIndex, double milesWalked)
{
	if (milesWalked < 0)
	{
		cout << "==>You must record a walk longer than zero miles" << endl;
		return;
	}
	//Check if they've walked there before, or resize the list
	if (personList.size() <= cityIndex) {
		personList.resize(cityIndex + 1);
	}
	personList[cityIndex] = milesWalked;
	totalMiles += milesWalked;
	
	if (milesWalked == 1) cout << "Recorded " << name << "'s walk of " << milesWalked << " mile in " + allCities[cityIndex] << endl;
	else cout << "Recorded " << name << "'s walk of " << milesWalked << " miles in " + allCities[cityIndex] << endl;
}

ostream& operator<<(ostream& out, const Person& p)
{
	out << "Username: " << p.getName() << ", Total miles walked: " << p.getTotalMiles() << endl;
	return out;
}
