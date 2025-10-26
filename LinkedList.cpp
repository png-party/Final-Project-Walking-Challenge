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
	first = nullptr;
	last = nullptr;
	noe = 0;
	
	Node* current = other.first;
	while (current != nullptr)
	{
		WalkData* copyData = new WalkData(*current->getItem());
		addNode(copyData);
		current = current->next;
	}	
}
//--------------------------------------------------
LinkedList& LinkedList::operator=(const LinkedList& RHS)
{
	if (this != &RHS)
	{
		//call clear function
		clear();

		Node* current = RHS.first;
		while (current != nullptr)
		{
			addNode(new WalkData(*current->getItem()));
			current = current->next;
		}
	}
	return *this;
}
//--------------------------------------------------
LinkedList::~LinkedList()
{
	clear();
}
//--------------------------------------------------
LinkedList::LinkedList(LinkedList&& RHS)
{
	first = RHS.first;
	last = RHS.last;
	noe = RHS.noe;

	RHS.first = nullptr;
	RHS.last = nullptr;
	RHS.noe = 0;
}
//--------------------------------------------------
LinkedList& LinkedList::operator=(LinkedList&& RHS)
{
	if (this != &RHS)
	{
		clear();

		first = RHS.first;
		last = RHS.last;
		noe = RHS.noe;

		RHS.first = nullptr;
		RHS.last = nullptr;
		RHS.noe = 0;
	}
	return *this;
}
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
//--------------------------------------------------
bool LinkedList::removeNode(string name)
{
	if (noe == 0 || first == nullptr)
		return false;

	Node* current = first;

	while (current)
	{
		if (current->x && current->x->getName() == name)
		{
			Node* prev = current->previous;
			Node* next = current->next;

			if (current == first)
			{
				first = next;
				if (first)
					first->previous = nullptr;
			}
			else
			{
				if (prev)
					prev->next = next;
			}

			if (current == last)
			{
				last = prev;
				if (last)
					last->next = nullptr;
			}
			else
			{
				if (next)
					next->previous = prev;
			}

			delete current;
			noe--;
			return true;
		}

		current = current->next;
	}

	return false;
}
//--------------------------------------------------
void LinkedList::clear()
{
	Node* current = first;
	while (current)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
	first = nullptr;
	last = nullptr;
	noe = 0;
}

