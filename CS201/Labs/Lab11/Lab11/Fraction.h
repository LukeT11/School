#pragma once
// Your Name
// Today's date
// Lab 9

#include <iostream>
using namespace std;

class Fraction
{
	// Add the variables and functions you need to. getGCD and reduce are 
	// provided for you.

private:
	int getGCD(int num1, int num2);
	int numerator;
	int denominator;
	char div;


public:
	void reduce();
	Fraction();
	friend ostream& operator << (ostream& output, const Fraction& fract);
	friend istream& operator >> (istream& input, Fraction& fract);
	const Fraction operator+( Fraction other);
	const Fraction operator-(Fraction other);
	const Fraction operator*(Fraction other);
	const Fraction operator/(Fraction other);
	const bool operator==(Fraction other);
};