#pragma once
#include "Property.h"
#include <string>
#include <iostream>
#include <sstream>

class Commercial :
	public Property
{
public:
	Commercial(string type, bool rental, int property_value, int days, bool discount, double discount_rate, string address);
	~Commercial();
	virtual string toString();
	//turns line input into modified string
	virtual string getDiscount();
	//determines if it has discount
	virtual double getDiscountRate();
	//gets Discount rate
	virtual double getTax();
	//gets Tax rate


private:
	bool discount;
	double discount_rate;
	const double commercial_tax = 0.01;
	const double commercial_rental_tax = 0.012;
	const int zero = 0;
	const int one = 1;
};

