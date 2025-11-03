/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1 
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include "Node.h"

using namespace std;
class Node;
class LinkedList
{
public:
	friend class Node;
	LinkedList();

	int getNodeCount() const;
	Node* getFirst() const;
	Node* getLast() const;

	LinkedList(const LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	~LinkedList();
	LinkedList(LinkedList&& other);
	LinkedList& operator=(LinkedList&& other);

	Node* findNode(const string& name) const;
	bool removeNode(Node* toRemove);
	void addNode(WalkData* data, int miles);
	void clear();

private:
	Node* first;
	Node* last;
	int nodeCount;
};


#endif