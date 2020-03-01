#include <iostream>

/*
Jordan Golden
Section 2
CS 142 Winter 2016 Midterm 1
*/


#include <cstdlib>
#include <string>
using namespace std;

int main()
{
	int greg_calendar_start = 1582;
	int startyear = 1582;
	int total_year1_days = 0;
	const int year_days = 365;
	const int leapyear_days = 366;
	const int leapyear = 4;
	const int leapcentury = 400;
	const int century = 100;
	const int firstday = 1;
	const int lastmonthday1 = 30;
	const int lastmonthday2 = 31;
	const int Febday = 28;
	const int Febleapday = 29;
	int Jandays = 0;
	int Febdays = 31;
	int Mardays = 59;
	int Aprdays = 90;
	int Maydays = 120;
	int Jundays = 151;
	int Juldays = 181;
	int Augdays = 212;
	int Sepdays = 243;
	int Octdays = 273;
	int Novdays = 304;
	int Decdays = 334;
	int total_month1_days = 0;
	const int leapday = 1;
	const int leap_remain_test = 0;
	string month;
	string day;
	string year;
	int total_days1 = 0;
	string monthb;
	string dayb;
	string yearb;
	int total_days2 = 0;
	int startyear2 = 1582;
	int total_year2_days = 0;
	const int year_days2 = 365;
	const int leapyear_days2 = 366;
	const int leapyear2 = 4;
	const int leapcentury2 = 400;
	const int century2 = 100;
	const int firstday2 = 1;
	const int lastmonthday1b = 30;
	const int lastmonthday2b = 31;
	const int Febday2 = 28;
	const int Febleapday2 = 29;
	int Jandays2 = 0;
	int Febdays2 = 31;
	int Mardays2 = 59;
	int Aprdays2 = 90;
	int Maydays2 = 120;
	int Jundays2 = 151;
	int Juldays2 = 181;
	int Augdays2 = 212;
	int Sepdays2 = 243;
	int Octdays2 = 273;
	int Novdays2 = 304;
	int Decdays2 = 334;
	int total_month2_days = 0;
	const int leapday2 = 1;
	int total_days = 0;
	const int singleday = 1;
	//Write ALL the variables!

	reprompt:
	cout << "Enter the first date: ";
	cin >> month >> day >> year;
		//input first date

	istream& getline(istream& in, string day);
	int day1 = atoi(day.substr(0, day.length() - 1).c_str());
	istream& getline(istream& in, string year);
	int year1 = atoi(year.substr(0, year.length()).c_str());
	//extract day and year substring to respective number value

	if (year1 < greg_calendar_start)
	{
		cout << "Invalid date" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		goto reprompt;
	}
	if (month != "January" && month != "February" && month != "March" && month != "April" && month != "May" && month != "June" && month != "July" && month != "August" && month != "September" && month != "October" && month != "November" && month != "December")
	{
		cout << "Invalid date" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		goto reprompt;		
	}
	if (day1 < firstday || day1 > lastmonthday2)
	{
		cout << "Invalid date" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		goto reprompt;
	}
	if (month == "January")
	{
		if (day1 < firstday || day1 > lastmonthday2)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "February" && year1 % leapyear == 0 && year1 % century == 0 && year1 % leapcentury > 0)
	{
		if (day1 < firstday || day1 > Febday)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "February" && year1 % leapyear > 0)
	{
		if (day1 < firstday || day1 > Febday)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "February" && year1 % leapyear == 0)
	{
		if (day1 < firstday || day1 > Febleapday)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "March")
	{
		if (day1 < firstday || day1 > lastmonthday2)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "April")
	{
		if (day1 < firstday || day1 > lastmonthday1)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "May")
	{
		if (day1 < firstday || day1 > lastmonthday2)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "June")
	{
		if (day1 < firstday || day1 > lastmonthday1)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "July")
	{
		if (day1 < firstday || day1 > lastmonthday2)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "August")
	{
		if (day1 < firstday || day1 > lastmonthday2)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "September")
	{
		if (day1 < firstday || day1 > lastmonthday1)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "October")
	{
		if (day1 < firstday || day1 > lastmonthday2)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "November")
	{
		if (day1 < firstday || day1 > lastmonthday1)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
	if (month == "December")
	{
		if (day1 < firstday || day1 > lastmonthday2)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt;
		}
	}
		
	/* Checks for valid dates.No implementation of if else loops, while loops, for loops, or do loops could get the program to return correctly to the prompt.  
		With the time I had this was the only way to return the program correctly and efficiently, and it works beautifully!*/

	
	if (year1 >= greg_calendar_start)
	{
		while (startyear < year1)
		{
			if (year1 % leapyear == leap_remain_test && startyear % century == leap_remain_test && startyear % leapcentury != leap_remain_test && startyear >= startyear)
			{
				total_year1_days = total_year1_days + year_days;
			}
			else if (startyear % leapyear == leap_remain_test)
			{
				total_year1_days = total_year1_days + leapyear_days;
			}
			else
			{
				total_year1_days = total_year1_days + year_days;
			}
			startyear++;

		}
	}
	// computes total days over period of years



	if (month == "January" || month == "February" || month == "March" || month == "April" || month == "May" || month == "June" || month == "July" || month == "August" || month == "September" || month == "October" || month == "November" || month == "December")
	{
		if (month == "January")
		{
			total_month1_days = Jandays;
		}
		else if (month == "February")
		{
			total_month1_days = Febdays;
		}
		else if (month == "March")
		{
			total_month1_days = Mardays;
		}
		else if (month == "April")
		{
			total_month1_days = Aprdays;
		}
		else if (month == "May")
		{
			total_month1_days = Maydays;
		}
		else if (month == "June")
		{
			total_month1_days = Jundays;
		}
		else if (month == "July")
		{
			total_month1_days = Juldays;
		}
		else if (month == "August")
		{
			total_month1_days = Augdays;
		}
		else if (month == "September")
		{
			total_month1_days = Sepdays;
		}
		else if (month == "October")
		{
			total_month1_days = Octdays;
		}
		else if (month == "November")
		{
			total_month1_days = Novdays;
		}
		else if (month == "December")
		{
			total_month1_days = Decdays;
		}
		if (year1 % leapyear == leap_remain_test && month != "January" && month != "February")
		{
			total_month1_days = total_month1_days + leapday;
		}
	}
	// computes past days before first day of the month

	if (day1 >= firstday && day1 <= lastmonthday2)
	{
		if (month == "January" && day1 >= firstday && day1 <= lastmonthday2)
		{
			day1 = day1;
		}
		else if (month == "February" && year1 % leapyear != 0 && day1 >= firstday && day1 <= Febday)
		{
			day1 = day1;
		}
		else if (month == "February" && year1 % leapyear == 0 && day1 >= firstday && day1 <= Febleapday)
		{
			day1 = day1;
		}
		else if (month == "March" && day1 >= firstday && day1 <= lastmonthday2)
		{
			day1 = day1;
		}
		else if (month == "April" && day1 >= firstday && day1 <= lastmonthday1)
		{
			day1 = day1;
		}
		else if (month == "May" && day1 >= firstday && day1 <= lastmonthday2)
		{
			day1 = day1;
		}
		else if (month == "June" && day1 >= firstday && day1 <= lastmonthday1)
		{
			day1 = day1;
		}
		else if (month == "July" && day1 >= firstday && day1 <= lastmonthday2)
		{
			day1 = day1;
		}
		else if (month == "August" && day1 >= firstday && day1 <= lastmonthday2)
		{
			day1 = day1;
		}
		else if (month == "September" && day1 >= firstday && day1 <= lastmonthday1)
		{
			day1 = day1;
		}
		else if (month == "October" && day1 >= firstday && day1 <= lastmonthday2)
		{
			day1 = day1;
		}
		else if (month == "November" && day1 >= firstday && day1 <= lastmonthday1)
		{
			day1 = day1;
		}
		else if (month == "December" && day1 >= firstday && day1 <= lastmonthday2)
		{
			day1 = day1;
		}
	}
	total_days1 = total_year1_days + total_month1_days + day1;
	//computes total days for first date

	reprompt2:
	cout << "Enter the second date: ";
	cin >> monthb >> dayb >> yearb;
	//input second date

	istream& getline(istream& in, string day);
	int day2 = atoi(dayb.substr(0, dayb.length() - 1).c_str());
	istream& getline(istream& in, string year);
	int year2 = atoi(yearb.substr(0, yearb.length()).c_str());
	//extract day and year substring to respective number value

	if (year2 < startyear2)
	{
		cout << "Invalid date" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		goto reprompt2;
	}
	if (monthb != "January" && monthb != "February" && monthb != "March" && monthb != "April" && monthb != "May" && monthb != "June" && monthb != "July" && monthb != "August" && monthb != "September" && monthb != "October" && monthb != "November" && monthb != "December")
	{
		cout << "Invalid date" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		goto reprompt2;
	}
	if (day2 < firstday2 || day2 > lastmonthday2b)
	{
		cout << "Invalid date" << endl;
		cin.clear();
		cin.ignore(10000, '\n');
		goto reprompt2;
	}
	if (monthb == "January")
	{
		if (day2 < firstday2 || day2 > lastmonthday2b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "February" && year2 % leapyear2 == leap_remain_test && year2 % century2 == leap_remain_test && year2 % leapcentury2 > leap_remain_test)
	{
		if (day2 < firstday2 || day2 > Febday2)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "February" && year2 % leapyear2 > leap_remain_test)
	{
		if (day2 < firstday2 || day2 > Febday2)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "February" && year2 % leapyear == leap_remain_test)
	{
		if (day2 < firstday2 || day2 > Febleapday2)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "March")
	{
		if (day2 < firstday2 || day2 > lastmonthday2b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "April")
	{
		if (day2 < firstday2 || day2 > lastmonthday1b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "May")
	{
		if (day2 < firstday2 || day2 > lastmonthday2b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "June")
	{
		if (day2 < firstday2 || day2 > lastmonthday1b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "July")
	{
		if (day2 < firstday2 || day2 > lastmonthday2b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "August")
	{
		if (day2 < firstday2 || day2 > lastmonthday2b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "September")
	{
		if (day2 < firstday2 || day2 > lastmonthday1b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "October")
	{
		if (day2 < firstday2 || day2 > lastmonthday2b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "November")
	{
		if (day2 < firstday2 || day2 > lastmonthday1b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	if (monthb == "December")
	{
		if (day2 < firstday2 || day2 > lastmonthday2b)
		{
			cout << "Invalid date" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			goto reprompt2;
		}
	}
	// This checks for valid dates. 

	if (year2 >= startyear2)
	{
		while (startyear2 < year2)
		{
			if (year2 % leapyear2 == leap_remain_test && startyear2 % century2 == leap_remain_test && startyear2 % leapcentury2 != leap_remain_test)
			{
				total_year2_days = total_year2_days + year_days;
			}
			else if (startyear2 % leapyear2 == leap_remain_test)
			{
				total_year2_days = total_year2_days + leapyear_days;
			}
			else
			{
				total_year2_days = total_year2_days + year_days;
			}
			startyear2++;
		}
	}
	// computes total days over period of years

	if (monthb == "January" || monthb == "February" || monthb == "March" || monthb == "April" || monthb == "May" || monthb == "June" || monthb == "July" || monthb == "August" || monthb == "September" || monthb == "October" || monthb == "November" || monthb == "December")
	{
		if (monthb == "January")
		{
			total_month2_days = Jandays2;
		}
		else if (monthb == "February")
		{
			total_month2_days = Febdays2;
		}
		else if (monthb == "March")
		{
			total_month2_days = Mardays2;
		}
		else if (monthb == "April")
		{
			total_month2_days = Aprdays2;
		}
		else if (monthb == "May")
		{
			total_month2_days = Maydays2;
		}
		else if (monthb == "June")
		{
			total_month2_days = Jundays2;
		}
		else if (monthb == "July")
		{
			total_month2_days = Juldays2;
		}
		else if (monthb == "August")
		{
			total_month2_days = Augdays2;
		}
		else if (monthb == "September")
		{
			total_month2_days = Sepdays2;
		}
		else if (monthb == "October")
		{
			total_month2_days = Octdays2;
		}
		else if (monthb == "November")
		{
			total_month2_days = Novdays2;
		}
		else if (monthb == "December")
		{
			total_month2_days = Decdays2;
		}
		if (year2 % leapyear == leap_remain_test && monthb != "January" && monthb != "February")
		{
			total_month2_days = total_month2_days + leapday2;
		}
	}
	// computes past days before first day of the month

	if (day2 >= firstday && day2 <= lastmonthday2)
	{
		if (monthb == "January" && day2 >= firstday && day2 <= lastmonthday2)
		{
			day2 = day2;
		}
		else if (monthb == "February" && year2 % leapyear != leap_remain_test && day2 >= firstday && day2 <= Febday)
		{
			day2 = day2;
		}
		else if (monthb == "February" && year2 % leapyear == leap_remain_test && day2 >= firstday && day2 <= Febleapday)
		{
			day2 = day2;
		}
		else if (monthb == "March" && day2 >= firstday && day2 <= lastmonthday2)
		{
			day2 = day2;
		}
		else if (monthb == "April" && day2 >= firstday && day2 <= lastmonthday1)
		{
			day2 = day2;
		}
		else if (monthb == "May" && day2 >= firstday && day2 <= lastmonthday2)
		{
			day2 = day2;
		}
		else if (monthb == "June" && day2 >= firstday && day2 <= lastmonthday1)
		{
			day2 = day2;
		}
		else if (monthb == "July" && day2 >= firstday && day2 <= lastmonthday2)
		{
			day2 = day2;
		}
		else if (monthb == "August" && day2 >= firstday && day2 <= lastmonthday2)
		{
			day2 = day2;
		}
		else if (monthb == "September" && day2 >= firstday && day2 <= lastmonthday1)
		{
			day2 = day2;
		}
		else if (monthb == "October" && day2 >= firstday && day2 <= lastmonthday2)
		{
			day2 = day2;
		}
		else if (monthb == "November" && day2 >= firstday && day2 <= lastmonthday1)
		{
			day2 = day2;
		}
		else if (monthb == "December" && day2 >= firstday && day2 <= lastmonthday2)
		{
			day2 = day2;
		}
	}
	//computes total days for first date

	total_days2 = total_year2_days + total_month2_days + day2;

	total_days = abs(total_days1 - total_days2);

	if (total_days == singleday)
	{
		cout << "There is " << total_days << " day between " << month << " " << day << " " << year << " and " << monthb << " " << dayb << " " << yearb << "." << endl;
	}
	else
	{
		cout << "There are " << total_days << " days between " << month << " " << day << " " << year << " and " << monthb << " " << dayb << " " << yearb << "." << endl;
	}

	// In all the test cases I performed in this iteration, the error range consistently stayed at 3 compared to the reference.
	system("pause");
	return 0;

}