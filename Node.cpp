#include "Node.h"
using namespace std;
template <typename T>
Node<T>::Node(const T& object)
{
	obj = object;
	next = nullptr;
	previous = nullptr;
}

template <typename T>
T Node<T>::getObj()
{
	return obj;
}