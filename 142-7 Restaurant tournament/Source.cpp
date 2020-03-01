#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

/*Test cases
current initialized restauraunts, shuffle, 1,1,2,2,1,2,2, winner is Dairy Queen
add input Pdq for new restaurant, start tournament, invalid size is not 2^n
remove Subway and Dairy Queen, add Qdoba's and Panera, shuffle, 1,2,1,2,1,2,1, winner is Cafe Rio
*/

const int NOT_FOUND = -1;
const int hundred = 100;
const int zero = 0;
const int two = 2;
const int one = 1;

void DisplayRestaurants(vector<string> list)
{
	for (int i = zero; i < list.size() - 1; i++)
	{
		cout << list[i] << ", ";
	}
	cout << list[list.size() - 1] << endl;
}
//display bracket

void ShuffleRestaurants(vector<string>& list)
{
	int largeNumber = hundred * list.size();
	for (int iteration = zero; iteration < largeNumber; iteration++)
	{
		int index1 = rand() % list.size();
		int index2 = rand() % list.size();
		string temp = list[index1];
		list[index1] = list[index2];
		list[index2] = temp;
	}
}
//shuffle bracket

int findRestaurants(vector<string> restaurants, string restaurant)
{
	for (int i = zero; i < restaurants.size(); i++)
	{
		if (restaurants[i] == restaurant)
		{
			return i;
		}
	}
	return NOT_FOUND;
}
//check if restaurant is in bracket

void AddRestaurant(vector<string>& restaurants, string& restaurant)
{
	cout << "Select a restaurant to add: " << endl;
	cin.sync();
	getline(cin, restaurant);
	int index = findRestaurants(restaurants, restaurant);
	if (index == NOT_FOUND)
	{
		restaurants.push_back(restaurant);
	}
	else if (index != NOT_FOUND)
	{
		cout << "Invalid Entry.  Already in Bracket." << endl;
	}
}
// adds a restaurant

void removeRestaurants(vector<string>& restaurants, string& restaurant)
{
	
	cin.sync();
	getline(cin, restaurant);
	int index = findRestaurants(restaurants, restaurant);
	if (index == NOT_FOUND)
	{
		cout << "Invalid Choice" << endl;
	}
	else if (index != NOT_FOUND)
	{
		restaurants.erase(restaurants.begin() + index);
	}
}
//removes restaurant

string Tournament(vector<string> restaurants)
{
	double n = log2(restaurants.size());
	int remainder = n;
	if (n - remainder > zero)
	{
		cout << "Invalid!  Size is not 2^n." << endl;
		return "empty";
	}
	else
	{
		vector<string> winner;
		int input = 0;
		int round = 1;
		while (restaurants.size() > one)
		{
			int match = restaurants.size() / two;
			for (int i = zero; i < restaurants.size(); i +=two)
			{
				cout << "Match: " << (i/two) + one << "/"<< match << " Round: "<< round << "/" << remainder << endl;
				cout << "Choose a restaurant: 1:" << restaurants[i] << " or 2: " << restaurants[i + one] << endl;
				cin.sync();
				cin >> input;
				while (input != one && input != two)
				{
					cin.fail();
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Invalid entry.  Type 1 or 2!" << endl;
					cin >> input;
				}
				if (input == one)
				{
					winner.push_back(restaurants[i]);
				}
				else if (input == two)
				{
					winner.push_back(restaurants[i+1]);
				}
			}
			round++;
			restaurants = winner;
			winner.clear();
		}
		return restaurants[0];
	}
}
//runs tournament

int main()
{
	srand(time(0));
	vector<string> restaurants = { "Wendy's", "Taco Bell", "Cafe Rio", "Subway", "Applebee's", "Red Robin", "Outback Steakhouse", "Dairy Queen" };
	string restaurant;
	int menuinput = 0;
	do
	{
		cout << "Welcome to the Restaurant Tournament" << endl
			<< "1: Display all restaurants" << endl
			<< "2: Add a restaurant" << endl
			<< "3: Remove a Restaurant" << endl
			<< "4: Shuffle the bracket" << endl
			<< "5: Begin tournament" << endl
			<< "6: Quit program" << endl;
		cin >> menuinput;
		switch (menuinput)
		{
		case 1:
			DisplayRestaurants(restaurants);
			break;
		case 2:
			AddRestaurant(restaurants, restaurant);
			break;
		case 3:
			cout << "Select a restaurant to remove: " << endl;
			removeRestaurants(restaurants, restaurant);
			break;
		case 4:
			ShuffleRestaurants(restaurants);
			break;
		case 5:
			restaurant = Tournament(restaurants);
				if (restaurant == "empty")
				{
					break;
				}
				else
				{
					cout << endl;
					cout << "The Winner is: " << endl;
					cout << restaurant << endl;
					// displays winner
					system("pause");
					return 0;
				}
		case 6: break;
		default:
			cout << "Invalid Selection !!!" << endl;
		}
	} while (menuinput != 6);
	// shows menu

	system("pause");
	return 0;
}