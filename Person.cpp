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

void Person::walk(WalkData* city, int miles)
{
	totalMiles += miles;
	WalkData* log = new WalkData(name, miles);
	if (Hood* c = dynamic_cast<Hood*>(city))
	{
		personList.addNode(new WalkData(c->getName(), miles));
		c->getList().addNode(log);
		c->setTotalMiles(c->getTotalMiles() + miles);
	}
}

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


void Person::writeToStream(ostream& out) const
{
	out << "Username: " << getName() << ", Total miles walked: " << getTotalMiles() << endl;
}


/*Prints person's name and total stats*/
ostream& operator<<(ostream& out, const Person* human)
{
	human->writeToStream(out);
	return out;
	//return human.writeToStream(out);
}
