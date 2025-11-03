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

Node::Node(WalkData* itemData, double milage)
{
	data = itemData;
	miles = milage;
	next = nullptr;
	previous = nullptr;
}

WalkData* Node::getData() const
{
	return data;
}

Node* Node::getNext() const
{
	return next;
}

Node* Node::getPrevious() const
{
	return previous;
}

double Node::getMiles() const
{
	return miles;
}

void Node::setData(WalkData* itemData)
{
	data = itemData;
}

void Node::setNext(Node* link)
{
	next = link;
}

void Node::setPrevious(Node* link)
{
	previous = link;
}

void Node::setMiles(double milage)
{
	miles = milage;
}

Node::Node(const Node& other)
{
	data = other.data;
	miles = other.miles;
	next = nullptr;
	previous = nullptr;
	
}

Node& Node::operator=(const Node& other)
{
	if (this != &other)
	{
		data = other.data;
		miles = other.miles;
		next = nullptr;
		previous = nullptr;
	}
	else cout << "Attempting self-assignment!" << endl;
	return *this;
}

Node::~Node()
{
	data = nullptr;
}

Node::Node(Node&& other)
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

Node& Node::operator=(Node&& other)
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
