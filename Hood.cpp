#include "Hood.h"
#include <iostream>
using namespace std;

Hood::Hood()
{
	cout << "Creating a default neighborhood object" << endl;
}
//--------------------------------------------------------------
Hood::Hood(string cityName) : WalkData(cityName)
{
	cout << "Creating neighborhood object" << endl;
}
//--------------------------------------------------------------
LinkedList& Hood::getList()
{
	return hoodList;
}
//--------------------------------------------------------------
//logs walked miles
void Hood::logWalk(const string& personName, int miles)
{
	Node* current = hoodList.getFirst();
	while (current)
	{
		if (current->x->getName() == personName)
		{
			current->x->setTotalMiles(current->x->getTotalMiles() + miles);
			totalMiles += miles;
			return;
		}
		current = current->getNext();
	}

	//add person
	WalkData* newPerson = new WalkData(personName, miles);
	hoodList.addNode(newPerson);
	totalMiles += miles;
}
//--------------------------------------------------------------
//finds person with the highest miles
WalkData* Hood::getTopWalker() const
{
	Node* current = hoodList.getFirst();
	if (!current)
		return nullptr;

	Node* topWalker = current;
	current = current->getNext();

	while (current)
	{
		if (current->x->getTotalMiles() > topWalker->x->getTotalMiles())
		{
			topWalker = current;
		}
		current = current->getNext();
	}

	return topWalker->x;
}
//--------------------------------------------------------------
void Hood::printHoodList() const
{
	cout << "\n===The City of " << name << "'s Walking Data===" << endl;
	cout << "" << totalMiles << " Total Miles Logged:" << endl;
	Node* current = hoodList.getFirst();
	int i = 1;
	while (current)
	{
		cout << "\n\t" << i <<".) Person: " << current->x->getName()
		<< ", Miles Logged: " <<  current->x->getTotalMiles()<< endl;
		current = current->next;
		i++;
	}
}
//--------------------------------------------------------------
void Hood::writeToStream(ostream& out) const
{
	out << "Location: " << getName() << " Total Miles Logged: " << getTotalMiles() << endl;
}
//--------------------------------------------------------------
ostream& operator<<(ostream& out, const Hood& city)
{
	city.writeToStream(out);
	return out;
}
