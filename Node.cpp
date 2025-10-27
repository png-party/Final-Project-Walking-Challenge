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