#include "Property.h"


Property::Property(string type, bool rental, int property_value, int days, string address)
{
	this->type = type;
	this->rental = rental;
	this->property_value = property_value;
	this->address = address;
	this->days = days;
}
Property::~Property()
{
}
//Property constructors and deconstructors

string Property::getType()
{
	return type;
}
//gets property type

string Property::getRental()
{
	string temp;
	if (rental == zero)
	{
		temp = "Not Rental";
		return temp;
	}
	else if (rental == one)
	{
		temp = "Rental";
		return temp;
	}
}
// gets rental boolean

int Property::getDays()
{
	return days;
}
//gets days since last payment

int Property::getValue()
{
	return property_value;
}
//gets property value

string Property::getAddress()
{
	return address;
}
//gets address

int Property::getDeadline()
{
	if (getType() == "Farm")
	{
		return hundred;
	}
	else if (getType() == "Residential" || getType() == "Commercial")
	{
		if (getTax() > million)
		{
			return sixty;
		}
		else if (getTax() <= million)
		{
			return ninety;
		}
	}
}
//gets tax deadline

string Property::toString()
{
	stringstream ss;
	ss << type << endl;
	ss << getRental() << endl;
	ss << "Value: $" << property_value << endl;
	ss << "Days since last payment: " << days << endl;
	ss << "Address: " << address << endl;
	return ss.str();
}
// converts property inputs to property stringstream
