#pragma once
#ifndef NODE_H
#define NODE_H
#include <string>
using namespace std;
template <typename T>
class Node
{
public:

	Node(const T& obj);
	T getObj();
private:
	T obj;
	Node* next;
	Node* previous;
};


#endif NODE_H
