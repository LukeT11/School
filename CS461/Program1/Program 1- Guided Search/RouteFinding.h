#pragma once

#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;
#include <fstream>
#include <vector>
#include <iomanip>
#include <set>
#include <iterator>

class RouteFind {
public:
	RouteFind();
	void addLocation(string locIn, double latitInput, double longitInput);
	void setAdjacencies(string locInterest, string locAdj);
	void routeLocation(string locStart, string locEnd);
	bool checkValidLocation(string checkLocStart, string checkLocEnd);
	double EuclideanDistanceLoc(double lat, double lon, double latTwo, double lonTwo);
	void locFindQueue();
	void returnData();

private:
	vector<string> locations;
	vector<vector<string>> adjLocations;
	vector<pair <double, double> > coordinates;
	vector<string> destinationRoute;
	vector<pair<vector<pair<string, double>>, vector<pair<string, double>>>> openList;
	vector<pair<string, double>> closedList;
	vector<pair<string, double>> pathToDestination;

	string location;
	double latit;
	double longit;
	int numLocations;
	string locationStart;
	string locationEnd;
};