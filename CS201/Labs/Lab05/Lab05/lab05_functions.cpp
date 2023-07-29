//Luke Talcott
//ldt9gn@mail.umkc.edu
//2/13/2019
//CS 201L Lab 05

#include <iostream>
#include <string>
//#include <vector>

using namespace std;


int GetNum(string value) {
	int num;

	cout << value;
	cin >> num;
	cout << endl;

	return num;
}

char AddMatrices(int row1, int column1, int row2, int column2) {
	char add = 'n';

	if (row1 == row2) {
		if (column1 == column2) {
			add = 'y';
		}
	}
	
	return add;
}

char MultiplyMatrices(int columns1, int rows2) {
	char multiply = 'n';

	if (columns1 == rows2) {
		multiply = 'y';
	}

	return multiply;
}