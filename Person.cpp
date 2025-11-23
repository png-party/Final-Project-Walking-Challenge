/*
Christiandior Falucho, Nicole Sirbu, Mohamed Ziq, Nicholas Donaldson
CMPR 131 - Fall 2025
November 22nd, 2025
Final Project #2
Collaboration:
	https://en.cppreference.com/w/cpp/container/unordered_map.html
	https://en.cppreference.com/w/cpp/utility/pair.html
	https://www.geeksforgeeks.org/cpp/different-ways-to-initialize-an-unordered_map-in-cpp/
	https://www.geeksforgeeks.org/cpp/traversing-a-map-or-unordered_map-in-cpp-stl/
*/
#include "Person.h"
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
	string title = "====" + name + "'s Walking Data====";
	cout << title << endl;
	string endBar(title.length(), '=');
	cout << "" << totalMiles << " Total Miles Logged:" << endl;
	int countCity = 1; //Use this to display numbers correctly, because i might count cities with zero miles
	for (int i  = 0; i < (int) personList.size(); i++)
	{
		if (personList[i] > 0)
		{
			cout << "\n\t" << countCity << ".) Location: " << allCities[i] << ", Miles Logged: " << personList[i] << endl;
			countCity++;
		}
	}
	cout << endBar << endl;
}

void Person::printStats(const vector<string>& allCities) const
{
	string title = "==================" + name + "'s Statistics==================";
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
			/* Avoid overwriting the smallest index with any zeroes
			 * Update it to the current index if smallest is zero by default
			 * the current one is actually smaller */
			if (personList[i] != 0 && (personList[smallestIndex] == 0 || personList[i] < personList[smallestIndex])) smallestIndex = i;
		}

		//Don't print result if the shortest/longest walks were zero miles
		if (personList[largestIndex] > 0)
		{
			cout << name << " has walked the most miles in " << allCities[largestIndex] << " with a total of " << personList[largestIndex] << " miles recorded." << endl;
		}
		if (personList[smallestIndex] > 0 && personList[smallestIndex] != personList[largestIndex])
		{
			cout << "In addition, " << name << " has walked the least miles in " << allCities[smallestIndex] <<
				" with a total of " << personList[smallestIndex] << " miles recorded." << endl;
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
	personList[cityIndex] += milesWalked;
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
