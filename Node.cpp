#include "Node.h"
#include "Walkdata.h"
using namespace std;

Node::Node(WalkData value)
{
	previous = nullptr;
	next = nullptr;
	x = value;
}




