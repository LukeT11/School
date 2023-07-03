//Main for running Genetic Algorithm
using namespace std;
#include "GeneticAlgorithm.h"
#include "stdlib.h"
#include "iostream"
#include <iomanip>
#include <fstream>
#include <string>

int main() {
	ifstream ifAppendix;
	ifstream ifActivities;
	ifstream ifFacilitators;
	ifstream ifRooms;
	string fileAppendix = "Appendix.txt";
	string fileActivities = "Activities.txt";
	string fileFacilitator = "Facilitators.txt";
	string fileRooms = "Rooms.txt";
	GeneticAlgorithm genAlg;

	ifAppendix.open(fileAppendix);
	ifActivities.open(fileActivities);
	ifFacilitators.open(fileFacilitator);
	ifRooms.open(fileRooms);

	string tempActivity;
	string tempActivitySize;
	if (!ifAppendix.is_open()) {
		cout << "Could not open file" << endl;
		return 1;
	}
	while (!ifAppendix.eof()) {
		getline(ifAppendix, tempActivity, ',');
		getline(ifAppendix, tempActivitySize);
		int activitySizeStoi = stoi(tempActivitySize);
		genAlg.addAppendix(tempActivity, activitySizeStoi);
	}
	string tempActivityGetLine;
	string tempActivityString;
	string tempActivityOne;
	string tempActivityTwo;
	string tempCapacityActivity;
	string tempFacilitatorsString;
	string tempFacilitator;
	vector<string> tempPrefFacilitatorsList;
	vector<string> tempOtherFacilitatorsList;
	if (!ifActivities.is_open()) {
		cout << "Could not open file" << endl;
		return 1;
	}
	while (!ifActivities.eof()) {
		getline(ifActivities, tempActivityGetLine, '"');
		getline(ifActivities, tempActivityGetLine, '"');
		for (int i = 0; i < tempActivityGetLine.size(); i++) {
			if (tempActivityGetLine.at(i) == ',') {
				tempActivityOne = tempActivityString;
				tempActivityString.clear();
			}
			else {
				tempActivityString.push_back(tempActivityGetLine.at(i));
			}
		}
		if (!tempActivityOne.empty()) {
			tempActivityTwo = tempActivityString;
		}
		else {
			tempActivityOne = tempActivityString;
		}
		getline(ifActivities, tempCapacityActivity, ',');
		getline(ifActivities, tempCapacityActivity, '"');
		getline(ifActivities, tempCapacityActivity, '"');
		int tempCapacityActivityNum = stoi(tempCapacityActivity);
		getline(ifActivities, tempFacilitatorsString, ',');
		getline(ifActivities, tempFacilitatorsString, '"');
		getline(ifActivities, tempFacilitatorsString, '"');
		for (int i = 0; i < tempFacilitatorsString.size(); i++) {
			if ((tempFacilitatorsString.at(i) == ',') || (i == tempFacilitatorsString.size() - 1)) {
				if (i == tempFacilitatorsString.size() - 1) {
					tempFacilitator.push_back(tempFacilitatorsString.at(i));
				}
				tempPrefFacilitatorsList.push_back(tempFacilitator);
				tempFacilitator.clear();
			}
			else {
				tempFacilitator.push_back(tempFacilitatorsString.at(i));
			}
		}
		getline(ifActivities, tempFacilitatorsString, ',');
		getline(ifActivities, tempFacilitatorsString, '"');
		getline(ifActivities, tempFacilitatorsString, '"');
		for (int i = 0; i < tempFacilitatorsString.size(); i++) {
			if ((tempFacilitatorsString.at(i) == ',') || (i == tempFacilitatorsString.size() - 1)) {
				if (i == tempFacilitatorsString.size() - 1) {
					tempFacilitator.push_back(tempFacilitatorsString.at(i));
				}
				tempOtherFacilitatorsList.push_back(tempFacilitator);
				tempFacilitator.clear();
			}
			else {
				tempFacilitator.push_back(tempFacilitatorsString.at(i));
			}
		}
		getline(ifActivities, tempFacilitator, '\n');
		if (!tempActivityTwo.empty()) {
			genAlg.addDoubleActivity(tempActivityOne, tempActivityTwo, tempCapacityActivityNum,
				tempPrefFacilitatorsList, tempOtherFacilitatorsList);
		}
		else {
			genAlg.addSingleActivity(tempActivityOne, tempCapacityActivityNum, tempPrefFacilitatorsList, 
				tempOtherFacilitatorsList);
		}
		tempActivityGetLine.clear();
		tempActivityString.clear();
		tempActivityOne.clear();
		tempActivityTwo.clear();
		tempCapacityActivity.clear();
		tempFacilitatorsString.clear();
		tempFacilitator.clear();
		tempPrefFacilitatorsList.clear();
		tempOtherFacilitatorsList.clear();
	}
	string tempFacilitators;
	if (!ifFacilitators.is_open()) {
		cout << "Could not open file" << endl;
		return 1;
	}
	while (!ifFacilitators.eof()) {
		getline(ifFacilitators, tempFacilitators);
		genAlg.addFacilitators(tempFacilitators);
	}
	string tempRoom;
	string tempCapacity;
	string tempTime;
	vector<string> tempTimes;
	if (!ifRooms.is_open()) {
		cout << "Could not open file" << endl;
		return 1;
	}
	while (!ifRooms.eof()) {
		getline(ifRooms, tempRoom, ',');
		getline(ifRooms, tempCapacity, ',');
		int tempCapacityNum = stoi(tempCapacity);
		getline(ifRooms, tempTime);
		string tempTimeString;
		for (int i = 0; i < tempTime.size(); i++) {
			if ((tempTime.at(i) == ',') || (i == tempTime.size()-1)) {
				if (i == tempTime.size() - 1) {
					tempTimeString.push_back(tempTime.at(i));
				}
				tempTimes.push_back(tempTimeString);
				tempTimeString.clear();
			}
			else if (tempTime.at(i) == ' ') {
				continue;
			}
			else{
				tempTimeString.push_back(tempTime.at(i));
			}
		}		
		genAlg.addRoom(tempRoom, tempCapacityNum, tempTimes);
		tempTimes.clear();
	}

	ifAppendix.close();
	ifActivities.close();
	ifFacilitators.close();
	ifRooms.close();

	int testSampleSize = 750;
	int testGenerations = 100;
	genAlg.setSampleSize(testSampleSize);
	genAlg.setNumGenerations(testGenerations);
	genAlg.generateSchedule();

	system("pause");
};