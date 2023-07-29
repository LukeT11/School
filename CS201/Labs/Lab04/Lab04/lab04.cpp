//Luke Talcott
//ldt9gn@mail.umkc.edu
//2/13/2019
//CS 201L Lab 04

#include <iostream>
#include <string>
#include "checkingmodule.h"
using namespace std;



int main() {
	double account = 0, depositAmount = 0, withdrawAmount = 0;
	char choice = ' ';
	double interestRate = 0.00;
	double creditScore = 0;
	double loanMonths = 0;
	double creditRating = 0;
	double principal = 0;
	double loanAmount = 0;

	while (choice != 'Q') {

		choice = MainMenu();

		switch (choice) {
		case 'D':
			depositAmount = GetValue("How much do you want to deposit? ==> ");
			deposit(account, depositAmount);
			OutputAmount(account);
			break;

		case 'W':
			withdrawAmount = GetValue("How much do you want to withdraw? ==> ", account);
			account = withdraw(account, withdrawAmount);
			OutputAmount(account);
			break;

		case 'L':
			creditRating = GetCreditRating();
			interestRate = GetInterestRate(creditScore);
			loanMonths = GetLoanMonths();
			while (principal <= 0) {
				cout << "How much do you want to borrow(Above 0)? ";
				cin >> principal;
				cout << endl;
			}
			loanAmount = CalculateLoanAmount(principal, interestRate, loanMonths);
			cout << "\nInterest Rate : " << interestRate << endl;
			cout << "Principal : " << principal << endl;
			cout << "Months : " << loanMonths << endl;
			cout << "Your total loan amount is " << loanAmount << endl;
			break;

		case 'Q':
			break;

		default:
			break;
		}
	}


	system("pause");
	return 0;
}