#include "Node.h"
#include "WalkData.h"
using namespace std;

Node::Node(WalkData* value)
{
	previous = nullptr;
	next = nullptr;
	x = value;
}

WalkData* Node::getItem() const
{
	return x;
}






