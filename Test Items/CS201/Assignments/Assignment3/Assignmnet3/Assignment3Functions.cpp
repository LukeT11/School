//Luke Talcott
//CS201
//3/09/19
//Assignment 3

#include <iostream>
#include "string"
#include "Assignment.h"
using namespace std;
#include <cmath>

void PrintOneMonth(int monthNumber, int year, int &startDayNumber) { //No requirements to call function. Takes 3 paramters of month number, year and start day for that month. Calls DaysPerMonth() to get number of days in month.Overall, displays the the days and date for that month for a calendar.
	const int numElements = 12;
	string months[numElements] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER" };
	string weekDay[numElements] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	int daysInMonth;
	int i;

	daysInMonth = DaysPerMonth(monthNumber, year);

	cout << setw((56 - (months[monthNumber].length() + 5)) / 2) << right << months[monthNumber] << " "<< year << endl;

	for (i = 0; i < numElements; i++) {
		cout << setw(8) << left << weekDay[i];
	}

	cout << endl;

	cout << setw((startDayNumber) * 8) << " ";

	for (i = 1; i <= daysInMonth; i++) {
		cout << setw(8) << left << i;
		++startDayNumber;

		if (startDayNumber % 7 == 0) {
			cout << endl;
			startDayNumber = 0;
		}
	}

	cout << "\n" << endl;
}

int DaysPerMonth(int monthNumber, int year) { //No requirements to call functions. Called in the PrintOneMonth() function. Checks what month it is and returns how many days are in that month. If Februrary, checks if it is a leap year. Else, its 31 or 30 days depenending on even or odd month divided by two.
	int daysInMonth;

	if (monthNumber == 1) {
		if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)) {
			daysInMonth = 29;
		}

		else {
			daysInMonth = 28;
		}
	}
	
	else {
		if ((monthNumber + 1) % 2 == 0) {
			daysInMonth = 30;
		}

		else if ((monthNumber + 1) % 2 == 1) {
			daysInMonth = 31;
		}
	}

	return daysInMonth;
}

int GetStartDayNumber() { //No requirements for call function. While loop to continue to ask user for what day of the week January 1st falls on in that year until valid answer is given and then returns it. If wrong, it throws and catches it displaying an error.
	const int numElements = 7;
	string weekDay[numElements] = {"SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY", "SATURDAY"};
	string day;
	int lengthWeekDay;
	int i;

	while (true) {
		try {
			cout << "What day of the week does Jan 1 fall on this year? ";
			cin >> day;
			lengthWeekDay = day.length();

			for (i = 0; i < lengthWeekDay; i++) {
				day[i] = toupper(day[i]);
			}

			cout << endl;

			for (i = 0; i < numElements; i++) {
				if (day == weekDay[i]) {
					return i;
				}
			}

			throw runtime_error("");
		}

		catch (runtime_error) {
			cout << "Not acceptable day. Enter valid day. Make sure spelling is correct.\n" << endl;
			day = " "; 
		}
	}
}

int GetYear() { //No requirements for call. Asks user for year in the range 1000 and 9999 and returns it.
	int year = 0;

	cout << "Enter year (must be in range 1000 <= Year <= 9999): ";
	cin >> year;
	cout << endl;

	return year;
}