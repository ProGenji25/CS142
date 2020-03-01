
#include <string>
#include <iostream>

const int MAXIMUM_LIST_SIZE = 100;

using namespace std;

void add_item(string grocery_list[], int& current_list_size, string& grocery_item)
{
	if (current_list_size < MAXIMUM_LIST_SIZE)
	{
		current_list_size++;
		grocery_list[current_list_size - 1] = grocery_item;
	}
}
// add item function
void display_list(string grocery_list[], int current_list_size)
{
	cout << "----------------" << endl;
	for (int i = 0; i < current_list_size; i++)
	{
		cout << grocery_list[i] << endl;
	}
	cout << "----------------" << endl;
}
//display grocer list function
string get_item_name(string grocery_list[], int current_list_size, int index)
{
	if (index < current_list_size && index >= 0)
	{
		return grocery_list[index];
	}
	else
	{
		return "INVAILD INDEX";
	}
}
//function to show item name in index
string find_longest(string grocery_list[], int current_list_size)
{
	string longest;
	for (int i = 0; i < current_list_size; i++)
	{
		int n = grocery_list[i].length();
		int l = grocery_list[i-1].length();
		if (n > l)
		{
			longest = grocery_list[i];
		}
		else if (n = l)
		{
			longest = longest;
		}
	}
	return longest;
}
//find longest item in list function
void swap_items(string grocery_list[], int& current_list_size, int& i1, int& i2)
{
	if (i1 >= 0 && i1 < current_list_size && i2 >= 0 && i2 < current_list_size)
	{
		string temp = grocery_list[i1];
		grocery_list[i1] = grocery_list[i2];
		grocery_list[i2] = temp;
	}
	else
	{
		cout << "INVAILID INDEX" << endl;
	}
}
//function for swapping two items in a list
void remove_item(string grocery_list[], int& current_list_size, string& grocery_item)
{
	int position = 0;
	bool found = false;
	while (position < current_list_size && !found)
	{
		if (grocery_list[position] == grocery_item)
		{
			found = true;
		}
		else
		{
			position++;
		}
	}
	for (int i = position + 1; i < current_list_size; i++)
	{
		grocery_list[i - 1] = grocery_list[i];
	}
	current_list_size--;
}
// function for removing item from list
int main() //DO NOT CHANGE THIS FUNCTION (EXCEPT TO COMMENT OR UNCOMMENT VARIOUS SECTIONS)
{
	string input;
	string grocery_list[MAXIMUM_LIST_SIZE];
	int current_list_size = 0;

	cout << "**********************************************************" << endl;
	cout << "GROCERY LIST.CPP" << endl;
	cout << "**********************************************************" << endl;
	cout << endl;
	cout << "This program accepts the following commands: " << endl << endl;
	cout << "add [item name]: adds an item to the list" << endl;
	cout << "remove [item name]: removes an item from the list" << endl;
	cout << "display: shows the contents of the list" << endl;
	cout << "show [index]: shows the contents of list[index]" << endl;
	cout << "longest: outputs the list item with the most letters" << endl;
	cout << "swap [index 1] [index 2]: swaps the location of two items" << endl;
	cout << "quit: exits the program" << endl;
	cout << endl;
	cout << "Please enter a command." << endl << endl;

	while (input != "quit") {
		cin >> input;

		if (input == "add") {
			string grocery_item;
			getline(cin, grocery_item);
			grocery_item = grocery_item.substr(1, grocery_item.length() - 1); //removes leading space
			add_item(grocery_list, current_list_size, grocery_item);	//add grocery_item to the grocery_list array
			//(You may assume that the user will never add more items
			//than the array can comfortably hold.)
		}

		if (input == "display") display_list(grocery_list, current_list_size);	//display the grocery list, one item per line,
		//with a row of hyphens above and below the list

		if (input == "show") {
			int index;
			cin >> index;
			cout << get_item_name(grocery_list, current_list_size, index) << endl;	//get_item_name() returns the string content 
			//of the item stored in position index. If
			//the index is invalid, return "INVALID INDEX"
		}

		if (input == "longest") cout << find_longest(grocery_list, current_list_size) << endl;	//find_longest() returns the string content of 
		//the list item with the most letters. If there is
		//a "tie" between two or more words, the function should
		//return the first one found.

		/*EXTRA CREDIT #1*/
		if (input == "swap") {
		int i1, i2;
		cin >> i1 >> i2;
		swap_items(grocery_list, current_list_size, i1, i2);	//swaps the position of the items at locations i1 and i2.
		//If either location is invalid, output "INVALID INDEX"
		//followed by a new line.
		}

		/*EXTRA CREDIT #2*/
		if (input == "remove") {
		string grocery_item;
		getline(cin, grocery_item);
		grocery_item = grocery_item.substr(1, grocery_item.length() - 1); //removes leading space
		remove_item(grocery_list, current_list_size, grocery_item);	//remove this item from the grocery_list array without
		//changing the order of the other items on the list.
		//If the item to be deleted is not on the list,
		//output "ITEM NOT FOUND" followed by a new line.
		}

		cout << endl;
	}

	return 0;
}

