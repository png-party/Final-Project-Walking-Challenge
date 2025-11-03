/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1 
Collaboration:
    https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#pragma once
#ifndef CHALLENGEMANAGER_H
#define CHALLENGEMANAGER_H

#include "LinkedList.h"
#include "Person.h"
#include "Hood.h"
#include "WalkData.h"
#include <string>
#include <fstrea,>
#include <vector>

using namespace std;

class ChallengeManager
{
    LinkedList allParticipants;
    LinkedList  allCities;

public:
    ChallengeManager();

    ~ChallengeManager();
    void loadData(const ifstream& file);
    void createPerson(const string& name);
    void createCity(const string& name);
    void removePerson(const string& name);
    void removeCity(const string& name);

    void lookUpPerson(const string& name) const;
    Person* findPerson(const string& name) const;
    Hood* findCity(const string& name) const;
    void recordWalk(const string& cityName, const string& personName, int milesWalked) const;
};

#endif