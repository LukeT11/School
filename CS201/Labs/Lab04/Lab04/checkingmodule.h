//Luke Talcott
//ldt9gn@mail.umkc.edu
//2/13/2019
//CS 201L Lab 04

#include <iostream>
#include <string>


using namespace std;

void deposit(double& account, double amount);
char MainMenu();
double GetValue(string value);
double GetValue(string value, double upperLimit);
double withdraw(double account, double amount);
double GetInterestRate(double creditScore);
double GetLoanMonths();
double GetCreditRating();
double CalculateLoanAmount(double principal, double interestRate, double loanMonths);
void OutputAmount(double amount);
