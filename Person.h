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
#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

using namespace std;
class ChallengeManager;

class Person
{
	friend class ChallengeManager;
	static int lastId;
	
	string name;
	double totalMiles;
	int userId;
	vector<double> personList;

protected:
	static vector<string> allCities;

public:
	Person(const string& personName);
	Person(const string& personName, int identity);
	string getName() const;
	double getTotalMiles() const;
	int getUserId() const;
	vector<double>& getList();

	void setName(const string& newName);
	void setTotalMiles(double miles);
	void setUserId(int identity);

	void printPersonList() const;
	void printMinMaxWalks() const;
	void printStats() const;
	void recordWalk(unsigned int cityIndex, double milesWalked);
	friend ostream& operator<<(ostream& out, const Person& person);
};

#endif
