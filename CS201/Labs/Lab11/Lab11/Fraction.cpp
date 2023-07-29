// Your name
// Your UMKC Email Address
// Today's date
// CS201L Lab 11

#include "Fraction.h"
#include <iostream>
#include <string>
using namespace std;

// Find the greatest common denominator (GCD)
// For reducing
int Fraction::getGCD(int num1, int num2)
{
	int remainder = num2 % num1;
	if (remainder != 0)
		return getGCD(remainder, num1);
	return num1;
}

// Reduce/simplify a fraction
void Fraction::reduce()
{
	// Alter this function later to adjust for negative values
	int gcd = getGCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

//Constructor sets numerator and denominator to 0.
Fraction::Fraction() {
	numerator = 0;
	denominator = 0;
}

//Returns the string ouput with numerator, fraction sign and denominator.
ostream& operator << (ostream& output, const Fraction& fract) {
	output << fract.numerator;
	output << "/";
	output << fract.denominator;

	return output;
}

//Returns the string input with numerator, fraction sign and denominator.
istream& operator >> (istream& input, Fraction& fract) {
	input >> fract.numerator;
	input >> fract.div;
	input >> fract.denominator;

	return input;
}

//Returns add with the numerator and denominator with fractions added.
const Fraction Fraction::operator+(Fraction other) {
	Fraction add;

	reduce();
	other.reduce();
	add.numerator = (numerator * other.denominator) + (denominator * other.numerator);
	add.denominator = denominator * other.denominator;

	return add;
}

//Returns sum with the numerator and denominator with fractions subtracted.
const Fraction Fraction::operator-(Fraction other) {
	Fraction sub;

	reduce();
	other.reduce();
	sub.numerator = (numerator * other.denominator) - (denominator * other.numerator);
	sub.denominator = denominator * other.denominator;

	return sub;
}

//Returns mult with the numerator and denominator with fractions multiplied.
const Fraction Fraction::operator*(Fraction other) {
	Fraction mult;
	
	mult.numerator = (numerator * other.numerator);
	mult.denominator = denominator * other.denominator;
	mult.reduce();
	
	return mult;
}

//Returns div with the numerator and denominator with fractions divided.
const Fraction Fraction::operator/(Fraction other) {
	Fraction div;

	reduce();
	other.reduce();
	div.numerator = (numerator * other.denominator);
	div.denominator = denominator * other.numerator;
	div.reduce();
	return div;

}

//Boolean checks in fractions equal each other or not returing ture if yes and false if no.
const bool Fraction::operator==(Fraction other) {
	reduce();
	other.reduce();

	if (numerator == other.numerator && denominator == other.denominator) {
		return true;
	}
	else {
		return false;
	}
}