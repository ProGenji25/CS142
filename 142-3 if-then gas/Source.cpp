#include <iostream>
#include <string>
using namespace std;

/*
Test cases
miles per year	gas price	hybrid initial cost		hybrid mpg	hybrid resale	car initial cost	car mpg		car resale	preference	expected position	actual position	
100000			$1.50		$35000					36			$25000			$30000				25			$20000		Gas			Hybrid				Hybrid
50000			$3.00		$30000					33			$20000			$25000				27			$15000		Total		Hybrid				Hybrid
75000			$2.00		$25000					30			$15000			$20000				38			$10000		Gas			Non-Hybrid			Non-Hybrid

expected hybrid gallons		actual hybrid gallons	expected hybrid cost	actual hybrid cost	expected non-hybrid gallons		actual non-hybrid gallons	expected non-hybrid cost	actual non-hybrid cost
13888.9						13888.9					$30833.33				$30833.33			20000							20000						$40000						$40000
7575.76						7575.76					$32727.27				$32727.27			9259.26							9259.26						$37777.78					$37777.78
12500						12500					$35000					$35000				9868.42							9868.42						$29736.84					$29736.84
*/
int main()
{
	double miles_per_year;
	double gas_price;
	double hybrid_cost;
	double hybrid_mpg;
	double hybrid_resale;
	double car_cost;
	double car_mpg;
	double car_resale;
	string preference;
	//user variables

	cout << "Estimated miles driven per year: ";
	cin >> miles_per_year;
	if (miles_per_year <= 0)
	{
		cout << "Only positive numbers accepted.  Please enter again." << endl;
		cin >> miles_per_year;
	}
	cout << "Estimated gas price during 5 years: ";
	cin >> gas_price;
	if (gas_price <= 0)
	{
		cout << "Only positive numbers accepted.  Please enter again." << endl;
		cin >> gas_price;
	}
	cout << "Initial cost of a hybrid car: ";
	cin >> hybrid_cost;
	if (hybrid_cost <= 0)
	{
		cout << "Only positive numbers accepted.  Please enter again." << endl;
		cin >> hybrid_cost;
	}
	cout << "Miles per gallon for hybrid: ";
	cin >> hybrid_mpg;
	if (hybrid_mpg <= 0)
	{
		cout << "Only positive numbers accepted.  Please enter again." << endl;
		cin >> hybrid_mpg;
	}
	cout << "Estimated hybrid resale value after 5 years: ";
	cin >> hybrid_resale;
	if (hybrid_resale <= 0)
	{
		cout << "Only positive numbers accepted.  Please enter again." << endl;
		cin >> hybrid_resale;
	}
	cout << "Initial cost of non-hybrid car: ";
	cin >> car_cost;
	if (car_cost <= 0)
	{
		cout << "Only positive numbers accepted.  Please enter again." << endl;
		cin >> car_cost;
	}
	cout << "Miles per gallon for non-hybrid car: ";
	cin >> car_mpg;
	if (car_mpg <= 0)
	{
		cout << "Only positive numbers accepted.  Please enter again." << endl;
		cin >> car_mpg;
	}
	cout << "Estimated non-hybrid car resale value after 5 years: ";
	cin >> car_resale;
	if (car_resale <= 0)
	{
		cout << "Only positive numbers accepted.  Please enter again." << endl;
		cin >> car_resale;
	}
	cout << "Minimized gas consumption or minimized total cost?: ";
	cin >> preference;
	
	//user input for both cars and reprompts if less than or equal to 0

	const int years = 5;
	double tot_miles;
	double hybrid_gallons;
	double hybrid_fuel_cost;
	double hybrid_depreciation;
	double tot_hybrid_cost;
	tot_miles = miles_per_year * years;
	hybrid_gallons = tot_miles / hybrid_mpg;
	hybrid_fuel_cost = hybrid_gallons * gas_price;
	hybrid_depreciation = hybrid_cost - hybrid_resale;
	tot_hybrid_cost = hybrid_depreciation + hybrid_fuel_cost;
	// Finds total hybrid cost

	double car_gallons;
	double car_fuel_cost;
	double car_depreciation;
	double tot_car_cost;
	car_gallons = tot_miles / car_mpg;
	car_fuel_cost = car_gallons * gas_price;
	car_depreciation = car_cost - car_resale;
	tot_car_cost = car_depreciation + car_fuel_cost;
	// Finds total car cost

	if (preference == "Gas")
	{
		if (hybrid_gallons < car_gallons)
		{
			cout << "Hybrid" << endl;
			cout << hybrid_gallons << " gallons of gas consumed" << endl;
			cout << "$" << tot_hybrid_cost << endl;
			cout << "Non-Hybrid" << endl;
			cout << car_gallons << " gallons of gas consumed" << endl;
			cout << "$" << tot_car_cost << endl;
		}
		else if (hybrid_gallons > car_gallons)
		{
			cout << "Non-Hybrid" << endl;
			cout << car_gallons << "gallons of gas consumed" << endl;
			cout << "$" << tot_car_cost << endl;
			cout << "Hybrid" << endl;
			cout << hybrid_gallons << " gallons of gas consumed" << endl;
			cout << "$" << tot_hybrid_cost << endl;
		}
	}
	else if (preference == "Total")
	{
		if (tot_hybrid_cost < tot_car_cost)
		{
			cout << "Hybrid" << endl;
			cout << hybrid_gallons << " gallons of gas consumed" << endl;
			cout << "$" << tot_hybrid_cost << endl;
			cout << "Non-Hybrid" << endl;
			cout << car_gallons << "gallons of gas consumed" << endl;
			cout << "$" << tot_car_cost << endl;
		}
		else if (tot_hybrid_cost > tot_car_cost)
		{
			cout << "Non-Hybrid" << endl;
			cout << car_gallons << "gallons of gas consumed" << endl;
			cout << "$" << tot_car_cost << endl;
			cout << "Hybrid" << endl;
			cout << hybrid_gallons << " gallons of gas consumed" << endl;
			cout << "$" << tot_hybrid_cost << endl;
		}
	}
	// Gives final gas and cost for both cars based on preference




	system("pause");
	return 0;
}