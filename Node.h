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
	Node(Person p)
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

	void setNext(Node* link)
	{
		next = link;
	}

	void setPrevious(Node* link)
	{
		previous = link;
	}
};

#endif NODE_H
