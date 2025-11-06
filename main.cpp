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
#include <iostream>
#include <fstream>
#include "ChallengeManager.h"

using namespace std;

int main()
{
	ifstream file("data.txt");

	ChallengeManager cm;

	cm.loadData(file);
	cm.printMostActive();
	/*
	LinkedList x = LinkedList();

	LinkedList y = LinkedList(x);


	challengeManager.createCity("Irvine");


	challengeManager.createCity("Orange");
	
	challengeManager.createPerson("John Doe");


	challengeManager.createPerson("Someone");

	Hood* foundCity = challengeManager.findCity("Irvine");
	*/


	return 0;
}
