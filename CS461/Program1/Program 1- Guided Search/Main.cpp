//Luke Talcott
//Program 1 Guided Search
//CS461

#include "RouteFinding.h";
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>


int main() {
	ifstream fileC;
	ifstream fileA;
	string fileCoord;
	string fileAdjac;
	string city;
	string lat;
	string longi;
	string adj;
	vector<string> cities;
	vector<double> latit;
	vector<double> longit;
	vector<pair <double, double> > coord;
	RouteFind routeCity;

	//Assign files and open for Coordinates and Adjacencies
	fileCoord = "coordinates.txt";
	fileAdjac = "Adjacencies.txt";

	fileC.open(fileCoord);
	fileA.open(fileAdjac);
	
	if (!fileC.is_open()) {
		cout << "Could Not Open file" << endl;
		return 1;
	}
	
	//Open and read file for Coordinates
	while (!fileC.eof()) {
		getline(fileC, city, ' ');
		getline(fileC, lat, ' ');
		getline(fileC, longi);

		double latitude = stod(lat);
		double longitude = stod(longi);
		routeCity.addLocation(city, latitude, longitude);
	}

	//Open and read file for Adjacencies
	while (!fileA.eof()) {
		getline(fileA, adj);
		string tOInt;
		string adjacent = adj;
		string tempCity;
		int numAdjCity = -1;

		for (int i = 0; i < adjacent.length(); i++) {
			if (adjacent.at(i) == ' ' && numAdjCity == -1) {
				tOInt = tempCity;
				tempCity = "";
				numAdjCity += 1;
			}
			else if ((adjacent.at(i) == ' ' || adjacent.length() == (i + 1)) && numAdjCity != -1) {
				if (adjacent.length() == (i + 1) && adjacent.length() != ' ') {
					tempCity.push_back((adjacent.at(i)));
				}
				routeCity.setAdjacencies(tOInt, tempCity);
				tempCity = "";
				numAdjCity += 1;
			}
			else {
				tempCity.push_back((adjacent.at(i)));
			}
		}
	}

	string cityStart;
	string cityEnd;

	//set cityStartand cityEnd, call routeCity class.
	cityStart = "Abilene";
	cityEnd = "Caldwell";
	cout << endl;
	routeCity.routeLocation(cityStart, cityEnd);

	//Close files for Coordinates and Adjacencies
	fileC.close();
	fileA.close();

	system("pause");
	return 0;
};