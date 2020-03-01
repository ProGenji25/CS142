#include "Farm.h"


Farm::Farm(string type, bool rental, int property_value, int days, double farm_discount_rate, string address) : Property(type, rental, property_value, days, address)
{
}

Farm::~Farm()
{
}
//Farm class constructor and deconstructor

double Farm::getDiscountRate()
{
	return farm_discount_rate;
}
//gets farm discount

double Farm::getTax()
{
	double temp;
	getRental();
	if (getRental() == "Rental")
	{
		getDiscountRate();
		temp = farm_rental_tax * (one - farm_discount_rate);
	}
	else if (getRental() == "Not Rental")
	{
		getDiscountRate();
		temp = farm_tax * (one - farm_discount_rate);
	}
	return temp * getValue();
}
//gets taxes

string Farm::toString()
{
	stringstream st;
	st << Property::toString();
	st << "Discounted " << endl;
	st << "Discount Rate " << getDiscountRate() << endl;
	st << "NOTE: Farm Property" << endl;
	return st.str();
}
//convert Farm inputs to Farm stringstream