#pragma once
#ifndef HOOD_H
#define HOOD_H
#include <string>
#include "LinkedList.h"
using namespace std;

class Hood
{
	string name;
	int totalMiles;
	template <typename T> LinkedList<T> list;

public:
	/*Constructors*/
	Hood();
	Hood(string cityName);

	/*Getters and setters*/
	string getName() const;
	int getTotalMiles() const;
	void setName(string newName);
	void setTotalMiles(int miles);

	//Overloaded stream insertion operator
	friend ostream& operator<<(ostream& out, const Hood& human);


};



#endif
