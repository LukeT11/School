// Luke Talcott
// ldt9gn@mail.umkc.edu
// 2/27/2019
// CS201L Lab 06

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

double calcDistance(double x1, double x2, double y1, double y2, double z1, double z2) {
	double distance;

	distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));

	return distance;
}