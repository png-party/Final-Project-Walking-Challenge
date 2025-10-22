#include "Hood.h"
#include <iostream>
using namespace std;

Hood::Hood()
{
	name = "No name";
	totalMiles = 0;
}

Hood::Hood(string cityName)
{
	name = cityName;
	totalMiles = 0;
}

string Hood::getName() const
{
	return name;
}

int Hood::getTotalMiles() const
{
	return totalMiles;
}

void Hood::setName(string newName)
{
	name = newName;
}

void Hood::setTotalMiles(int miles)
{
	totalMiles = miles;
}

ostream& operator<<(ostream& out, const Hood& human)
{
	
}
