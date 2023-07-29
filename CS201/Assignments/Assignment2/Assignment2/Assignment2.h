#pragma once
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

//List of all functions called for Assignment 2.

char Menu();
void PrintCustomersData(const int id[], const string first[], const string last[], const double savings_Account[], const double checking_Account[], int size);
void printNames(const int id[], const string first[], const string last[], int size);
void printTotal(const int id[], const double savings_Account[], const double checking_Account[], int size);