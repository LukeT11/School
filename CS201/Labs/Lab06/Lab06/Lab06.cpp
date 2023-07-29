// Luke Talcott
// ldt9gn@mail.umkc.edu
// 2/27/2019
// CS201L Lab 06

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include "lab06.h"
using namespace std;

int main() {
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	ofstream fouts("output_sorted.txt");
	
	vector<vector<double>> vect1;
	vector<vector<double>> vect2;
	vector<double> vect3;
	
	double x;
	double y;
	double z;
	double i = 0;
	double a = 0;
	double indexsmall = 0;
	double temp;

	while (fin.good()) {
		vect1.resize(vect1.size() + 1);
		vect2.resize(vect2.size() + 1);
		
		vect1.at(i).resize(3);
		vect2.at(i).resize(3);

		fin >> vect1.at(i).at(0) >> vect1.at(i).at(1) >> vect1.at(i).at(2);
		fin >> vect2.at(i).at(0) >> vect2.at(i).at(1) >> vect2.at(i).at(2);
		
		i++;
	}

	fin.close();

	for (i = 0; i < vect1.size(); i++) {
		vect3.push_back(calcDistance(vect1.at(i).at(a), vect2.at(i).at(a), vect1.at(i).at(a + 1), vect2.at(i).at(a + 1), vect1.at(i).at(a + 2), vect2.at(i).at(a + 2)));
	}

	for (i = 0; i < vect3.size(); i++) {
		fout << vect3.at(i) << endl;
	}

	fout.close();

	for (i = 0; i < vect3.size() - 1; i++) {
		indexsmall = i;
		for (a = i + 1; a < vect3.size(); a++) {
			if (vect3.at(a) < vect3.at(indexsmall))  {
				indexsmall = a;
			}
		}
		temp = vect3.at(i);
		vect3.at(i) = vect3.at(indexsmall);
		vect3.at(indexsmall) = temp;
	}

	for (i = 0; i < vect3.size(); i++) {
		fouts << vect3.at(i) << endl;
	}
	
	fouts.close();

	return 0;
}