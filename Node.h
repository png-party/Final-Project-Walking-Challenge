#pragma once
#ifndef NODE_H
#define NODE_H
#include <string>
#include "WalkData.h"
using namespace std;

class Node
{
public:

	Node(const T& obj);
	T getObj();
private:
	T obj;
	Node* next;
	Node* previous;
	WalkData x;
	Node(WalkData item);
};


#endif NODE_H
