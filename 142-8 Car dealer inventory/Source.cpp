#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "Car.h"
using namespace std;

/*
Test cases
 load cars1.txt >> display inventory >> balance = $10529.23 >> change color of Lemon to red >> Lemon price = $5226.99  >> sell Jalopy >> balance = $14756.22 >> saves corectly
 load cars2.txt >> display inventory >> balance = $69715.43 >> Buy black Batmobile for $11000 _ can not buy>> sell Lima >> balance = $82084.42 >> saves corectly
Buy red mustang $1235>> balance = $8765 >> change color to blue >> price = $2235 >> sell Mustang >> balance = $11000
*/

const int NOT_FOUND = -1;
const int zero = 0;

void DisplayInventory(vector<Car>& inventory)
{
	for (int i = zero; i < inventory.size(); i++)
	{
		cout << inventory[i].toString() << endl;
	}
}
//display inventory
int findCar(vector<Car> inventory, string name)
{
	for (int i = zero; i < inventory.size(); i++)
	{
		inventory[i].getName();
		if (inventory[i].getName() == name)
		{
			return i;
		}
	}
	return NOT_FOUND;
}
//finds if car exists
void BuyCar(vector<Car>& inventory, double& cash_balance, string& name, string& color, double& price)
{
	cout << "Type the name, color, and price of the car you wish to buy." << endl;
	cin.sync();
	getline(cin, name);
	getline(cin, color); 
	cin >> price;
	if (price <= cash_balance)
	{
		cash_balance -= price;
		inventory.push_back(Car(name, color, price));
	}
	else
	{
		cout << "Can't Buy Car.  Price Too High." << endl;
	}
}
//buys new car
void SellCar(vector<Car>& inventory, double& cash_balance, string& name, string& color, double& price)
{
	cout << "Type the name of the car you wish to sell." << endl;
	cin.sync();
	cin >> name;
	int index = findCar(inventory, name);
	if (index == NOT_FOUND)
	{
		cout << "Car does not exist." << endl;
	}
	else if (name == name)
	{
		cash_balance += inventory[index].getPrice();
		inventory.erase(inventory.begin() + index);
	}
	
}
//sells car in inventory
void PaintCar(vector<Car>& inventory, double& cash_balance, string& name, string& color, double& price)
{
	cout << "Type the name of the car you want to paint." << endl;
	cin >> name;
	int index = findCar(inventory, name);
	if (index == NOT_FOUND)
	{
		cout << "Car does not exist." << endl;
	}
	else
	{
		cout << "What new color do you want?" << endl;
		string new_color;
		cin >> new_color;
		Car temp = Car(name, color, price);
		temp.getName();
		temp.getColor();
		temp.getPrice();
		inventory[index].paint(new_color);
	}
}
//paints car object with new color
void LoadFile(vector<Car>& inventory, string& file, double& cash_balance, string& name, string& color, double& price, double& temp)
{
	cout << "Input file name." << endl;
	cin >> file;
	ifstream inputfile;
	inputfile.open(file.c_str());
	inputfile >> temp;
	cash_balance += temp;
	while (!inputfile.eof())
	{
		inputfile >> name >> color >> price;
		inventory.push_back(Car(name, color, price));
	}
}
//loads in file to program
void SaveFile(vector<Car>& inventory, string& file, double& cash_balance)
{
	cout << "Input file name." << endl;
	cin >> file;
	ofstream outFile;
	outFile.open(file.c_str());
	outFile << cash_balance << endl;
	for (int i = zero; i < inventory.size(); i++)
	{
		if (i < inventory.size()-1)
		{
			outFile << fixed << setprecision(2) << setw(10) << inventory[i].getName() << setw(10) << inventory[i].getColor() << setw(10) << inventory[i].getPrice();
			outFile << endl;
		}
		else
		{
			outFile << fixed << setprecision(2) << setw(10) << inventory[i].getName() << setw(10) << inventory[i].getColor() << setw(10) << inventory[i].getPrice();
		}
	}
	outFile.close();
	//exports to text file
}

int main()
{
	double cash_balance = 10000.00;
	int menuinput = 0;
	string file;
	string name;
	string color;
	double price = 0;
	double temp = 0;
	vector<Car> inventory;
	//main variables
	do
	{
		cout << "Crazy Jimmy's Bargain-priced Pre-owned Pinto Emporium" << endl
			<< "1: Show Current Inventory" << endl
			<< "2: Show Current Balance" << endl
			<< "3: Buy a Car" << endl
			<< "4: Sell a Car" << endl
			<< "5: Paint a Car" << endl
			<< "6: Load File" << endl
			<< "7: Save File" << endl
			<< "8: Quit program" << endl;
		cin >> menuinput;
		switch (menuinput)
		{
		case 1:
			DisplayInventory(inventory);
			break;
		case 2:
			cout << fixed << setprecision(2) << "$" << cash_balance << endl;
			break;
		case 3:
			BuyCar(inventory, cash_balance, name, color, price);
			break;
		case 4:
			SellCar(inventory, cash_balance, name, color, price);
			break;
		case 5:
			PaintCar(inventory, cash_balance, name, color, price);
			break;
		case 6:
			LoadFile(inventory, file, cash_balance, name, color, price, temp);
			break;
		case 7:
			SaveFile(inventory, file, cash_balance);
			break;
		case 8:
			break;
		default:
			cout << "Invalid Selection !!!" << endl;
			break;
		}
	} while (menuinput != 8);
	// shows menu

	system("pause");
	return 0;
}