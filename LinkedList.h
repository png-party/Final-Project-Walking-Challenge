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
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "Node.h"

using namespace std;

class LinkedList
{
public:
	LinkedList();

	int getNodeCount() const;
	Node* getFirst() const;
	Node* getLast() const;

	/* ==The Big 5== */
	//Copy constructor
	LinkedList(const LinkedList& other);
	//Overloaded assignment operator
	LinkedList& operator=(const LinkedList& other);
	//Destructor
	~LinkedList();
	//Move constructor
	LinkedList(LinkedList&& other) noexcept;
	//Overloaded move operator
	LinkedList& operator=(LinkedList&& other) noexcept;

	void addNode(Node* data);
	bool removeNode(const string& name);
	Node* findNode(const string& name) const;
	void clear();

private:
	Node* first;
	Node* last;
	int nodeCount;
	
};


#endif
