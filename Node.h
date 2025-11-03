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
#include "WalkData.h"
#include <iostream>

using namespace std;

class Node
{
	friend class LinkedList;
	Node* next;
	Node* previous;
	WalkData* data;
	double miles;

public:
	Node(WalkData* itemData, double milage)
	{
		data = itemData;
		miles = milage;
		next = nullptr;
		previous = nullptr;
	}

	WalkData* getData() const
	{
		return data;
	}

	Node* getNext() const
	{
		return next;
	}

	Node* getPrevious() const
	{
		return previous;
	}

	double getMiles() const
	{
		return miles;
	}

	void setData(WalkData* itemData)
	{
		data = itemData;
	}

	void setNext(Node* link)
	{
		next = link;
	}

	void setPrevious(Node* link)
	{
		previous = link;
	}

	void setMiles(double milage)
	{
		miles = milage;
	}

	/*==The Big 5==
	 * The copy constructor and overloaded assignment operator
	 * aren't rewritten because the nodes don't have sole
	 * ownership over the objects at their data pointers.
	 * Since the nodes point to other WalkData objects,
	 * such as a person or city, the data is shared by
	 * multiple lists, so shallow copies are intended.
	 * The Challenge Manager class is responsible
	 * for freeing up the memory at those WalkData*
	 * pointers through its destructor or its removePerson
	 * and removeCity methods.
	 */

	/*The node itself will be deleted, like the miles it
	 * stores, but the data at its pointer won't be.
	 * deleted by this class
	 */
	~Node()
	{
		data = nullptr;
	}

	Node(Node&& other) noexcept
	{
		data = other.data;
		miles = other.miles;
		next = other.next;
		previous = other.previous;

		other.data = nullptr;
		other.miles = 0;
		other.next = nullptr;
		other.previous = nullptr;
	}

	Node& operator=(Node&& other) noexcept
	{
		if (this != &other)
		{
			data = other.data;
			miles = other.miles;
			next = other.next;
			previous = other.previous;

			other.data = nullptr;
			other.miles = 0;
			other.next = nullptr;
			other.previous = nullptr;
		}
		else cout << "Attempting to move to self!" << endl;
		return *this;
	}
};

#endif NODE_H
