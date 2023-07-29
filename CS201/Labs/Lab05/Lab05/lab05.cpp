//Luke Talcott
//ldt9gn@mail.umkc.edu
//2/13/2019
//CS 201L Lab 05

#include "lab05.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	vector<vector<int>> matrix1;
	vector<vector<int>> matrix2;
	vector<vector<int>> matrix3;
	vector<vector<int>> matrix4;

	char key = 'r';
	int rows = 0;
	int columns = 0;
	int rows2 = 0;
	int columns2 = 0;
	int i;
	int j;
	char add = 'n';
	char multiply = 'n';


	while (key != 'Q') {
		rows = GetNum("Enter the number of rows in this matrix >>> ");
		columns = GetNum("Enter the number of columns in this matrix >>> ");

		matrix1.resize(rows);
		cout << "Please enter the values in this matrix, you can enter each row at once, each cell or all of them seperated by spaces." << endl;
		
		for (i = 0; i < matrix1.size(); i++) {
			matrix1.at(i).resize(columns);

			for (j = 0; j < matrix1.at(i).size(); j++) {
				cin >> matrix1.at(i).at(j);
			}
		}
		
		cout << "You entered the grid g1 as " << endl;

		for (i = 0; i < matrix1.size(); i++) {

			for (j = 0; j < matrix1.at(i).size(); j++) {
				cout << matrix1.at(i).at(j) << " ";
			}
			cout << endl;
		}

		rows2 = GetNum("Enter the number of rows in this matrix >>> ");
		columns2 = GetNum("Enter the number of columns in this matrix >>> ");

		matrix2.resize(rows2);
		cout << "Please enter the values in this matrix, you can enter each row at once, each cell or all of them seperated by spaces." << endl;

		for (i = 0; i < matrix2.size(); i++) {
			matrix2.at(i).resize(columns2);

			for (j = 0; j < matrix2.at(i).size(); j++) {
				cin >> matrix2.at(i).at(j);
			}
		}

		cout << "You entered the grid g2 as " << endl;

		for (i = 0; i < matrix2.size(); i++) {

			for (j = 0; j < matrix2.at(i).size(); j++) {
				cout << matrix2.at(i).at(j) << " ";
			}
			cout << endl;
		}

		add = AddMatrices(rows, columns, rows2, columns2);
		if (add == 'y') {
			cout << "g1 + g2 is" << endl;
			matrix3.resize(rows);

			for (i = 0; i < matrix3.size(); i++) {
				matrix3.at(i).resize(columns);

				for (j = 0; j < matrix3.at(i).size(); j++) {
					matrix3.at(i).at(j) = matrix1.at(i).at(j) + matrix2.at(i).at(j);
				}
			}

			for (i = 0; i < matrix3.size(); i++) {

				for (j = 0; j < matrix3.at(i).size(); j++) {
					cout << matrix3.at(i).at(j) << " ";
				}
				cout << endl;
			}
		}
		else {
			cout << "Cannot add 2 grids of this size together, the # of rows and columns must be the same." << endl;
		}

		multiply = MultiplyMatrices(columns, rows2);

		if (multiply == 'y') {
			cout << "g1 * g2 is " << endl;
			matrix4.resize(rows);

			for (i = 0; i < matrix4.size(); i++) {
				matrix4.at(i).resize(columns2);

				for (j = 0; j < matrix4.at(i).size(); j++) {
					matrix4.at(i).at(j) = matrix1.at(i).at(j) + matrix2.at(i).at(j);
				}
			}

			for (i = 0; i < matrix4.size(); i++) {

				for (j = 0; j < matrix4.at(i).size(); j++) {
					cout << matrix4.at(i).at(j) << " ";
				}
				cout << endl;
			}
		}
		else {
			cout << "Cannot multiply 2 grids this size together, the number of columns from grid 1 must match the number of rows from grid 2" << endl;
		}

		cout << "Press Q to quit, any other key to do another grid ";
		cin >> key;
		key = toupper(key);
		cout << endl;
	}
	system("Pause");
	return 0;
}