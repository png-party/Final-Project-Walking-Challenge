#include "Person.h"

#include <iostream>
using namespace std;

Person::Person()
{
	cout << "Creating person object" << endl;
}

Person::Person(string personName) : WalkData(personName)
{
	cout << "Creating person object" << endl;
}



ostream& operator<<(ostream& out, const Person& human)
{
	return out;
}
