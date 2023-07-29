#pragma once
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

//All functions called and used in Assignment 3.

void PrintOneMonth(int monthNumber, int year, int &startDayNumber);
int DaysPerMonth(int monthNumber, int year);
int GetStartDayNumber();
int GetYear();