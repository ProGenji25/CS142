#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Property.h"
#include "Commercial.h"
#include "Residential.h"
#include "Farm.h"
/*
Main Function that builds vector list of various real estate ranging from Farms, Residential, and Commercial properties
Determines the variables specific to each property in the list
Prints a tax report for all valid property inputs
*/
using namespace std;
const int zero = 0;

void printList(vector<Property*> list)
{
	cout << "All valid properties:" << endl;
	for (unsigned i = zero; i < list.size(); i++)
	{
		cout << "Property ID:" << i << " "<< list[i]->toString() << endl;
	}
}
//prints list of valid property inputs

int main()
{
	string file;
	string type;
	bool rental;
	int property_value = 0;
	int days = 0;
	bool occupancy;
	bool discount;
	double discount_rate = 0;
	const double farm_discount_rate = .4;
	string address;
	vector<Property*> list;
	const int million = 1000000;
	//main variables

	cout << "Input file name." << endl;
	cin >> file;
	ifstream inputfile;
	string line;
	inputfile.open(file.c_str());
	//reads text file to program

	if (inputfile.is_open())
	{
		while (getline(inputfile, line))
		{
			stringstream strm(line);
			if (strm >> type >> rental >> property_value >> days)
			{
				if (type == "Residential")
				{
					strm >> occupancy;
					if (!strm.fail())
					{
						getline(strm, address);
						Property* real_estate = new Residential(type, rental, property_value, days, occupancy, address);
						list.push_back(real_estate);
					}
					else
					{
						cout << "Ignoring bad RESIDENTIAL in input file: " << line << endl;
					}
				}
				//handles input for residential properties

				else if (type == "Commercial")
				{
					strm >> discount;
					strm >> discount_rate;
					if (!strm.fail())
					{
						getline(strm, address);
						Property* real_estate = new Commercial(type, rental, property_value, days, discount, discount_rate, address);
						list.push_back(real_estate);
					}
					else
					{
						cout << "Ignoring bad COMMERCIAL in input file: " << line << endl;
					}
				}
				//handles input for commercial properties

				else if (type == "Farm")
				{
					if (!strm.fail())
					{
						getline(strm, address);
						Property* real_estate = new Farm(type, rental, property_value, days, farm_discount_rate, address);
						list.push_back(real_estate);
					}
					else
					{
						cout << "Ignoring bad FARM in input file: " << line << endl;
					}
				}
				//handles input for farm properties
			}
			else
			{
				cout << "Ignoring bad input in input file: " << line << endl;
				cout << endl;
			}
			//ignores bad input
		}

		printList(list);

		cout << "Now Printing Tax Report" << endl << endl;
		for (int i = zero; i < list.size(); i++)
		{
			cout << "Taxes due for the property at: " << list[i]->getAddress() << endl;
			cout << "Property ID: " << i << endl;
			cout << "This property has an estimated value of: " << list[i]->getValue() << endl;
			cout << "Last payment: " << list[i]->getDays() <<" days ago" << endl;
			cout << "Taxes due on this property are: " << list[i]-> getTax() << endl;
			if (list[i]->getType() == "Farm")
			{
				cout << "Taxes due on this property in: " << list[i]->getDeadline() << " days" << endl << endl;
			}
			else if (list[i]->getType() == "Residential" || list[i]->getType() == "Commercial")
			{
				if (list[i]->getTax() > million)
				{
					cout << "Taxes due on this property in: " << list[i]->getDeadline() << " days" << endl << endl;
				}
				else if (list[i]->getTax() <= million)
				{
					cout << "Taxes due on this property in: " << list[i]->getDeadline() << " days" << endl << endl;
				}
			}
		}
		//prints tax report
	}
	else
	{
		cout << "Invalid file" << endl;
		system("pause");
		return 0;
		//rejects invalid file name
	}
	system("pause");
	return 0;
}