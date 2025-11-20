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
#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

using namespace std;
class ChallengeManager;

class Person
{
public:
	Person();
	Person(const string& personName);
	Person(const string& personName, int identity);
	string getName() const;
	double getTotalMiles() const;
	int getUserId() const;
	vector<double>& getList();

	void setName(const string& newName);
	void setTotalMiles(double miles);
	void setUserId(int identity);

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
