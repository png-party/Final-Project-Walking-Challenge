/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1 
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#pragma once
#ifndef NODE_H
#define NODE_H
#include <string>
#include "WalkData.h"

using namespace std;

class Node
{
	Node* next;
	Node* previous;
	WalkData* data;
	int miles;
public:
	Node(WalkData* itemData, int milage); 
	WalkData* getData() const;
	Node* getNext() const;
	Node* getPrevious() const;
	int getMiles() const;

	void setData(WalkData* itemData);
	void setNext(Node* link);
	void setPrevious(Node* link);
	void setMiles(int milage);

	Node(const Node& other);
	Node& operator=(const Node& other);
	~Node();
	Node(Node&& other);
	Node& operator=(Node&& other);

};

#endif NODE_H
