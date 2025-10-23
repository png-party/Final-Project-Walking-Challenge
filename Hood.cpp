#include "Hood.h"
#include <iostream>
using namespace std;

Hood::Hood()
{
	cout << "Creating a default neighborhood object" << endl;
}

Hood::Hood(string cityName) : WalkData(cityName)
{
	cout << "Creating neighborhood object" << endl;
}

LinkedList& Hood::getList()
{
	return hoodList;
}

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

void Hood::writeToStream(ostream& out) const
{
	out << "Location: " << getName() << " Total Miles Logged: " << getTotalMiles() << endl;
}

ostream& operator<<(ostream& out, const Hood& city)
{
	city.writeToStream(out);
	return out;
}
