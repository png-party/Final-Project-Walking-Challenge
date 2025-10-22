#include <iostream>
#include "Person.h"
#include "WalkData.h"
#include "LinkedList.h"
using namespace std;
int main()
{
	LinkedList bruh = LinkedList();
	WalkData x = WalkData("irvine", 25);
	bruh.addNode(x);

	return 0;
}