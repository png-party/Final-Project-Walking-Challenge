#include "LinkedList.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList()
{
	first = nullptr;
	last = nullptr;
	noe = 0;
}
//--------------------------------------------------
int LinkedList::getNoe() const
{
	return noe;
}
//--------------------------------------------------
Node* LinkedList::getFirst() const
{
	return first;
}
//--------------------------------------------------
Node* LinkedList::getLast() const
{
	return last;
}
//--------------------------------------------------
LinkedList::LinkedList(const LinkedList& other)
{
}
//--------------------------------------------------
/*
LinkedList& LinkedList::operator=(const LinkedList& RHS)
{

}*/
//--------------------------------------------------
LinkedList::~LinkedList()
{
}
//--------------------------------------------------
LinkedList::LinkedList(LinkedList&& RHS)
{
}
//--------------------------------------------------
/*
LinkedList& LinkedList::operator=(LinkedList&& RHS)
{

}*/

//--------------------------------------------------
void LinkedList::addNode(WalkData* data)
{
	if (noe == 0)
	{
		Node* temp = new Node(data);
		if (temp)
		{
			first = temp;
			temp = nullptr;
			last = first;
			noe++;

		}
		else cout << "Memory could not be allocated" << endl;
	}
	else
	{
		Node* temp = new Node(data);
		if (temp)
		{
			temp->previous = last;
			last->next = temp;
			last = temp;
			temp = nullptr; //idk if this is redundant
			noe++;
		}
		else cout << "Memory could not be allocated" << endl;
	}
}

