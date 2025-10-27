/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
    https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#include "ChallengeManager.h"
#include <iostream>

using namespace std;

ChallengeManager::ChallengeManager()
{
    
    cout << "Challenge Manager created." << endl;
}

ChallengeManager::~ChallengeManager()
{
    
    cout << "Challenge Manager destroyed." << endl;
}

void ChallengeManager::addPerson(Person* person)
{
    peopleList.addNode(person);
}

void ChallengeManager::addCity(Hood* city)
{
    cityList.addNode(city);
}


WalkData* ChallengeManager::findItem(const string& name, LinkedList& listToSearch) const
{
    Node* current = listToSearch.getFirst();
    while (current)
    {
        if (current->data && current->data->getName() == name) 
        {
            return current->data; 
        }
        current = current->next;
    }

    
    return nullptr;
}


Person* ChallengeManager::findPerson(const string& name) const
{
    Node* current = peopleList.getFirst();
    while (current)
    {
        if (current->data && current->data->getName() == name) 
        {
            
            return dynamic_cast<Person*>(current->data); 
        }
        current = current->next;
    }
    return nullptr;
}


Hood* ChallengeManager::findCity(const string& name) const
{
    Node* current = cityList.getFirst();
    while (current)
    {
        if (current->data && current->data->getName() == name) 
        {
            return dynamic_cast<Hood*>(current->data); 
        }
        current = current->next;
    }
    return nullptr;
}