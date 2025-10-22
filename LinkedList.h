#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include "Node.h"
using namespace std;
struct WalkData
{
	string name;
	int miles;
};
template <typename T>
class LinkedList
{
	Node<T>* first;
	Node<T>* last;
	int noe;

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

	void addNode(const Node<T>& data);
};


#endif
