/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1 
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
    https://www.geeksforgeeks.org/cpp/how-to-read-from-a-file-in-cpp/
    https://www.hlsl.co.uk/blog/2017/12/1/c-noexcept-and-move-constructors-effect-on-performance-in-stl-containers
    https://cppscripts.com/cpp-delete-copy-constructor
*/
#ifndef WALKDATA_H
#define WALKDATA_H
#include <string>
using namespace std;

class WalkData
{
protected:
	string name;
	double totalMiles;

public:
	WalkData();
	WalkData(const string& itemName);
	WalkData(const string& itemName, double itemMiles);
	virtual ~WalkData();
	string getName() const;
	double getTotalMiles() const;
	void setName(const string& newName);
	void setTotalMiles(double miles);

	virtual void writeToStream(ostream& out) const;
	friend ostream& operator<<(ostream& out, WalkData* log);
};
#endif
