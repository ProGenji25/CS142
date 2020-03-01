#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include "Property.h"

class Residential : public Property
{
public:
	Residential(string type, bool rental, int property_value, int days, bool occupancy, string address);
	~Residential();
	virtual string toString();
	//turns line input into modified string
	virtual string getOccupancy();
	//Determine if occupied
	virtual double getTax();
	//gets tax rate

private:
	bool occupancy;
	const double residential_tax = 0.009;
	const double residential_occupied_tax = 0.006;
	const int zero = 0;
	const int one = 1;
};

