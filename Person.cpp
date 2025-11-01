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

Person::Person()
{
    personList = LinkedList();

}

Person::Person(string personName) : WalkData(personName)
{
    personList = LinkedList();
    cout << "Creating person object..." << endl;
}

Person::~Person()
{
    cout << "Calling derived class destructor" << endl;
}

void Person::walk(WalkData* city, int miles)
{
    //Update corresponding city's walking data data
    if (Hood* cityAsHood = dynamic_cast<Hood*>(city))
    {
        cityAsHood->logWalk(name, miles);
    }
    else cout << "You must log data to a city!" << endl;

    //Update the person's walking data
    totalMiles += miles;
    string cityName = city->getName();
    Node* current = personList.getFirst();

    //Check if the person's list is empty
    if (!current)
    {
        WalkData* newCity = new WalkData(cityName, miles);
        personList.addNode(newCity);
    }
    else
    {
        while (current)
        {
            if (current->data->getName() == cityName)
            {
                current->data->setTotalMiles(current->data->getTotalMiles() + miles);
                break;
            }
            current = current->next;
        }
    }
}

void Person::printPersonList() const
{
    cout << "\n===" << name << "'s Walking Data===" << endl;
    cout << "" << totalMiles << " Total Miles Logged:" << endl;
    Node* current = personList.getFirst();
    int count = 1;
    while (current)
    {
        cout << "\n\t" << count << ".) Location: " << current->data->getName() << ", Miles Logged: " << current->data->getTotalMiles() << endl;
        current = current->next;
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