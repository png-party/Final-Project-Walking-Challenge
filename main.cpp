/*
Nicole Sirbu, Nicolas Grant, Ramon Aguilera
CMPR 131 - Fall 2025
October 26th, 2025
Final Project #1
Collaboration:
    https://www.geeksforgeeks.org/cpp/how-to-read-from-a-file-in-cpp/
    https://www.hlsl.co.uk/blog/2017/12/1/c-noexcept-and-move-constructors-effect-on-performance-in-stl-containers
    https://www.geeksforgeeks.org/cpp/if-memory-allocation-using-new-is-failed-in-c-then-how-it-should-be-handled/
*/
#include <iostream>
#include <fstream>
#include "ChallengeManager.h"

using namespace std;

int main()
{

	ChallengeManager m = ChallengeManager();
	m.createCity("New York");
	m.createCity("Vancouver");
	m.createCity("Villa Park");
	m.createCity("San Diego");

	m.createPerson("Alice Walker");
	m.createPerson("Hugh Mann");
	m.createPerson("Bob Lastname");
	m.createPerson("Wendy Walker");

	m.logWalk("Alice Walker", "Vancouver", 2.7);
	m.logWalk("Alice Walker", "San Diego", 3.5);
	m.logWalk("Hugh Mann", "Villa Park", 10.6);
	m.logWalk("Bob Lastname", "New York", 6.7);
	m.logWalk("Bob Lastname", "New York", 2.4);
	m.logWalk("Wendy Walker", "Vancouver", 8.5);
	m.logWalk("Wendy Walker", "San Diego", 7.2);

	m.printAllParticipants();
	m.getPersonStats("Bob Lastname");
	m.printMostActive();
	m.removeCity("Vancouver");
	m.printMostActive();
	m.removePerson("Hugh Mann");
	m.printAllParticipants();
	m.printMostActive();


	ifstream file("data.txt");
	ChallengeManager cm = ChallengeManager();
	cm.loadData(file);

	cout << "\n" << endl;
	cm.printMostActive();
	cout << "\n" << endl;

	cm.printAllParticipants();

	cm.getPersonStats("Riley Robinson");
	cout << "\n" << endl;


	cout << "===Adding cities/people and recording walks===" << endl;
	ChallengeManager x = ChallengeManager();
	x.createCity("Irvine");
	x.createCity("Los Angeles");
	x.createCity("Tustin");
	x.createPerson("John Doe");
	x.createPerson("Jane Doe");
	x.createPerson("Sabrina Carpenter");
	x.logWalk("John Doe", "Irvine", 1.4);
	x.logWalk("Jane Doe", "Los Angeles", 2.3);
	x.logWalk("Sabrina Carpenter", "Tustin", 9);


	cout << "\n===X's current data===" << endl;
	x.printAllParticipants();
	cout << "\n===Copying X with the overloaded assignment operator===" << endl;
	ChallengeManager y = x;
	cout << "\n===Y's current data===" << endl;
	y.printAllParticipants();
	cout << "\n===Removing a city and person from Y===" << endl;
	y.removePerson("Sabrina Carpenter");
	y.removeCity("Irvine");
	y.printAllParticipants();
	cout << "\n===X remains intact after modifying Y===" << endl;
	x.printAllParticipants();


	return 0;
}
