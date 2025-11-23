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
	cout << "===Loading text data===" << endl;
	cm.loadData(file);
	cm.printAllPersons();
	cm.printMostActive();
	cm.printAllPersons();
	cm.printPersonWalks("Riley Robinson");
	cm.getPersonStats("Riley Robinson");
	cm.printPersonWalks("Mia Lee");
	cm.getPersonStats("Mia Lee");
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
	x.printAllPersons();
	cout << "\n===Copying X with the overloaded assignment operator===" << endl;
	ChallengeManager y = x;
	cout << "\n===Y's current data===" << endl;
	y.printAllPersons();
	cout << "\n===Removing a city and person from Y===" << endl;
	y.deletePerson("Sabrina Carpenter");
	y.deleteCity("Irvine");
	cout << "\n===Y after making modifications===" << endl;
	y.printAllPersons();
	cout << "\n===X remains intact after modifying Y===" << endl;
	x.printAllPersons();

	return 0;
}
