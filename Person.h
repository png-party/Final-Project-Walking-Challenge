#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "LinkedList.h"
#include "WalkData.h"
using namespace std;

class Person : public WalkData
{
	LinkedList personList;

public:
	/*Constructors*/
	Person();
	Person(string personName);

	//Overloaded stream insertion operator
	friend ostream& operator<<(ostream& out, const Person& human);
};

#endif