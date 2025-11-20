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
#ifndef CHALLENGEMANAGER_H
#define CHALLENGEMANAGER_H

#include "LinkedList.h"
#include "Person.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class ChallengeManager
{

public:

	ChallengeManager();

	void loadData(ifstream& file);
	void createPerson(const string& name);
	void createCity(const string& name);
	void removePerson(const string& name);
	bool removeCity(const string& cityName);
	void clearParticipants();

	bool logWalk(const string& personName, const string& cityName, double miles) const;
	void printPersonWalks(const string& personName) const;
	void getPersonStats(const string& name) const;
	void printMostActive() const;
	void printAllParticipants() const;

private:
	LinkedList allParticipants;
	vector<string> allCities = { "Old Towne", "El Modena", "Orange Hills", "Santiago Creek", "Villa Park Area", "North El Camino Real" };
	int lastId;

	Person* getPerson(const string& name) const;
	int getCityIndex(const string& name) const; 
};

#endif
