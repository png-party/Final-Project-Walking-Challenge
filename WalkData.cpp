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
