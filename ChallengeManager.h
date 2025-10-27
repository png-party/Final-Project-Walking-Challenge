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