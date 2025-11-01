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
public:
	Node* next;
	Node* previous;
	WalkData* data; 
	Node(WalkData* itemData); 
	WalkData* getData() const;

	Node(const Node& other);
	Node& operator=(const Node& other);
	~Node();
	Node(Node&& other);
	Node& operator=(Node&& other);

};

#endif NODE_H
