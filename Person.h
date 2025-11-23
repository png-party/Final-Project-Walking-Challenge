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
#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

class Person;
using namespace std;

class ChallengeManager;

class Person
{
public:
	Person();
	Person(const string& personName);
	Person(const string& personName, int identity);
	Person(const Person&) = default;
	string getName() const;
	double getTotalMiles() const;
	int getUserId() const;
	vector<double>& getList();

	void setName(const string& newName);
	void setTotalMiles(double miles);
	void setUserId(int identity);
	bool operator==(const Person& other) const;

	friend ostream& operator<<(ostream& out, const Person& p);


protected:
	friend ChallengeManager;
	void printPersonList(const vector<string>& allCities) const;
	void recordWalk(int cityIndex, double milesWalked, const vector<string>& allCities);
	void printStats(const vector<string>& allCities) const;
private:
	string name;
	double totalMiles;
	int userId;
	vector<double> personList;
};

#endif
