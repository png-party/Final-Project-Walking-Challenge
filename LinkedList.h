#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include "Node.h"

using namespace std;

class LinkedList
{

public:
	//Constructor
	LinkedList();

	/*Getters and setters*/
	int getNoe() const;

	/*==The Big 5==*/
	//Copy constructor
	LinkedList(const LinkedList& other);
	//Overloaded Assignment operator
	LinkedList& operator=(const LinkedList& RHS);
	//Destructor
	~LinkedList();
	//Move constructor
	LinkedList(LinkedList&& RHS);
	//Move operator
	LinkedList& operator=(LinkedList&& RHS);


	void addNode(const WalkData& data);
	//void addNode(const Node<WalkData>& data);

private:
	Node* first;
	Node* last;
	int noe;
};


#endif
