#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include "LinkedList.h"
using namespace std;

class Person
{
private:
	string name;
	int totalMiles;
	template <typename T>LinkedList<T> list;

public:
	/*Constructors*/
	Person();
	Person(string personName);

	/*Getters and setters*/
	string getName() const;
	int getTotalMiles() const;
	void setName(string newName);
	void setTotalMiles(int miles);

	//Overloaded stream insertion operator
	friend ostream& operator<<(ostream& out, const Person& human);


};
	
#endif