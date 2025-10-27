#include "Person.h"
#include "LinkedList.h"
#include <iostream>

using namespace std;

Person::Person()
{
    cout << "Creating person object..." << endl;
}

Person::Person(string personName) : WalkData(personName)
{
    cout << "Creating person object..." << endl;
}

Person::Person(const Person& other)
{
    name = other.name;
    totalMiles = other.totalMiles;
    personList = LinkedList(other.personList);
}

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        name = other.name;
        totalMiles = other.totalMiles;
        personList = LinkedList(other.personList);
    }
    else cout << "Attempting self-assignment!" << endl;
    return *this;
}

Person::~Person() {
    cout << "Calling derived class destructor " << endl;
}
void Person::walk(WalkData* city, int miles)
{
    totalMiles += miles;
    string cityName = city->getName();

    Node* current = personList.getFirst();
    while (current)
    {
        if (current->data->getName() == cityName)
        {
            current->data->setTotalMiles(current->data->getTotalMiles() + miles);
            break;
        }
        current = current->next;
    }

    if (!current)
    {
        WalkData* newCity = new WalkData(cityName, miles);
        personList.addNode(newCity);
    }

    if (Hood* cityAsHood = dynamic_cast<Hood*>(city))
    {
        cityAsHood->logWalk(name, miles);
    }
}

void Person::printPersonList() const
{
    cout << "\n===" << name << "'s Walking Data===" << endl;
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