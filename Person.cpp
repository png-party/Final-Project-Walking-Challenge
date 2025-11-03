/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
    https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/

#include "Person.h"
#include "LinkedList.h"
#include "Hood.h"
#include <iostream>

using namespace std;

Person::Person(string personName) : WalkData(personName)
{
    personList = LinkedList();
    userId = lastID;
    lastID++;
}

Person::Person(string personName, int identity) :WalkData(personName)
{
    personList = LinkedList();
    userId = identity;
}

Person::~Person()
{
    cout << "Calling derived class destructor" << endl;
}

void Person::printMinMaxWalks() const
{
    Node* maxCity = personList.getFirst();
    Node* minCity = personList.getFirst();

    Node* current = personList.getFirst();
    if (!current)
    {
        cout << "No walks recorded!" << endl;
        return;
    }
    while (current)
    {
        if (current->getMiles() > maxCity->getMiles())
        {
            maxCity = current;
        }
        else if (current->getMiles() < minCity->getMiles())
        {
            minCity = current;
        }
        current = current->getNext();
    }
    cout << name << "has walked the most miles in " << maxCity->getData()->getName() << " with a total of " << maxCity->getMiles() << " miles recorded"<< endl;
    cout << "In addition, " << name << " has walked the least miles in " << minCity->getData()->getName() << " with a total of " << minCity->getMiles() << " miles recorded" << endl;
}

int Person::getUserId() const
{
    return userId;
}

LinkedList& Person::getList()
{
    return personList;
}

void Person::setUserId(int identity)
{
    userId = identity;
}


void Person::printPersonList() const
{
    cout << "\n===" << name << "'s Walking Data===" << endl;
    cout << "" << totalMiles << " Total Miles Logged:" << endl;
    Node* current = personList.getFirst();
    int count = 1;
    while (current)
    {
        cout << "\n\t" << count << ".) Location: " << current->getData()->getName() << ", Miles Logged: " << current->getData()->getTotalMiles() << endl;
        current = current->getNext();
        count++;
    }
}

void Person::writeToStream(ostream& out) const
{
    out << "Username: " << getName() << ", Total miles walked: " << getTotalMiles() << endl;
}

ostream& operator<<(ostream& out, const Person* person)
{
    person->writeToStream(out);
    return out;
}