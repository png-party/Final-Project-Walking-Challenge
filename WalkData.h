#pragma once
#ifndef WALKDATA_H
#define WALKDATA_H
#include <string>
using namespace std;
class WalkData
{
	string name;
	int totalMiles;
public:
	WalkData();
	WalkData(string itemName);
	WalkData(string itemName, int itemMiles);
	string getName() const;
	int getTotalMiles() const;
	void setName(string newName);
	void setTotalMiles(int miles);
};
#endif