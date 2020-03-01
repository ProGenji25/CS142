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
int main()
{
	srand(time(0));
	int menuinput = 0;
	while (menuinput != 3)
	{
		cout << "MENU: Please select one of the following options:" << endl;
		cout << "1 - Drop a single chip into one slot" << endl;
		cout << "2 - Drop multiple chips into one slot" << endl;
		cout << "3 - Quit the program" << endl;
		cout << "Enter your selection now: " << endl;
		cin >> menuinput;
		//menu

		double slot = 0;
		double start_slot = 0;
		int row = 0;
		int chips = 0;
		const double prize1 = 100.00;
		const double prize2 = 500.00;
		const double prize3 = 1000.00;
		const double prize4 = 0.00;
		const double prize5 = 10000.00;
		const double step = .5;
		double total = 0;
		int winnings = 0;
		const int slot0 = 0;
		const int slot1 = 1;
		const int slot2 = 2;
		const int slot3 = 3;
		const int slot4 = 4;
		const int slot5 = 5;
		const int slot6 = 6;
		const int slot7 = 7;
		const int slot8 = 8;

		//variables

		if (menuinput == 1)
		{
			cout << "*** DROP SINGLE CHIP ***" << endl;
			cout << "Which slot do you want to drop the chip in (0-8)?" << endl;
			cin >> slot;
			cout << "*** DROPPING CHIP INTO SLOT" << slot << "***" << endl;
			if (slot >= slot0 && slot <= slot8)
			{
				cout << "PATH: [";
				cout << slot;
				for (int row = 1; row <= 12; row++)
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
					else if (r % 2 == 0)
					{
						slot = slot - step;
					}
					else if (r % 2 == 1)
					{
						slot = slot + step;
					}
					cout << " " << slot;
				}
				cout << "]" << endl;

				if (slot == slot0 || slot == slot8)
				{
					cout << "WINNINGS: $" << prize1 << endl;
				}
				else if (slot == slot1 || slot == slot7)
				{
					cout << "WINNINGS: $" << prize2 << endl;
				}
				else if (slot == slot2 || slot == slot6)
				{
					cout << "WINNINGS: $" << prize3 << endl;
				}
				else if (slot == slot3 || slot == slot5)
				{
					cout << "WINNINGS: $" << prize4 << endl;
				}
				else if (slot == slot4)
				{
					cout << "WINNINGS: $" << prize5 << endl;
				}

			}
			else if (slot < slot0 || slot > slot8)
			{
				cout << "INVALID SLOT." << endl;
			}
		}
		//single chip

		else if (menuinput == 2)
		{
			cout << "*** DROP MULTIPLE CHIPS ***" << endl;
			cout << "How many chips do you want to drop (>0)?" << endl;
			cin >> chips;
			if (chips <= 0)
			{
				cout << "INVALID NUMBER OF CHIPS" << endl;
			}
			else
			{
				cout << "Which slot do you want to drop the chips in (0-8)?" << endl;
				cin >> start_slot;

				if (start_slot >= slot0 && start_slot <= slot8)
				{
					for (int j = 1; j <= chips; j++)
					{
						slot = start_slot;

						for (int row = 1; row <= 12; row++)
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
							else if (r % 2 == 0)
							{
								slot = slot - step;
							}
							else if (r % 2 == 1)
							{
								slot = slot + step;
							}
						}
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
					}
					cout << "TOTAL WINNINGS ON " << chips << " CHIPS: $" << total << endl;
					total = total / chips;
					cout << fixed << setprecision(2);
					cout << "AVERAGE WINNINGS PER CHIP: $" << total << endl;
				}
				else if (slot < slot0 || slot > slot8)
				{
					cout << "INVALID SLOT." << endl;
				}
			}
		}
		// multiple chips
		else if (menuinput < 1 || menuinput > 3)
		{
			cout << "INVALID SELECTION.  Please enter 1, 2, or 3." << endl;
		}
	}
	if (menuinput == 3)
	{
		cout << "GOODBYE!" << endl;
	}
	
	//exits program
	system ("pause");
	return 0;
}