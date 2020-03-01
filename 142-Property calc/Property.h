#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Property
{
public:
	Property(string type, bool rental, int property_value, int days, string address);
	~Property();

	virtual string getType();
	//determines if residential or commercial
	virtual string getRental();
	//determine if rental
	virtual int getValue();
	//retrieves property value
	virtual string getAddress();
	// retrieves address
	virtual string toString();
	//turns line input into modified string
	virtual double getTax() = 0;
	//get tax function
	virtual int getDays();
	//finds days since last tax payment
	virtual int getDeadline();
	//finds deadline for next taxes
	
private:
	string type;
	string address;
	bool rental;
	int property_value;
	const int zero = 0;
	const int one = 1;
	int days;
	const int million = 1000000;
	const int hundred = 100;
	const int sixty = 60;
	const int ninety = 90;
};

