#pragma once
#include "Property.h"
#include <string>
#include <iostream>
#include <sstream>

class Farm :
	public Property
{
public:
	Farm(string type, bool rental, int property_value, int days, double farm_discount_rate, string address);
	~Farm();

	virtual string toString();
	//turns line input into modified string
	virtual double getDiscountRate();
	//gets Discount rate
	virtual double getTax();
	//gets tax rate

private:
	const double farm_discount_rate = .4;
	const double farm_tax = 0.01;
	const double farm_rental_tax = 0.012;
	const int zero = 0;
	const int one = 1;
};

