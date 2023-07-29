//Luke Talcott
//ldt9gn@mail.umkc.edu
//2/13/2019
//CS 201L Lab 04

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


void deposit(double& account, double amount) {
	account = account + amount;
}

char MainMenu() {
	char choice = ' ';

	while (choice != 'D' && choice != 'W' && choice != 'L' && choice != 'Q') {
		cout << "Main Menu ( Enter one of the following )" << endl;
		cout << "    (D)eposit, (W)ithdrawal, (L)oan or (Q)uit" << endl;
		cin >> choice;
		choice = toupper(choice);
	}

	return choice;
}

double GetValue(string value) {
	double amount = 0;

	while (amount <= 0) {
		cout << value;
		cin >> amount;
		cout << endl;
		if (amount <= 0) {
			cout << "\nYou must enter an amount greater than 0" << endl;
		}
	}
	return amount;
}

double GetValue(string value, double upperLimit) {
	double amount = 0;

	while (amount <= 0 || amount >= upperLimit) {
		cout << value;
		cin >> amount;
		cout << endl;
		if (amount <= 0) {
			cout << "\nYou must enter an amount greater than 0" << endl;
		}
		else if (amount >= upperLimit) {
			cout << "\nYou must enter an amount less than or equal to " << upperLimit << endl;
		}
	}
	return amount;
}

double withdraw(double account, double amount) {
	account = account - amount;

	return account;
}

double GetInterestRate(double creditScore = 0) {
	double interestRate = 0.00;

	if (creditScore < 500) {
		interestRate = .05;
	}
	else if (creditScore > 500 && creditScore <= 700) {
		interestRate = .03;
	}
	else if (creditScore > 700) {
		interestRate = .01;
	}
	return interestRate;
}

double GetLoanMonths() {
	double months = 0;

	while (months != 12 && months != 24 && months != 36 && months != 60) {
		cout << "How many months for the loan? 12, 24, 36 or 60 ==> ";
		cin >> months;
		cout << endl;
		if (months != 12 && months != 24 && months != 36 && months != 60) {
			cout << "\nYou must enter 12,24 36 or 60 only" << endl;
		}
	}
	return months;
}

double GetCreditRating() {
	double creditScore = 0;

	while (creditScore < 300 || creditScore > 850) {
		cout << "What is your credit rating? [300, 850] ==> ";
		cin >> creditScore;
		cout << endl;
		if (creditScore < 300 || creditScore > 850) {
			cout << "\nYou must choose a vale from 300 - 850 inclusive." << endl;
		}
	}
	return creditScore;
}

double CalculateLoanAmount(double principal, double interestRate, double loanMonths) {
	double loanAmount;
	double rate;

	rate = 1 + (interestRate / 12);
	loanAmount = (principal) * (pow(rate, (loanMonths / 12)));

	return loanAmount;
}

void OutputAmount(double amount) {
	cout << "\nSummary of Account" << endl;
	cout << "    Amount $" << amount;
	cout << endl;
}