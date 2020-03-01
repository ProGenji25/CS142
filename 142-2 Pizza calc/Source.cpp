# include <iostream>
# include <cmath>
# include <iomanip>
using namespace std;

int main()
{
	//Use inputs 25, 19, 37
	cout << "How many guests are attending?:\n";
	int guests;
	cin >> guests;
	//Inputs number of guests

	const int large = 7;
	int tot_l = guests / large;
	cout << tot_l << " large pizzas" << endl;
	//Determines how many large pizzas needed

	const int medium = 3;
	int guests_m = guests % large;
	int tot_m = guests_m / medium;
	cout << tot_m << " medium pizzas" << endl;
	// Determines how many medium pizzas needed

	const int small = 1;
	int guests_s = guests_m % medium;
	int tot_s = guests_s / small;
	cout << tot_s << " small pizzas" << endl;
	// Determines how many small pizzas needed

	const double PI = 3.14159;
	const double rad_l = 10;
	const double rad_m = 8;
	const double rad_s = 6;
	double tot_area_l = (tot_l * PI * pow(rad_l, 2));
	double tot_area_m = (tot_m * PI * pow(rad_m, 2));
	double tot_area_s = (tot_s * PI * pow(rad_s, 2));
	double tot_area_pizza = tot_area_l + tot_area_m + tot_area_s;
	cout << tot_area_pizza << " square inches of pizza" << endl;
	// Gives the total area of pizzas bought

	double area_per_guest = tot_area_pizza / guests;
	cout << area_per_guest << " square inches per guest" << endl;
	// Gives amount of pizza per guest

	//Use inputs 8, 10, 14
	cout << "What percent of the total price will be paid as a tip?: \n";
	double tip;
	cin >> tip;
	//Inputs tip percentage

	const double cost_l = 14.68;
	const double cost_m = 11.48;
	const double cost_s = 7.28;
	double tot_cost_l = cost_l * tot_l;
	double tot_cost_m = cost_m * tot_m;
	double tot_cost_s = cost_s * tot_s;
	double tot_cost = tot_cost_l + tot_cost_m + tot_cost_s;
	tot_cost = tot_cost + (tot_cost * tip / 100);
	cout << fixed << setprecision(0);
	cout << "$" << tot_cost << endl;

	/*
	guests	tip		expected large	actual large	expected medium		actual medium	expected small	actual small	expected area	 actual area	expected area/person	actual area/person	expected cost	actual cost
	19		8		2				2				1					1				2				2				1055.57			1055.57				55.5565					55.5565					$60			$60
	25		10		3				3				1					1				1				1				1256.64			1256.64				50.2654					50.2654					$69			$69
	37		14		5				5				0					0				2				2				1796.99			1796.99				48.5673					48.5673					$100		$100
	*/


	system("pause");
	return 0;
}