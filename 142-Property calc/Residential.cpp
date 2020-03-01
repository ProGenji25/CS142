#include "Residential.h"


Residential::Residential(string type, bool rental, int property_value, int days, bool occupancy, string address) : Property(type, rental, property_value, days, address)
{
	this->occupancy = occupancy;
}

Residential::~Residential()
{
}
//Residnetial constructor and deconstructor

string Residential::getOccupancy()
{
	string temp;
	if (occupancy == zero)
	{
		temp = "Not Occupied";
		return temp;
	}
	else if (occupancy == one)
	{
		temp = "Occupied";
		return temp;
	}
}
//gets occupancy boolean

string Residential::toString()
{
stringstream st;
st << Property::toString();
st << getOccupancy() << endl;
return st.str();
}
//turns Residential inputs to Residential stringstream

double Residential::getTax()
{
	double temp;
	getOccupancy();
	if (getOccupancy() == "Occupied")
	{
		temp = residential_occupied_tax;
		return temp * getValue();
	}
	else if (getOccupancy() == "Not Occupied")
	{
		temp = residential_tax;
		return temp * getValue();
	}
}
//gets tax rate