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
#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "LinkedList.h"
#include "Hood.h"
#include "WalkData.h"

using namespace std;

class Person : public WalkData
{
	static int lastId;
	LinkedList personList;
	int userId;

public:
	Person(const string& personName);
	Person(const string& personName, int identity);
	~Person() override;
	void printMinMaxWalks() const;
	int getUserId() const;
	LinkedList& getList();
	void setUserId(int identity);
	void printPersonList() const;
	void writeToStream(ostream& out) const override;

	friend ostream& operator<<(ostream& out, const Person* person);
	/*Prevent copying*/
	Person(const Person& other) = delete;
	Person& operator=(const Person& other) = delete;
	/*Move instead*/
	Person(Person&& other) noexcept = default;
	Person& operator=(Person&& other) noexcept = default;
};

#endif
