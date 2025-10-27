/*TODO
 * ==>Add all functions in .h files that are missing bodies
 * ==>Implement the big 5 in ANY class that has its own pointer member variables
 *
 * 1.) LinkedList:
 *		>Create removeNode() function
 * 2.) Hood:
 *		>Create function to determine person with highest miles
 *		>Make a function to record walking data that isn't just adding a
 *		node since we need to check that one person doesn't end up with like
 *		5 nodes in the hood's list if they walked in that city 5 times
 * 3.) Person:
 *		>Rewrite walk() function so it first checks if the city is in the
 *		person's walking data, and then updates miles in the corresponding
 *		node. Only add node if they've never walked in that city before
 *		>When the person walks, we can use Hood's walking function to update
 *		the hood object's data, too. 
 * 4.) ChallengeManager:
 *		>Update findItem() so it uses the class's own member variables for
 *		the people and cities list--instead of just any lists created in main
 *		>Create a function to add people and cities into their corresponding
 *		linked lists
 * 6.) Hood & Person:
 *		>Make their printList functions look nicer
 */

/*
 * ==New Updates - Please read!==
 * Hood and Person now inherit a base class called WalkData. This base class
 * is used for holding generic "name", "miles" data.
 *
 * Each node now has a pointer to a WalkData object called "x."
 * Because inheriting a base class lets us have polymorphism, this means that
 * linked lists can now hold WalkData, Person, and Hood objects in their nodes.
 * So we don't have to worry about working with templates anymore. 
 *
 * However, when you return a WalkData* pointer when using findItem() from
 * the ChallengeManager class, the compiler can't actually tell if the returned
 * pointer is referring to a Person, Hood, or WalkData obj.
 *
 * This is an issue because what if you wanted to use a function specific to
 * the Hood class? The compiler thinks you're just talking about WalkData objects
 * because that's the type of pointer the nodes use.
 * To fix this, you need to use dynamic casting inside your functions.
 *
 * EX: walk() takes a generic WalkData* pointer in its parameter, but we only
 * want Hood objects, so writing: if (Hood* NewHoodPtr = dynamic_cast<Hood*>(oldWalkDataPtr)) {...}
 * will end up casting the pointer from WalkData* to Hood*
 * If the object isn't the correct type, the assignment will evaluate to
 * nullptr & the if statement won't execute which prevents errors. 
 */

#include <iostream>
#include "Person.h"
#include "WalkData.h"
#include "LinkedList.h"
#include "Hood.h"
#include "ChallengeManager.h"

using namespace std;

int main()
{
	ChallengeManager challengeManager = ChallengeManager();

	Hood* Irvine = new Hood("Irvine");
	challengeManager.addCity(Irvine);

	Hood* Orange = new Hood("Orange");
	challengeManager.addCity(Orange);

	Person* defaultPerson = new Person("John Doe");
	challengeManager.addPerson(defaultPerson);

	Person* someone = new Person("Someone");
	challengeManager.addPerson(someone);

	Hood* foundCity = challengeManager.findCity("Irvine");

	if (foundCity != nullptr)
	{
		cout << "City found! Logging walks." << endl;
		someone->walk(foundCity, 100);
		defaultPerson->walk(foundCity, 25);
	}
	else
	{
		cout << "Error: City 'Irvine' not found in manager." << endl;
	}

	defaultPerson->printPersonList();
	Irvine->printHoodList();

	cout << someone->getTotalMiles() << endl;
	cout << Irvine->getTotalMiles() << endl;

	return 0;
}