//Luke Talcott
//2/9/2019
//CS201
//Program 2

#include <iostream>
#include "string"
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;

//All functions used and defintions.

char Menu() { //Runs everytime the while loop restarts back to the beginning. No preconditions/postconditions. Outputs a list of options to choose from and returns a chosen character.
	char key = ' ';
	
	cout << "1. Print all customers data" << endl;
	cout << "2. Print names and ID's" << endl;
	cout << "3. Print accounts total" << endl;
	cout << "4. Enter q/Q to quit " << endl;
	cout << "\nEnter your choice, or 'q' to quit: ";
	cin >> key;
	key = toupper(key);
	cout << endl;

	return key;
}

//If the char key equals 1, output a table with the customers data with their id, first and last name, savings account amount, and checking account amount. No return value.
void PrintCustomersData(const int id[], const string first[], const string last[], const double savings_Account[], const double checking_Account[], int size) {
	int i;

	cout << setw(10) << left << "ID";
	cout << setw(10) << left << "First";
	cout << setw(15) << left << "Last";
	cout << setw(20) << left << "Savings Account";
	cout << setw(20) << left << "Checking Account" << endl;

	for (i = 0; i < size; i++) {
		cout << setw(10) << left << id[i];
		cout << setw(10) << left << first[i];
		cout << setw(15) << left << last[i];
		cout << setw(20) << left << savings_Account[i];
		cout << setw(20) << left << checking_Account[i] << endl;
	}
}

//If the char key equals 2, output a table with the customers id, first name and last name. No return value.
void printNames(const int id[], const string first[], const string last[], int size) {
	int i;

	cout << setw(7) << left << "ID";
	cout << setw(10) << left << "First";
	cout << setw(15) << left << "Last" << endl;
	
	for (i = 0; i < size; i++) {
		cout << setw(7) << left << id[i];
		cout << setw(10) << left << first[i];
		cout << setw(15) << left << last[i] << endl;
	}
}

//If the char key equals 3, output a table with the customers id, savings account amount, checking account amount, and the total of the two accounts combined. No return value.
void printTotal(const int id[], const double savings_Account[], const double checking_Account[], int size) {
	int i;

	cout << setw(7) << left << "ID";
	cout << setw(20) << left << "Savings Account";
	cout << setw(20) << left << "Checking Account";
	cout << setw(10) << left << "Total" << endl;

	for (i = 0; i < size; i++) {
		cout << setw(7) << left << id[i];
		cout << setw(20) << left << savings_Account[i];
		cout << setw(20) << left << checking_Account[i];
		cout << setw(10) << left << savings_Account[i] + checking_Account[i] << endl;
	}
}