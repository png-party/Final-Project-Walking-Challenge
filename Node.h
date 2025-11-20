/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
	https://www.geeksforgeeks.org/cpp/how-to-read-from-a-file-in-cpp/
	https://www.hlsl.co.uk/blog/2017/12/1/c-noexcept-and-move-constructors-effect-on-performance-in-stl-containers
	https://www.geeksforgeeks.org/cpp/if-memory-allocation-using-new-is-failed-in-c-then-how-it-should-be-handled/
*/
#pragma once
#ifndef NODE_H
#define NODE_H
#include "Person.h"
#include <iostream>

using namespace std;

class Node
{
	friend class LinkedList;
	Node* next;
	Node* previous;
	Person data;

public:
	Node(const Person& p)
	{
		data = p;
		next = nullptr;
		previous = nullptr;
	}

	Person* getData()
	{
		return &data;
	}

	Node* getNext() const
	{
		return next;
	}

	Node* getPrevious() const
	{
		return previous;
	}

	void setData(const Person& p)
	{
		data = p;
	}
	friend ostream& operator<<(ostream& out, const Node* other)
	{
		if (!other) out << "Null value" << endl;
		else out << other->data;
		return out;
	}

};

#endif NODE_H
