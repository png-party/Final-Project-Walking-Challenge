//https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
#pragma once
#ifndef WALKDATA_H
#define WALKDATA_H
#include <string>
using namespace std;
class WalkData
{
protected:
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
	virtual void writeToStream(ostream& out) const;
	friend ostream& operator<<(ostream& out, WalkData* log);

};
#endif