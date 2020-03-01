#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


const int ROWS = 20;
const int COLUMNS = 20;
const int row0 = 0;
const int row1 = 1;
const int column0 = 0;
const int column1 = 1;
const int heat = 100;
const int ave = 4;
const int cold = 0;

void HotPlate(double initial_temp[ROWS][COLUMNS])
{
	for (int row = row0; row < ROWS; row++)
	{
		for (int column = column0; column < COLUMNS; column++)
		{
			initial_temp[row][column] = cold;

			if (row == row0 || row == ROWS - 1)
			{
				initial_temp[row][column] = heat;
			}
			
			if (column == column0 || column == COLUMNS - 1)
			{
				initial_temp[row][column] = cold;
			}
		}
	}
	// creates initial arrays
}

double Average(double initial_temp[ROWS][COLUMNS], double new_temp[ROWS][COLUMNS])
{
	double total_diff = 0;
	for (int row = row1; row < ROWS - 1; row++)
	{
		for (int column = column1; column < COLUMNS - 1; column++)
		{
			new_temp[row][column] = (initial_temp[row - 1][column] + initial_temp[row + 1][column] + initial_temp[row][column - 1] + initial_temp[row][column + 1]) / ave;
		}
	}
	//takes average
	for (int row = row1; row < ROWS - 1; row++)
	{
		for (int column = column1; column < COLUMNS - 1; column++)
		{
			double diff = abs(initial_temp[row][column] - new_temp[row][column]);
			if (diff > total_diff)
			{
				total_diff = diff;
			}
			initial_temp[row][column] = new_temp[row][column];
		}
	}
	// takes difference of old aray and new array and copies new array values into old array values
	return total_diff;
}

void PrintArray(double initial_temp[ROWS][COLUMNS])
{
	for (int row = row0; row < ROWS; row++)
	{
		for (int column = column0; column < COLUMNS; column++)
		{
			cout << fixed << setprecision(0) << setw(4) << initial_temp[row][column] << " ";
		}
		cout << endl;
	}
	//prints array
}

void ExportsArray(double new_temp[ROWS][COLUMNS])
{
	ofstream outFile;
	outFile.open("lab6output.csv");
	for (int row = row0; row < ROWS; row++)
	{
		for (int column = column0; column < COLUMNS; column++)
		{
			outFile << fixed << setprecision(1) << setw(4) << new_temp[row][column] << ",";
		}
		outFile << endl;
	}
	outFile.close();
	//exports to Excel file
}

int main()
{
	bool run = true;
	double large_diff = 0;
	double diff = 0;
	double small_diff = .1;
	double initial_temp[ROWS][COLUMNS];
	double new_temp[ROWS][COLUMNS];
	HotPlate(initial_temp);
	HotPlate(new_temp);
	PrintArray(initial_temp);
	cout << endl;
	Average(initial_temp, new_temp);
	PrintArray(new_temp);
	while (run == true)
	{
		
		large_diff = Average(initial_temp, new_temp);
		if (large_diff < small_diff)
		{
			run = false;
		}
		else
		{
			run = true;
		}	
	}
	//loops Average function untill stable
	ExportsArray(new_temp);
	system("pause");
	return 0;
}