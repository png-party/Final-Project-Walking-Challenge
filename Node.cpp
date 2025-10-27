/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#include "Node.h"
#include "WalkData.h"

using namespace std;

Node::Node(WalkData* itemData)
{
	previous = nullptr;
	next = nullptr;
	data = itemData;
}

WalkData* Node::getData() const
{
	return data;
}