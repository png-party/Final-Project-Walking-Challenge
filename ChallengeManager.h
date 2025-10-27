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

using namespace std;

class ChallengeManager
{
private:
    LinkedList peopleList;
    LinkedList cityList;

public:
    
    ChallengeManager();

    
    ~ChallengeManager();

    
    void addPerson(Person* person);
    void addCity(Hood* city);

    
    WalkData* findItem(const string& name, LinkedList& listToSearch) const;

    
    Person* findPerson(const string& name) const;
    Hood* findCity(const string& name) const;
};

#endif