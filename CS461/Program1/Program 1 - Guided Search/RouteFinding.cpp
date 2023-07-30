#include "RouteFinding.h"

//Constructor set default values Route Find.
RouteFind::RouteFind() {
	location = "";
	latit = 0;
	longit = 0;
	numLocations = 0;
	locationStart = "";
	locationEnd = "";
}

/*Add Location to a vector of locations, add coordinates to vector coordinates, add empty vector for
adjacency locations for added location.*/
void RouteFind::addLocation(string locIn, double latitInput, double longitInput) {
	string locationIn = locIn;
	latit = latitInput;
	longit = longitInput;

	locations.push_back(locationIn);
	vector<string> emptyVec;
	emptyVec.push_back("");
	adjLocations.push_back(emptyVec);

	coordinates.push_back(make_pair(latit, longit));
	numLocations = locations.size();
}

//For list of locations, Add adjacencies for each of those locations that we know how to get too from them.
void RouteFind::setAdjacencies(string locInterest, string locAdj) {
	int numLoc = numLocations;
	string tempLocInt = locInterest;
	string tempLocAdj = locAdj;
	int vecLoc = 0;

	for (int i = 0; i < numLoc; i++) {
		if (tempLocInt == locations[i]) {
			if (find(adjLocations[i].begin(), adjLocations[i].end(), tempLocAdj) != adjLocations[i].end()) {
				break;
			}
			else {
				adjLocations[i].push_back(tempLocAdj);
			}

			if (adjLocations[i][0] == "") {
				adjLocations[i].erase(adjLocations[i].begin());
			}
		}
	}
	for (int i = 0; i < numLoc; i++) {
		if (tempLocAdj == locations[i]) {
			if (find(adjLocations[i].begin(), adjLocations[i].end(), tempLocInt) != adjLocations[i].end()) {
				break;
			}
			else {
				adjLocations[i].push_back(tempLocInt);
			}

			if (adjLocations[i][0] == "") {
				adjLocations[i].erase(adjLocations[i].begin());
			}
		}
	}
}

/*Take input locaton startand end.Validate usable locations, add start location to new open list nodes
to search, call function to begin path to end location.*/
void RouteFind::routeLocation(string locStart, string locEnd) {
	locationStart = locStart;
	locationEnd = locEnd;
	bool locValid = checkValidLocation(locStart, locEnd);

	if (locValid == true) {
		vector<pair<string, double>> vecPath = { make_pair(locationStart, 0) };
		vector<pair<string, double>> vecPathLocations = { make_pair(locationStart, 0) };
		openList.push_back(make_pair(vecPath, vecPathLocations));
		locFindQueue();
	}
	else if (locValid == false) {
		cout << "Location not found in list of locations" << endl;
	}
}

//Verify that location inputs are in vector of locations.
bool RouteFind::checkValidLocation(string checkLocStart, string checkLocEnd) {
	if (find(locations.begin(), locations.end(), checkLocStart) != locations.end() && 
		find(locations.begin(), locations.end(), checkLocEnd) != locations.end())
	{
		return true;
	}
	else {
		return false;
	}
}

/*Main Queue Function to explore the "Frontier" of locations until we reach a solution to final location using
the open vector list of locations.*/
void RouteFind::locFindQueue() {
	while (!openList.empty()) {
		//Take lowest distance all all locaions
		double tempLocSize = openList.back().second.back().second;
		int tempVecLocPath = openList.size() - 1;
		int tempVecLocPathPairs = (openList.at(tempVecLocPath).second.size())-1;
		for (int i = 0; i < openList.size(); i++)
		{
			for (int s = 0; s < openList.at(i).second.size(); s++)
			{
				if (tempLocSize > openList.at(i).second.at(s).second)
				{
					tempLocSize = openList.at(i).second.at(s).second;
					tempVecLocPath = i;
					tempVecLocPathPairs = s;
				}
			}
		}
		pair<string, double> currentLocation = openList.at(tempVecLocPath).second.at(tempVecLocPathPairs);
		vector<pair<string, double>> currentPath = openList.at(tempVecLocPath).first;
		//Remove location pair from openList
		if (openList.at(tempVecLocPath).second.size() == 1)
		{
			openList.erase(openList.begin() + tempVecLocPath);
		}
		else {
			openList.at(tempVecLocPath).second.erase(openList.at(tempVecLocPath).second.begin() + tempVecLocPathPairs);
		}
		//Check and match path with current location
		bool inPathToDestination = false;
		int tempPathNum = 0;
		for (int s = 0; s < pathToDestination.size(); s++) {
			if (currentLocation.first == pathToDestination.at(s).first) {
				inPathToDestination = true;
				tempPathNum = s;
				break;
			}
		}
		if (inPathToDestination == true) {
			for (int b = (tempPathNum + 1); b < pathToDestination.size();) {
				pathToDestination.erase(pathToDestination.begin() + b);
			}
			closedList.push_back(currentLocation);
		}
		else {
			//Math path to destination with path of current location
			if ((pathToDestination.size() == currentPath.size()) && pathToDestination.size() != 0)
			{
				for (int i = 0; i < pathToDestination.size(); i++) {
					if (pathToDestination.at(i) != currentPath.at(i)) {
						pathToDestination.at(i) = currentPath.at(i);
					}
				}

			}
			else if (pathToDestination.size() != 0) {
				pathToDestination = currentPath;
			}
			//If location is end destination return path data
			pathToDestination.push_back(currentLocation);
			if (currentLocation.first == locationEnd) {
				return returnData();
			}
			//Find adjacent locations to current location and add to open list if not worse 
			//than whats in open or close list.
			else {
				for (int i = 0; i < adjLocations.size(); i++)
				{
					if (locations.at(i) == currentLocation.first) {
						for (int j = 0; j < adjLocations[i].size(); j++) {
							//Variables for findng coordinates to adjacetn locations
							double totalDistancePath = 0;
							double totalDistanceToGoal = 0;
							double tempLat = 0;
							double tempLon = 0;
							double currVecLat = 0;
							double currVecLon = 0;
							
							//Find coordinates to adjacent locations, find Distance from start to current location.
							for (int k = 0; k < coordinates.size(); k++)
							{
								if (locations.at(k) == adjLocations[i][j]) {
									currVecLat = coordinates.at(k).first;
									currVecLon = coordinates.at(k).second;
								}
								if (locations.at(k) == pathToDestination.at(0).first)
								{
									tempLat = coordinates.at(k).first;
									tempLon = coordinates.at(k).second;
								}
							}
							for (int l = 0; l < pathToDestination.size()-1; l++) {		
								for (int m = 0; m < coordinates.size(); m++) {
									if (pathToDestination.at(l+1).first == locations.at(m) && l+1 == pathToDestination.size() - 1)
									{
										totalDistancePath += (EuclideanDistanceLoc(currVecLat, currVecLon,
											coordinates.at(l).first, coordinates.at(l).second));
									}
									else if (pathToDestination.at(l + 1).first == locations.at(m) && l == 0) {
										totalDistancePath += (EuclideanDistanceLoc(tempLat, tempLon,
											coordinates.at(l).first, coordinates.at(l).second));
									}

									else if (pathToDestination.at(l + 1).first == locations.at(m)) {
										totalDistancePath += (EuclideanDistanceLoc(coordinates.at(l+1).first,
											coordinates.at(l+1).second,
											coordinates.at(l).first, coordinates.at(l).second));
									}
								}
							}
							//Get Distance current location to goal.
							for (int k = 0; k < coordinates.size(); k++) {
								if (locations.at(k) == locationEnd) {
									totalDistanceToGoal = (EuclideanDistanceLoc(currVecLat, currVecLon, 
										coordinates.at(k).first, coordinates.at(k).second));
									break;
								}
							}
							//If adjacent location better than in open and closed list, add to open list.
							double totalDistance = totalDistancePath + totalDistanceToGoal;
							bool inOpenOrClosedList = false;
							for (int k = 0; k < openList.size(); k++) {
								for (int a = 0; a < openList.at(k).second.size(); a++) {
									if ((openList.at(k).second.at(a).first == adjLocations[i][j]) && (openList.at(k).second.at(a).second <= totalDistance)) {
										inOpenOrClosedList = true;
										break;
									}
								}
							}

							for (int k = 0; k < closedList.size(); k++) {
								if (closedList.at(k).first == adjLocations[i][j] && (closedList.at(k).second <= totalDistance)) {
									inOpenOrClosedList = true;
									break;
								}
							}
							if (inOpenOrClosedList == false) {
								bool vecInOpenListAlreadyCreated = false;
								for (int a = 0; a < openList.size(); a++)
									if (openList.at(a).first == pathToDestination) {
										vecInOpenListAlreadyCreated = true;
										openList.at(a).second.push_back(make_pair(adjLocations[i][j], totalDistance));
										break;
									}
								if (vecInOpenListAlreadyCreated == false) {
									vector<pair<string, double>> vecPath;
									vecPath = pathToDestination;
									vector<pair<string, double>> vecPathLocations = { make_pair(adjLocations[i][j], totalDistance) };
									openList.push_back(make_pair(vecPath, vecPathLocations));
								}
							}
						}
					}
				}
				//Add current location to closed list.
				closedList.push_back(currentLocation);
			}
		}
	}
	cout << "Finished Location Queue. Location Not Found." << endl;
}

//Find the distance location of two locations. Euclidean Distance.
double RouteFind::EuclideanDistanceLoc(double lat, double lon, double latTwo, double lonTwo) {
	double xOne = lat;
	double yOne = lon;
	double xTwo = latTwo;
	double yTwo = lonTwo;
	double dist = sqrt(pow(xTwo - xOne, 2) + pow(yTwo - yOne, 2));

	return dist;
}

//Return Output of Data for path to destination.
void RouteFind::returnData() {
	cout << endl << "Path to Destination: ";
	for (int i = 0; i < pathToDestination.size(); i++) {
		if (i == pathToDestination.size() - 1)
		{
			cout << "" << pathToDestination.at(i).first << endl;
		}
		else {
			cout << "" << pathToDestination.at(i).first << "->";
		}
	}
	cout << endl;
}