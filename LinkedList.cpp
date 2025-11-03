/* 
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
    https://www.geeksforgeeks.org/cpp/how-to-read-from-a-file-in-cpp/
    https://www.hlsl.co.uk/blog/2017/12/1/c-noexcept-and-move-constructors-effect-on-performance-in-stl-containers
    https://cppscripts.com/cpp-delete-copy-constructor
*/
#include "LinkedList.h"
#include "Node.h"
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

void LinkedList::addNode(WalkData* data, double miles)
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
		cout << "Memory could not be allocated!" << endl;
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
		//Link new node to last
		temp->previous = last;
		last->next = temp;
		//Update last
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

/*Delete the node itself, but don't delete the memory in the
 *node's data pointer because it's used in other object's lists
 *Since the ChallengeManager class stores any and all pointers
 * that will be in the node's data pointer, the memory will
 * only be freed by the class's destructor or its methods
 * removePerson or removeCity
 */
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

LinkedList::~LinkedList()
{
	clear();
}

//Move constructor
LinkedList::LinkedList(LinkedList&& other) noexcept
{
	//Steal the other object's pointers
	nodeCount = other.nodeCount;
	first = other.first;
	last = other.last;

	//Modify the other object
	other.nodeCount = 0;
	other.first = nullptr;
	other.last = nullptr;
}

//Move assignment
LinkedList& LinkedList::operator=(LinkedList&& other) noexcept
{
	if (this != &other)
	{
		//Delete existing nodes
		clear();
		//Steal the other object's pointers
		nodeCount = other.nodeCount;
		first = other.first;
		last = other.last;

		//Modify the other object
		other.nodeCount = 0;
		other.first = nullptr;
		other.last = nullptr;
	}
	else cout << "Attempting to move to self!" << endl;
	return *this;
}
