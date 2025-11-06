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

	/*==The Big 5==
	 *The copy constructor and overloaded assignment operator
	 * are deleted to avoid copying the data or creating
	 * shallow copies of the linked list's pointers.
	 *
	 * See more in Node.h
	 */
	LinkedList(const LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	~LinkedList();
	LinkedList(LinkedList&& other) noexcept;
	LinkedList& operator=(LinkedList&& other) noexcept;

	Node* findNode(const string& name) const;
	bool removeNode(Node* toRemove);
	void addNode(Node* data);
	void clear();

private:
	Node* first;
	Node* last;
	int nodeCount;
};


#endif
