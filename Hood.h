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
	Hood(const string& cityName);
	~Hood() override;

	WalkData* getTopWalker() const;

	LinkedList& getList();
	void printHoodList() const;
	void writeToStream(ostream& out) const override;

	friend ostream& operator<<(ostream& out, const Hood& city);
	/*Prevent copying*/
	Hood(const Hood& other) = delete;
	Hood& operator=(const Hood& other) = delete;
	/*Move instead*/
	Hood(Hood&& other) noexcept = default;
	Hood& operator=(Hood&& other) noexcept = default;
};

#endif
