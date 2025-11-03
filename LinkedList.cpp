/* 
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList()
{
	first = nullptr;
	last = nullptr;
	nodeCount = 0;
}

int LinkedList::getNodeCount() const
{
	return nodeCount;
}

Node* LinkedList::getFirst() const
{
	return first;
}

Node* LinkedList::getLast() const
{
	return last;
}

LinkedList::LinkedList(const LinkedList& other)
{
	nodeCount = other.nodeCount;

	//Check if copying an empty list
	if (!other.first)
	{
		first = nullptr;
		last = nullptr;
	}
	else
	{
	//	first = new Node(other.first->getData());
		Node* current = other.first;
		while (current)
		{
			WalkData* copyData = new WalkData(*current->getData());
			addNode(copyData);
			current = current->next;
		}
	//	last = current;

	}
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (this != &other)
	{
		clear();
		Node* current = other.first;
		while (current != nullptr)
		{
			addNode(new WalkData(*current->getData()));
			current = current->next;
		}
	}
	else cout << "Attempting self-assignment!" << endl;
	return *this;
}

LinkedList::~LinkedList()
{
	clear();
}

LinkedList::LinkedList(LinkedList&& other)
{
	first = other.first;
	last = other.last;
	nodeCount = other.nodeCount;

	other.first = nullptr;
	other.last = nullptr;
	other.nodeCount = 0;
}

LinkedList& LinkedList::operator=(LinkedList&& other)
{
	if (this != &other)
	{
		clear();

		first = other.first;
		last = other.last;
		nodeCount = other.nodeCount;

		other.first = nullptr;
		other.last = nullptr;
		other.nodeCount = 0;
	}
	else cout << "Attempting self-assignment" << endl;
	return *this;
}

Node* LinkedList::findNode(const string& name) const
{
	Node* current = first;
	while (current)
	{
		if (current->getData()->getName() == name) return current;
		current = current->next;
	}
	return nullptr;
}

void LinkedList::addNode(WalkData* data, int miles)
{
	//Check if pointer is valid
	if (!data)
	{
		cout << "Attempting to add null data!" << endl;
		return;
	}
	Node* temp = new Node(data, miles);
	if (!temp)
	{
		cout << "Memory could not be allocated" << endl;
		return;
	}
	//Check if adding the first node
	if (!first)
	{
		first = temp;
		last = first;
	}
	else
	{
		temp->previous = last;
		last->next = temp;
		last = temp;
	}
	nodeCount++;
}

bool LinkedList::removeNode(Node* toRemove)
{
	if (!toRemove || !first || nodeCount == 0) return false;

	Node* current = first;

	//check if removing the only node in the list
	if (nodeCount == 1)
	{
		first = nullptr;
		last = nullptr;
	}
	//Check if removing the first node
	else if (toRemove == first)
	{
		first = first->next;
	}
	//Check if removing the last node
	else if (toRemove == last)
	{
		last = last->previous;
	}
	else
	{
		while (current)
		{
			if (current == toRemove)
			{
				//Get address of node after the one to remove
				Node* otherNode = current->next;

				//Attach to previous node
				otherNode->previous = current->previous;

				//Make previous node point to next node over
				current->previous->next = otherNode;
			}
			current = current->next;
		}
	}
	delete toRemove;
	nodeCount--;
	return true;
}
/*Delete the node itself, but don't delete the memory
 * in the node's data pointer if it's stored in other lists*/
void LinkedList::clear()
{
	Node* current = first;
	while (current)
	{
		Node* toDelete = current;
		current = current->next;
		delete toDelete;
	}
	first = nullptr;
	last = nullptr;
	nodeCount = 0;
}