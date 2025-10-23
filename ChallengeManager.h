#pragma once
#ifndef CHALLENGEMANAGER_H
#define CHALLENGEMANAGER_H
#include "Person.h"
#include "Hood.h"
class ChallengeManager
{
	LinkedList cities;
	LinkedList people;
public:

	ChallengeManager();
	WalkData* findItem(const string& userName, const LinkedList& list);

};
#endif