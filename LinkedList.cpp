#include "LinkedList.h"
#include <iostream>
using namespace std;

template <typename T>
LinkedList<T>::LinkedList()
{
}

template <typename T>
int LinkedList<T>::getNoe() const
{
	return noe;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& RHS)
{
}

template <typename T>
LinkedList<T>::~LinkedList()
{
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList&& RHS)
{
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList&& RHS)
{
}

template <typename T>
void LinkedList<T>::addNode(const Node<T>& data)
{
	if (noe == 0)
	{
		Node<T>* temp = new Node<T>(data);
		if (temp)
		{
			first = temp;
			temp = nullptr;
			last = first;
			noe++;

		} else cout << "Memory could not be allocated" << endl;
	}
	else
	{
		Node<T>* temp = new Node<T>(data);
		if (temp)
		{
			temp->previous = last;
			last->next = temp;
			noe++;
		} else cout << "Memory could not be allocated" << endl;
	}
}
