// Luke Talcott
// ldt9gn@mail.umkc.edu
// 3/6/19
// CS201L Lab 07

//#include "lab07.h";

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

//All functions used in lab07 program.

double GetMiles() {//While the loop is still set to yes, asks user for input of miles and checks to make sure the input is valid. If yes, returns the number. If not, it throws an error with a reason.
	double number;

	cout << "Enter number of miles: ";
	cin >> number;
	cout << endl;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>:: max(), '\n');
		throw runtime_error("Invalid input received, you must enter a decimal number.");
	}

	if (number <= 0) {
		throw runtime_error("Miles cannot be less than 0");
	}

	return number;
}

double GetGallons() {//While the loop is still set to yes, asks user for input of gallons and checks to make sure the input is valid. If yes, returns the number. If not, it throws an error with a reason.
	double number;

	cout << "Enter number of gallons: ";
	cin >> number;
	cout << endl;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw exception("Invalid input received, you must enter a decimal number.");
	}

	if (number <= 0) {
		throw exception("Gallons cannot be less than 0.");
	}

	return number;
}

double GetMPG(vector<double> &miles, vector<double> &gallons) {//When the user is done entering the tanks and while loop breaks, calculates the miles per gallon using the vertexs miles and gallons and returns the value. If the vertex's are empty, then it throws an error.

	double totalMiles = 0;
	double totalGallons = 0;
	double total;
	int i;

	if (miles.size() == 0) {
		throw runtime_error("Vertex's are empty");
	}

	for (i = 0; i < miles.size(); i++) {
		totalMiles += miles.at(i);
	}

	for (i = 0; i < gallons.size(); i++) {
		totalGallons += gallons.at(i);
	}

	total = totalMiles / totalGallons;

	return total;
}