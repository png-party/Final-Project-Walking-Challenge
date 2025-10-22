#include "Hood.h"
#include <iostream>
using namespace std;

Hood::Hood()
{
	cout << "Creating a default neighborhood object" << endl;
}

Hood::Hood(string cityName) : WalkData(cityName)
{
	cout << "Creating neighborhood object" << endl;
}



ostream& operator<<(ostream& out, const Hood& city)
{
	return out;
}
