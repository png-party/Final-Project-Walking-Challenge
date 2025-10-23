/*TODO:
 * Implement big 5
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
	WalkData* x;
	Node(WalkData* item);
	WalkData* getItem() const;
};





#endif NODE_H
