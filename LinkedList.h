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

	LinkedList(const LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	~LinkedList();
	LinkedList(LinkedList&& other);
	LinkedList& operator=(LinkedList&& other);

	bool removeNode(string name);
	void addNode(WalkData* data);
	void clear();

private:
	Node* first;
	Node* last;
	int nodeCount;
};


#endif