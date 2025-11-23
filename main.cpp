/*
Christiandior Falucho, Nicole Sirbu, Mohamed Ziq, Nicholas Donaldson
CMPR 131 - Fall 2025
November 22nd, 2025
Final Project #2
Collaboration:
	https://en.cppreference.com/w/cpp/container/unordered_map.html
	https://en.cppreference.com/w/cpp/utility/pair.html
	https://www.geeksforgeeks.org/cpp/different-ways-to-initialize-an-unordered_map-in-cpp/
	https://www.geeksforgeeks.org/cpp/traversing-a-map-or-unordered_map-in-cpp-stl/
*/
#include <iostream>
#include <fstream>
#include "ChallengeManager.h"

using namespace std;

int main()
{
	ChallengeManager cm = ChallengeManager();
	ifstream file("data.txt");
	cm.loadData(file);
	cm.printPersonMap();
	//cm.printAllParticipants();
	cm.addPerson("Someone");
	cm.addPerson("Sabrina Carpenter");
	Person* p = cm.getPersonObject("Someone");
	cout << p->getList().capacity() << endl;
	cm.getPersonStatsMap("Someone");
	//cm.addCity("Aaaa");
	
	cm.logWalk("Sabrina Carpenter", "Villa Park", 12);
	cm.logWalk("Sabrina Carpenter", "Orange Hills", 12);
	cm.getPersonStatsMap("Sabrina Carpenter");
	cm.printPersonWalks("Sabrina Carpenter");


	ChallengeManager m = ChallengeManager();
	m.addCity("New York");
	m.addCity("Vancouver");
	m.addCity("Villa Park");
	m.addCity("San Diego");

	m.addPerson("Alice Walker");
	m.addPerson("Hugh Mann");
	m.addPerson("Bob Lastname");
	m.addPerson("Wendy Walker");

	m.logWalk("Alice Walker", "Vancouver", 2.7);
	m.logWalk("Alice Walker", "San Diego", 3.5);
	m.logWalk("Hugh Mann", "Villa Park", 10.6);
	m.logWalk("Bob Lastname", "New York", 6.7);
	m.logWalk("Bob Lastname", "New York", 2.4);
	m.logWalk("Wendy Walker", "Vancouver", 8.5);
	m.logWalk("Wendy Walker", "San Diego", 7.2);

	m.printPersonMap();
	m.getPersonStatsMap("Bob Lastname");
	m.printMostActive();
	m.deleteCity("Vancouver");
	m.printMostActive();
	m.deletePerson("Hugh Mann");

	m.printPersonMap();
	m.printMostActive();


	cout << "\n" << endl;
	cm.printMostActive();
	cout << "\n" << endl;

	cm.printPersonMap();

	cm.getPersonStatsMap("Riley Robinson");
	cout << "\n" << endl;


	cout << "===Adding cities/people and recording walks===" << endl;
	ChallengeManager x = ChallengeManager();
	x.addCity("Irvine");
	x.addCity("Los Angeles");
	x.addCity("Tustin");
	x.addPerson("John Doe");
	x.addPerson("Jane Doe");
	x.addPerson("Sabrina Carpenter");
	x.logWalk("John Doe", "Irvine", 1.4);
	x.logWalk("Jane Doe", "Los Angeles", 2.3);
	x.logWalk("Sabrina Carpenter", "Tustin", 9);


	cout << "\n===X's current data===" << endl;
	x.printPersonMap();
	cout << "\n===Copying X with the overloaded assignment operator===" << endl;
	ChallengeManager y = x;
	cout << "\n===Y's current data===" << endl;
	y.printPersonMap();
	cout << "\n===Removing a city and person from Y===" << endl;
	y.deletePerson("Sabrina Carpenter");
	y.deleteCity("Irvine");
	y.printPersonMap();
	cout << "\n===X remains intact after modifying Y===" << endl;
	x.printPersonMap();

	return 0;
}
