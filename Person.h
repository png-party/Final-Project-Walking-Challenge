/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1 
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
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
	Person();
	Person(string personName);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person() override;
	void walk(WalkData* city, int miles);
	void printPersonList() const;
	void writeToStream(ostream& out) const override;

	friend ostream& operator<<(ostream& out, const Person* person);
};

#endif