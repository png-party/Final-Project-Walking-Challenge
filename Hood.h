#pragma once
#ifndef HOOD_H
#define HOOD_H
#include <string>
#include "WalkData.h"
#include "LinkedList.h"
using namespace std;

class Hood : public WalkData
{
	LinkedList hoodList;

public:
	/*Constructors*/
	Hood();
	Hood(string cityName);

	//Overloaded stream insertion operator
	friend ostream& operator<<(ostream& out, const Hood& human);


};



#endif
