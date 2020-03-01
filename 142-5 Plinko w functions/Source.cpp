#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

/*Test cases
single chip		row 5 path: 5 5.5 5 4.5 5 4.5 5 4.5 4 4.5 4 3.5 4	winnings $10000
multiple chips	231 chips	row2	winnings $404200		average $1749.78
single chip		row -2	invalid
*/
const double prize1 = 100.00;
const double prize2 = 500.00;
const double prize3 = 1000.00;
const double prize4 = 0.00;
const double prize5 = 10000.00;
const double step = .5;
const int slot0 = 0;
const int slot1 = 1;
const int slot2 = 2;
const int slot3 = 3;
const int slot4 = 4;
const int slot5 = 5;
const int slot6 = 6;
const int slot7 = 7;
const int slot8 = 8;
const int finalrow = 12;
const int row1 = 1;
const int even = 0;
const int odd = 1;
const int divisor = 2;
const int chips1 = 1;

int Winnings(int total, int slot)
{
	int winnings = 0;

	if (slot == slot0 || slot == slot8)
	{
		winnings = prize1;
	}
	else if (slot == slot1 || slot == slot7)
	{
		winnings = prize2;
	}
	else if (slot == slot2 || slot == slot6)
	{
		winnings = prize3;
	}
	else if (slot == slot3 || slot == slot5)
	{
		winnings = prize4;
	}
	else if (slot == slot4)
	{
		winnings = prize5;
	}
	total = total + winnings;
	//multiple chip winnings
	return total;
}
int SingleChip(double slot, double step)
{
	int single_chip = 0;
	cout << "*** DROP SINGLE CHIP ***" << endl;
	cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
	cin >> slot;
	if (cin.fail())
	{
		//menuinput = 0;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	
	
	else if (slot >= slot0 && slot <= slot8)
	{
		cout << "*** DROPPING CHIP INTO SLOT " << slot << "***" << endl;
		cout << "PATH: [";
		cout << slot;
		for (int row = row1; row <= finalrow; row++)
		{
			int r = rand();
			if (slot == slot0)
			{
				slot = slot + step;
			}
			else if (slot == slot8)
			{
				slot = slot - step;
			}
			else if (r % divisor == even)
			{
				slot = slot - step;
			}
			else if (r % divisor == odd)
			{
				slot = slot + step;
			}
			cout << " " << slot;
		}
		cout << "]" << endl;

		int total = 0;
		total = Winnings(total, slot);
		cout << "WINNINGS: $" << total << endl;
		return slot;
	}


	else if (slot < slot0 || slot > slot8)
	{
		cout << "INVALID SLOT." << endl;
	}
}

void MultipleChips(double slot, int& chips)
{
		int totalrunning = 0;
		int start_slot = slot;

		for (int j = chips1; j <= chips; j++)
		{
			slot = start_slot;
			for (int row = row1; row <= finalrow; row++)
			{
				int r = rand();
				if (slot == slot0)
				{
					slot = slot + step;
				}
				else if (slot == slot8)
				{
					slot = slot - step;
				}
				else if (r % divisor == even)
				{
					slot = slot - step;
				}
				else if (r % divisor == odd)
				{
					slot = slot + step;
				}
			}
			totalrunning += Winnings(0, slot);
		}
		cout << "TOTAL WINNINGS ON " << chips << " CHIPS: $" << totalrunning << endl;
		totalrunning = totalrunning / chips;
		cout << fixed << setprecision(2);
		cout << "AVERAGE WINNINGS PER CHIP: $" << totalrunning << endl;	
}

int main()
{
	srand(time(0));
	int menuinput = 0;
	while (menuinput != 4)
	{
		cout << "MENU: Please select one of the following options:" << endl;
		cout << "1 - Drop a single chip into one slot" << endl;
		cout << "2 - Drop multiple chips into one slot" << endl;
		cout << "3 - Drop a number of chips into each slot" << endl;
		cout << "4 - Quit the program" << endl;
		cout << "Enter your selection now: " << endl;
		cin >> menuinput;
		//menu

		if (cin.fail())
		{
			menuinput = 0;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		double slot = 0;
		double start_slot = 0;
		int row = 0;
		int chips = 0;
		int chips0 = 0;
		double total = 0;
		//variables

		if (menuinput == 1)
		{
			int single_chip = SingleChip(slot, step);
		}
		//single chip

		else if (menuinput == 2)
		{
			cout << "*** DROP MULTIPLE CHIPS ***" << endl;
			cout << "How many chips do you want to drop (>0)?" << endl;
			cin >> chips;
			if (cin.fail())
			{
				menuinput = 0;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			if (chips <= chips0)
			{
				cout << "INVALID NUMBER OF CHIPS" << endl;
			}
			else
			{
				cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
				cin >> slot;
				if (cin.fail())
				{
					menuinput = 0;
					cin.clear();
					cin.ignore(1000, '\n');
				}
				else if (slot >= slot0 && slot <= slot8)
				{
					cout << "*** DROPPING CHIPS INTO SLOT " << slot << "***" << endl;
					int totalrunning = 0;
					MultipleChips(slot, chips);
				}
				else if (slot < slot0 || slot > slot8)
				{
					cout << "INVALID SLOT." << endl;
				}
			}
		}
		else if (menuinput == 3)
		{
			
			cout << "*** DROP MULTIPLE CHIPS ***" << endl;
			cout << "How many chips do you want to drop (>0)?" << endl;
			cin >> chips;
			if (cin.fail())
			{
				menuinput = 0;
				cin.clear();
				cin.ignore(1000, '\n');
			}
			else if (chips <= chips0)
			{
				cout << "INVALID NUMBER OF CHIPS" << endl;
			}
			else
			{
				int totalrunning = 0;
				for (slot = slot0; slot <= slot8; slot++)
				{
					cout << "*** DROPPING CHIPS INTO SLOT " << slot << "***" << endl;
					MultipleChips(slot, chips);
				}
			}
		}
		// multiple chips in one slot

		else if (menuinput < 1 || menuinput > 4)
		{
			cout << "INVALID SELECTION.  Please enter 1, 2, 3, or 4." << endl;
		}
	}
	if (menuinput == 4)
	{
		cout << "GOODBYE!" << endl;
	}

	//exits program
	system("pause");
	return 0;
}