#include "Commercial.h"


Commercial::Commercial(string type, bool rental, int property_value, int days, bool discount, double discount_rate, string address) : Property(type, rental, property_value, days, address)
{
	this->discount = discount;
	this->discount_rate = discount_rate;
}


Commercial::~Commercial()
{
}
//Commercial class constructor and deconstructor

string Commercial::getDiscount()
{
	string temp;
	if (discount == zero)
	{
		temp = "Not Discounted";
		return temp;
	}
	else if (discount == one)
	{
		temp = "Discounted";
		return temp;
	}
}
//gets discount boolean

double Commercial::getDiscountRate()
{
	double temp;
	if (discount == zero)
	{
		temp = discount_rate;
		return temp;
	}
	else if (discount == one)
	{
		temp = discount_rate;
		return temp;
	}
}
//gets discount rate

double Commercial::getTax()
{
	double temp;
	getRental();
	getDiscount();
	if (getRental() == "Rental")
	{
		if (getDiscount() == "Discounted")
		{
			getDiscountRate();
			temp = commercial_rental_tax * (one- discount_rate);
		}
		else if (getDiscount() == "Not Discounted")
		{
			temp = commercial_rental_tax;
		}
	}
	else if (getRental() == "Not Rental")
	{
		if (getDiscount() == "Discounted")
		{
			getDiscountRate();
			temp = commercial_tax * (one - discount_rate);
		}
		else if (getDiscount() == "Not Discounted")
		{
			getDiscountRate();
			temp = commercial_tax;
		}
	}
	return temp * getValue();
}
//determines the taxes due

string Commercial::toString()
{
	stringstream st;
	st << Property::toString();
	st << getDiscount() << endl;
	if (getDiscount() == "Discounted")
	{
		st << "Discount: " << getDiscountRate() << endl;
	}
	
	return st.str();
}
//converts all inputs into Commercial stringstream