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
#ifndef CHALLENGEMANAGER_H
#define CHALLENGEMANAGER_H

#include "Person.h"
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>
using namespace std;
class ChallengeManager
{

public:
	ChallengeManager();
	void loadData(ifstream& file);
	void addPerson(const string& name);
	void addCity(const string& name);
	void deletePerson(const string& name);
	void deleteCity(const string& name);
	void getPersonStats(const string& name) const;
	void printAllPersons() const;

	//To Do:
	void printMostActive() const;
	void clearParticipants();
	//delete all cities

	bool logWalk(const string& personName, const string& cityName, double miles);
	void printPersonWalks(const string& personName) const;

private:
	unordered_map<string, Person> personMap;
	vector<string> allCities = { "Old Towne", "El Modena", "Orange Hills", "Santiago Creek", "Villa Park Area", "North El Camino Real"};
	int lastId;
	int getCityIndex(const string& name) const;
};

#endif
