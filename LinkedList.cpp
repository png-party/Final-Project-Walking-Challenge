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
	nodeCount = 0;
}

//Copy constructor
LinkedList::LinkedList(const LinkedList& other)
{
	//Check if copying an empty list
	if (!other.first)
	{
		first = nullptr;
		last = nullptr;
		nodeCount = 0;
	}
	else
	{
		nodeCount = other.nodeCount;
		Node* otherptr = other.first;

		/* The nothrow argument with the new operator prevents
		 * an error from being thrown if memory allocation fails
		 * Instead, it sets the pointer to nullptr  */
		Node* current = new (std::nothrow) Node(*otherptr->getData());
		/* Points to valid data or nullptr if memory allocation fails,
		 * preventing loop from starting if it fails */
		first = current; 
		while (current && otherptr->next)
		{
			if (Node* temp = new (std::nothrow) Node(*otherptr->next->getData()))
			{
				//Link new node to previous node
				temp->previous = current;
				//Connect current node to new node
				current->next = temp;

				//Keep traversing
				current = current->next;
				otherptr = otherptr->next;
			}
			else  //Break loop if memory allocation fails
			{
				cout << "Memory could not be allocated!" << endl;
				break;
			}
		}
		last = current;
	}
}
/*Overloaded assignment operator*/
LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (this != &other)
	{
		clear();
		nodeCount = other.nodeCount;
		Node* otherptr = other.first;

		Node* current = new (nothrow) Node(*otherptr->getData());
		first = current;
		while (current && otherptr->next)
		{
			if (Node* temp = new (nothrow) Node(*otherptr->next->getData()))
			{
				//Link new node to previous node
				temp->previous = current;
				//Connect new node to current node
				current->next = temp;

				//Keep traversing both lists 
				current = current->next;
				otherptr = otherptr->next;
			}
			else  //Break loop if memory allocation fails
			{
				cout << "Memory could not be allocated!" << endl;
				break;
			}
		}
		last = current;
	}
	else cout << "Attempting self-assignment!" << endl;
	return *this;
}

/*Destructor*/
LinkedList::~LinkedList()
{
	clear();
}

/*Move constructor*/
LinkedList::LinkedList(LinkedList&& other) noexcept
{
	first = other.first;
	last = other.last;
	nodeCount = other.nodeCount;

	other.first = nullptr;
	other.last = nullptr;
	other.nodeCount = 0;
}

/*Move assignment operator*/
LinkedList& LinkedList::operator=(LinkedList&& other) noexcept
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
	else cout << "Attempting self-assignment!" << endl;
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

void LinkedList::addNode(Node* data)
{
	//Check if pointer is valid
	if (!data)
	{
		cout << "Attempting to add null data!" << endl;
		return;
	}
	//Check if adding the first node
	if (!first)
	{
		first = data;
		last = first;
	}
	else
	{
		//Link new node to last
		data->previous = last;
		last->next = data;
		//Update last
		last = data;
	}
	nodeCount++;
}

bool LinkedList::removeNode(const string& name)
{
	Node* toRemove = findNode(name);
	if (!toRemove || !first || nodeCount == 0) return false;
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
		first->previous = nullptr; //Prevent dangling pointer to freed memory
	}
	//Check if removing the last node
	else if (toRemove == last)
	{
		last = last->previous;
		last->next = nullptr; //Prevent dangling pointer to freed memory
	}
	else
	{
		//Get address of next node after the one to remove
		Node* otherNode = toRemove->next;

		//Attach to previous node
		otherNode->previous = toRemove->previous;

		//Make previous node point to next node over
		toRemove->previous->next = otherNode;
	}
	//Finally, delete the node
	delete toRemove;
	nodeCount--;
	return true;
}

