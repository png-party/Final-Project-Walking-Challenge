#include "Person.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

Person::Person()
{
	cout << "Creating person object..." << endl;
}
//-----------------------------------------------------------
Person::Person(string personName) : WalkData(personName)
{
	cout << "Creating person object..." << endl;
}
//-----------------------------------------------------------
void Person::walk(WalkData* city, int miles)
{
    totalMiles += miles;
    string cityName = city->getName();

    // check if the city already exists in person's list
    Node* current = personList.getFirst();
    while (current)
    {
        if (current->x->getName() == cityName)
        {
            current->x->setTotalMiles(current->x->getTotalMiles() + miles);
            break;
        }
        current = current->getNext();
    }

    // add new city if not found
    if (!current)
    {
        WalkData* newCity = new WalkData(cityName, miles);
        personList.addNode(newCity);
    }

    // update Hood data using logWalk()
    if (Hood* c = dynamic_cast<Hood*>(city))
    {
        c->logWalk(name, miles);
    }
}
//-----------------------------------------------------------
void Person::printPersonList() const
{
	cout << "\n===" << name << "'s Walking Data===" << endl;
	Node* current = personList.getFirst();
	int i = 1;
	while (current)
	{
		cout << "\n\t" << i <<".) Location: " << current->x->getName() << ", Miles Logged: " << current->x->getTotalMiles() << endl;
		current = current->next;
		i++;
	}
}
//-----------------------------------------------------------
void Person::writeToStream(ostream& out) const
{
	out << "Username: " << getName() << ", Total miles walked: " << getTotalMiles() << endl;
}
//-----------------------------------------------------------
/*Prints person's name and total stats*/
ostream& operator<<(ostream& out, const Person* human)
{
	human->writeToStream(out);
	return out;
	//return human.writeToStream(out);
}
