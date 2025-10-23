#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "LinkedList.h"
#include "WalkData.h"
#include "Hood.h"
using namespace std;

class Person : public WalkData
{
	LinkedList personList;

public:
	/*Constructors*/
	Person();
	Person(string personName);
	void walk(WalkData* city, int miles);
	void printPersonList() const;
	void writeToStream(ostream& out) const override;
	//Overloaded stream insertion operator
	friend ostream& operator<<(ostream& out, const Person* human);
};

#endif