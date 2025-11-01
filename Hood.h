/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1 
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#pragma once
#ifndef HOOD_H
#define HOOD_H

#include <string>
#include "WalkData.h"
#include "LinkedList.h"

using namespace std;

class Hood : public WalkData
{
	LinkedList hoodList = LinkedList();

public:
	Hood();
	Hood(const string& cityName);
	~Hood() override;
	void logWalk(const string& personName, int miles);

	WalkData* getTopWalker() const;

	LinkedList& getList();
	void printHoodList() const;
	void writeToStream(ostream& out) const override;

	friend ostream& operator<<(ostream& out, const Hood& city);
};

#endif