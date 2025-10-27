#pragma once
#ifndef HOOD_H
#define HOOD_H

#include <string>
#include "WalkData.h"
#include "LinkedList.h"

using namespace std;

class Hood : public WalkData
{
	LinkedList hoodList = LinkedList();

public:
	Hood();
	Hood(const string& cityName);
	Hood(const Hood& other);
	Hood& operator=(const Hood& other);
	~Hood() override;
	void logWalk(const string& personName, int miles);

	WalkData* getTopWalker() const;

	LinkedList& getList();
	void printHoodList() const;
	void writeToStream(ostream& out) const override;

	friend ostream& operator<<(ostream& out, const Hood& city);


};

#endif