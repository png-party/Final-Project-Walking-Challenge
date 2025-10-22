#include "WalkData.h"

WalkData::WalkData()
{
	name = "No name";
	totalMiles = 0;
}

WalkData::WalkData(string itemName)
{
	name = itemName;
	totalMiles = 0;
}

WalkData::WalkData(string itemName, int itemMiles)
{
	name = itemName;
	totalMiles = itemMiles;
}

string WalkData::getName() const
{
	return name;
}

int WalkData::getTotalMiles() const
{
	return totalMiles;
}

void WalkData::setName(string newName)
{
	name = newName;
}

void WalkData::setTotalMiles(int miles)
{
	totalMiles = miles;
}
