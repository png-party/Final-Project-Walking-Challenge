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
	WalkData* data; 
	Node(WalkData* itemData); 
	WalkData* getData() const; 
};

#endif NODE_H
