#pragma once
using namespace std;
#include <stdlib.h>
#include <iomanip>
#include "iostream"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class GeneticAlgorithm
{
public:
	GeneticAlgorithm();
	void addSingleActivity(string newSingleActivity, int newCapacity, vector<string> addPrefFaciliators, vector<string> addOtherFacilitators);
	void addDoubleActivity(string addActivityOne, string addActivityTwo, int newCapacity, vector<string> addPrefFaciliators, vector<string> addOtherFacilitators);
	void addRoom(string addRoomName, int addCapacitySize, vector<string> addRoomTimes);
	void addAppendix(string addAppendixName, int addAppendixSize);
	void addFacilitators(string addFacilitatorVec);
	void setSampleSize(int inputSampleSize);
	void setNumGenerations(int inputNumGenerations);
	void generateSchedule();

private:
	struct activity {
		string activityName;
		int capacityActivity = 0;
		vector<string> prefFacilitators;
		vector<string> otherFacilitators;
	};
	struct room {
		string roomName;
		int capacityRoom = 0;
		vector<string> times;
	};
	struct sampleActivityAssignments {
		int numSectionsActivities;
		int numActivity;
		int numRoom;
		int numSlotTime;
		int numFacilitator;
	};
	struct sampleSchedule {
		vector<sampleActivityAssignments> sampleActivities;
		double fitness = 0;
	};

	vector<pair<string, int>> appendix;
	vector<string> facilitators;
	vector<activity> activities;
	vector<pair<string, string>> pairsDoubleActivities;
	vector<room> rooms;
	vector<sampleSchedule> sampleSchedules;
	vector<sampleSchedule> newGenerationSchedules;
	vector<double> softMaxSchedulesExponentials;
	vector<double> softmaxSchedulesProbability;
	vector<double> softmaxSchedulesProbabilityDistributionForRNG;
	vector<double> generationsAvgFitness;
	int sampleSize = 500;
	int numGenerations = 100;
	int currGeneration = 0;

	int randomRoom();
	int randomSlotTime(int numRandRoom);
	int randomFacilitator();
	bool randomMutationRate();
	void generateRandomStartPopulationSchedules();
	void generateFitnessScoresForSchedules();
	double calcFitnessForSchedule(sampleSchedule tempScheduleCalcFitness);
	void sortFitnessScoresByHighest();
	void calcSoftMaxSchedules();
	void calcSoftmaxSchedulesProbabilityDistributionForRNG();
	int randomProbDistNumParentSchedule();
	void calcOffspringScheduleFromParents(sampleSchedule scheduleParentOne, sampleSchedule scheduleParentTwo);
	void calcGenerationsSchedules();
	void returnInputDataText();
	void returnBestScheduleText();
	void returnFinalScheduleOutputFile();
};