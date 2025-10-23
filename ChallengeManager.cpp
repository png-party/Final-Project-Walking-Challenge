#include "ChallengeManager.h"
#include <iostream>
using namespace std;

ChallengeManager::ChallengeManager()
{
	cout << "Creating challenge manager instance" << endl;
}

WalkData* ChallengeManager::findItem(const string& userName, const LinkedList& list) 
{
	Node* current = list.getFirst();
	while (current)
	{
		if (current->x->getName() == userName) {
			return current->x;
		}
		current = current->next;
	}
}

