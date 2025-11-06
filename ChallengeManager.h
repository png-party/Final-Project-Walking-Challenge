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
#ifndef CHALLENGEMANAGER_H
#define CHALLENGEMANAGER_H

#include "LinkedList.h"
#include "Person.h"
#include "Hood.h"
#include <string>
#include <fstream>
using namespace std;

class ChallengeManager
{
	LinkedList allParticipants;
	//LinkedList allCities;

public:
	ChallengeManager();
	~ChallengeManager();

	/*Although we could technically make new copies of all of the data within
	 * a challenge manager, the copy constructor and move assignment are still
	 * deleted because it's not very efficient or compatible with the current
	 * current design, and moving over the data would be better anyways. */
	ChallengeManager(const ChallengeManager& other) = delete;
	ChallengeManager& operator=(const ChallengeManager& other) = delete;

	/*Move instead of copying*/
	ChallengeManager(ChallengeManager&& other) noexcept = default;
	ChallengeManager& operator=(ChallengeManager&& other) noexcept = default;

	void loadData(ifstream& file);
	void createPerson(const string& name);
	void createCity(const string& name);
	void removePerson(const string& name);
	bool removeCity(const string& cityName);

	void getPersonStats(const string& name) const;
	//Person* findPerson(const string& name) const;
	Person* getMostActive() const;
	Hood* findCity(const string& name) const;
};

#endif
