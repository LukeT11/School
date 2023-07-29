//Luke Talcott
//CS201
//3/09/19
//Assignment 3

#include <iostream>
#include "string"
#include <cstdlib>
#include <iomanip>
#include "Assignment.h"
using namespace std;

//Main function to create a calendar off the year and starting day unless year is out of range. If out of range, program rejects it and ends.
int main() { //Variables used.
	int year;
	int startDay;
	int dayLastMonthEnded = 0;
	int i;

	//Calls GetYear() functonto receive year calendar is being created for and assigns it to variable year.
	year = GetYear();

	if (year < 1000 || year > 9999) { // If year not in specified range of 1000 to 9999, then program rejects with a message and terminates it. 
		cout << "Input not valid. Cannot compute calendar for entered input." << endl;
		system ("Pause");
		return 1;
	}
	//Calls function GetStartDayNumber() for what day of the week the year will begin on and assigns it to startDay.
	startDay = GetStartDayNumber();

	for (i = 0; i < 12; i++) { //Loops 12 times in order to call the function 12 times to create the 12 different months in a year and takes arguments of month number, year and day the month starts on for month it is creating.
		PrintOneMonth(i, year, startDay);
	}

	system("Pause");
	return 0;
}