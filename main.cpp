/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
	https://stackoverflow.com/questions/50979946/virtual-insertion-operator-overloading-for-base-and-derived-class
*/
#include <iostream>
#include <fstream>
#include "Person.h"
#include "WalkData.h"
#include "LinkedList.h"
#include "Hood.h"
#include "ChallengeManager.h"

using namespace std;

int main()
{
	ifstream file("data.txt");

	ChallengeManager challengeManager = ChallengeManager();

	challengeManager.loadData(file);
	LinkedList x = LinkedList();

	LinkedList y = LinkedList(x);


	challengeManager.createCity("Irvine");


	challengeManager.createCity("Orange");
	
	challengeManager.createPerson("John Doe");


	challengeManager.createPerson("Someone");

	Hood* foundCity = challengeManager.findCity("Irvine");

	if (foundCity != nullptr)
	{
		cout << "City found! Logging walks." << endl;
		someone->walk(foundCity, 100);
		defaultPerson->walk(foundCity, 25);
	}
	else cout << "Error: City 'Irvine' not found in manager." << endl;

	defaultPerson->printPersonList();

	cout << someone->getTotalMiles() << endl;
	cout << Irvine->getTotalMiles() << endl;

	return 0;
}