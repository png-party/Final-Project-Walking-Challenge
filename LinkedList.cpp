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

void LinkedList::addNode(WalkData* data)
{
	//Check if adding the first node
	if (nodeCount == 0)
	{
		Node* temp = new Node(data);
		if (temp)
		{
			first = temp;
			last = first;
			nodeCount++;
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
			nodeCount++;
		}
		else cout << "Memory could not be allocated" << endl;
	}
}

bool LinkedList::removeNode(string name)
{
	if (nodeCount == 0 || first == nullptr)
		return false;

	Node* current = first;

	while (current)
	{
		if (current->data && current->data->getName() == name)
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

			delete current->data;
			current->data = nullptr;
			delete current;
			current = nullptr;

			nodeCount--;
			return true;
		}
		current = current->next;
	}
	return false;
}

void LinkedList::clear()
{
	Node* current = first;
	while (current)
	{
		Node* next = current->next;

		delete current->data;
		current->data = nullptr;

		delete current;
		current = next;
	}
	first = nullptr;
	last = nullptr;
	nodeCount = 0;
}