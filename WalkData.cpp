#include "WalkData.h"
#include <iostream>

WalkData::WalkData()
{
	name = "No name";
	totalMiles = 0;
	cout << "Creating walking activity log..." << endl;
}
//----------------------------------------------------------
WalkData::WalkData(string itemName)
{
	name = itemName;
	totalMiles = 0;
	cout << "Creating walking activity log..." << endl;
}
//----------------------------------------------------------
WalkData::WalkData(string itemName, int itemMiles)
{
	name = itemName;
	totalMiles = itemMiles;
	cout << "Creating walking activity log..." << endl;
}
 WalkData::~WalkData()
{
	 cout << "Calling base class destructor" << endl;
}
//----------------------------------------------------------
string WalkData::getName() const
{
	return name;
}
//----------------------------------------------------------
int WalkData::getTotalMiles() const
{
	return totalMiles;
}
//----------------------------------------------------------
void WalkData::setName(string newName)
{
	name = newName;
}
//----------------------------------------------------------
void WalkData::setTotalMiles(int miles)
{
	totalMiles = miles;
}
//----------------------------------------------------------
	/*Virtual function to override in Person and Hood class.
	 * Since you can't override a friend function, to "override"
	 * the stream insertion operator, we had to make a helper function
	 * that gets called in the overloaded operator function that
	 * can be overridden*/
void WalkData::writeToStream(ostream& out) const
{
	out << "Name: " << getName() << ", Miles: " << getTotalMiles() << endl;
}
//----------------------------------------------------------
ostream& operator<<(ostream& out, WalkData* log)
{
	log->writeToStream(out);
	return out;
}
