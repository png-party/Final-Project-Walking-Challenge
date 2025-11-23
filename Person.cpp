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

#include "Person.h"
#include "ChallengeManager.h"
#include <vector>
#include <iostream>

using namespace std;

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
	userId = -1;
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


void Person::printPersonList(const vector<string>& allCities) const
{
	if (personList.empty())
	{
		cout << name << " has not logged any walks! " << endl;
		return;
	}
	cout << "\n===" << name << "'s Walking Data===" << endl;
	cout << "" << totalMiles << " Total Miles Logged:" << endl;
	int countCity = 1; //Use this to display numbers correctly, even if we don't use all values at i
	for (int i  = 0; i < (int) personList.size(); i++)
	{
		if (personList[i] > 0)
		{
			cout << "\n\t" << countCity << ".) Location: " << allCities[i] << ", Miles Logged: " << personList[i] << endl;
			countCity++;
		}
	}
}

void Person::printStats(const vector<string>& allCities) const
{
	string title = "====" + name + "'s statistics====";
	string endBar(title.length(), '=');
	cout << title << endl;
	cout << "ID:" << userId << "\nTotal miles walked: " << totalMiles << endl;
	if (!personList.empty()) //Skip if they have zero walks
	{
		int largestIndex = 0;
		int smallestIndex = 0;
		for (int i = 0; i < (int)personList.size(); i++)
		{
			if (personList[i] > personList[largestIndex])  largestIndex = i;
			//Avoid overwriting the smallest index with any zeroes
			else if (personList[i] < personList[smallestIndex] && personList[i] != 0) smallestIndex = i;
		}

		//Don't print result if the shortest/longest walks were zero miles
		if (personList[smallestIndex] > 0 && personList[largestIndex] > 0)
		{
			cout << name << " has walked the most miles in " << allCities[largestIndex] << " with a total of " << personList[largestIndex] << " miles recorded\nIn addition, " << name << " has walked the least miles in " << allCities[smallestIndex] <<
				" with a total of " << personList[smallestIndex] << " miles recorded" << endl;
		}
	}
	
	cout << endBar << "\n" << endl;
}

void Person::recordWalk(int cityIndex, double milesWalked, const vector<string>& allCities)
{
	if (milesWalked < 0)
	{
		cout << "==>You must record a walk longer than zero miles" << endl;
		return;
	}
	//Check if they've walked there before, or resize the list
	if ((int) personList.size() <= cityIndex) {
		personList.resize(cityIndex + 1);
	}
	personList[cityIndex] = milesWalked;
	totalMiles += milesWalked;
	
	if (milesWalked == 1) cout << "\n==>Recorded " << name << "'s walk of " << milesWalked << " mile in " + allCities[cityIndex] << endl;
	else cout << "\n==>Recorded " << name << "'s walk of " << milesWalked << " miles in " + allCities[cityIndex] << endl;
}


bool Person::operator==(const Person& other) const
{
	return name == other.name;
}

ostream& operator<<(ostream& out, const Person& p)
{
	out << "|ID: " << p.getUserId() << "| Username: " << p.getName() << ", Total miles: " << p.getTotalMiles() << endl;
	return out;
}
