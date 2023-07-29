//Luke Talcott
//2/9/2019
//CS201
//Program 2

#include <iostream>
#include "string"
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include "Assignment2.h"
using namespace std;

//Main function/Code that executes the program.

int main() { //15-23 Just sets up integers, characters, strings, arrays, input File Stream.
	ifstream inFS;
	const int numElements = 10;
	int userID[numElements]; //= { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	string userFirst[numElements]; //= { "Homer", "Jack", "Daneiel", "Sara", "Thomas", "Sam", "Tina", "Wael", "Carol", "Jack" };
	string userLast[numElements]; //= { "Smith", "Stanely", "Hackson", "Thomson", "Elu", "Carol", "Jefferson", "Lion", "Smith", "Carlton" };
	double userSavings[numElements]; //= { 810.2, 100.0, 333.90, 1930.02, 932.0, 33.0, 334.90, 8843.2, 3994.09, 99.0 };
	double userChecking[numElements]; //= { 101.10, 1394.90, 7483.77, 4473.20, 2334.40, 0.0, 777.5, 88.90, 2343.30, 8433.04 };
	char key = ' ';
	int i = 0;

	inFS.open("input.txt"); //Inputs and opens the text file.

	if (inFS.fail()) {// Checks to see if file failed to open.
		cout << "Couldn't open file" << endl;
		return 1;
	}
	else { //Input each string to a certain array and index based off of its properties.
		for (i = 0; i < numElements; i++) {
			inFS >> userID[i];
			inFS >> userFirst[i];
			inFS >> userLast[i];
			inFS >> userSavings[i];
			inFS >> userChecking[i];
		}

		if (!inFS.eof()) {//Checks to see if there were any erros in reading the file.
			cout << "Error reading myfile.txt" << endl;
			return 1;
		}
	}

	inFS.close();  //Closes the input file.

	while (key != 'Q') { //While loop to run the flow of the function until a ceratin key is chosen to exit it.

		key = Menu(); //Calls function to display option to choose from.

		switch (key) { //Switch statement to execute funtion call.
		case '1': //Calls function to output customers id, first and last name, saving account, and checking account in a table if char key eqauls 1.
			PrintCustomersData(userID, userFirst, userLast, userSavings, userChecking, numElements);
			cout << endl;
			cout << endl;
			cout << endl;
			break;

		case '2': //Calls function to output customers id, first name, and last name in a table if char key equals 2.
			printNames(userID, userFirst, userLast, numElements);
			cout << endl;
			cout << endl;
			cout << endl;
			break;

		case '3': //Calls function to output customers id, savings account, checking account and the total of the accounts combined if char key equals 3.
			printTotal(userID, userSavings, userChecking, numElements);
			cout << endl;
			cout << endl;
			cout << endl;
			break;

		case 'Q': //Used to just go back to the top of the while loop to exit it if char key equals Q.
			break;

		default: //If char key equals none of the above choices, outputs a statement to try and pick a viable option.
			cout << "Wrong input. Try again...\n\n" << endl;
			break;
		}
	}

	return 0;
}