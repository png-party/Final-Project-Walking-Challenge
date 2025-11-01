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
#include <iostream>

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

Node::Node(const Node& other)
{
	previous = nullptr;
	next = nullptr;
	WalkData* temp = new WalkData(other.data->getName(), other.data->getTotalMiles());
	if (temp)
	{
		data = temp;
	}
	else cout << "Memory could not be allocated!" << endl;
}

Node& Node::operator=(const Node& other)
{
	if (this != &other)
	{
		previous = nullptr;
		next = nullptr;
		delete[] data;
		WalkData* temp = new WalkData(other.data->getName(), other.data->getTotalMiles());
		if (temp)
		{
			data = temp;
		}
		else cout << "Memory could not be allocated!" << endl;
	}
	else cout << "Attempting self-assignment!" << endl;
	return *this;
}

Node::~Node()
{
	delete[] data;
}

Node::Node(Node&& other)
{
	previous = other.previous;
	next = other.next;
	data = other.data;

	other.previous = nullptr;
	other.next = nullptr;
	other.data = nullptr;
}

Node& Node::operator=(Node&& other)
{
	if (this != &other)
	{
		previous = other.previous;
		next = other.next;
		data = other.data;

		other.previous = nullptr;
		other.next = nullptr;
		other.data = nullptr;
	}
	else cout << "Attempting to move to self!" << endl;
	return *this;
}
