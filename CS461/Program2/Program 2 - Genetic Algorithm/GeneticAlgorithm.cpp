#include "GeneticAlgorithm.h"

//Add Activty of only one to Activities
GeneticAlgorithm::GeneticAlgorithm() {
	//srand(time(0));
}

void GeneticAlgorithm::addSingleActivity(string newSingleActivity, int newCapacity, vector<string> addPrefFaciliators, vector<string> addOtherFacilitators)
{
	activity tempSingleActivity;
	tempSingleActivity.activityName = newSingleActivity;
	tempSingleActivity.capacityActivity = newCapacity;
	tempSingleActivity.prefFacilitators = addPrefFaciliators;
	tempSingleActivity.otherFacilitators = addOtherFacilitators;
	activities.push_back(tempSingleActivity);
}

//Add Activities of Two to Activities
void GeneticAlgorithm::addDoubleActivity(string addActivityOne, string addActivityTwo, int newCapacity, vector<string> addPrefFaciliators, vector<string> addOtherFacilitators)
{
	pairsDoubleActivities.push_back(make_pair(addActivityOne, addActivityTwo));
	activity tempActivityOne;
	activity tempActivityTwo;
	tempActivityOne.activityName = addActivityOne;
	tempActivityOne.capacityActivity = newCapacity;
	tempActivityOne.prefFacilitators = addPrefFaciliators;
	tempActivityOne.otherFacilitators = addOtherFacilitators;
	activities.push_back(tempActivityOne);
	tempActivityTwo.activityName = addActivityTwo;
	tempActivityTwo.capacityActivity = newCapacity;
	tempActivityTwo.prefFacilitators = addPrefFaciliators;
	tempActivityTwo.otherFacilitators = addOtherFacilitators;
	activities.push_back(tempActivityTwo);
}

//Add a Room to Rooms
void GeneticAlgorithm::addRoom(string addRoomName, int addCapacitySize, vector<string> addRoomTimes)
{
	room tempRoom;
	tempRoom.roomName = addRoomName;
	tempRoom.capacityRoom = addCapacitySize;
	tempRoom.times = addRoomTimes;
	rooms.push_back(tempRoom);
}

//Add Appendix Item to Appendixes
void GeneticAlgorithm::addAppendix(string addAppendixName, int addAppendixSize)
{
	appendix.push_back(make_pair(addAppendixName, addAppendixSize));
}

//Add a Facilitator to Facilitators
void GeneticAlgorithm::addFacilitators(string addFacilitatorVec)
{
	facilitators.push_back(addFacilitatorVec);
}

//Set Sample Size for Number of Schedules to be generated for each Generation
void GeneticAlgorithm::setSampleSize(int inputSampleSize) {
	sampleSize = inputSampleSize;
}

//Set Number of generations create
void GeneticAlgorithm::setNumGenerations(int inputNumGenrations) {
	numGenerations = inputNumGenrations;
}

//Get a Random Room
int GeneticAlgorithm::randomRoom() {
	return (rand() % rooms.size());
}

//Get a random Slot Time for a particular room
int GeneticAlgorithm::randomSlotTime(int numRandRoom) {
	return (rand() % rooms.at(numRandRoom).times.size());
}

//Get a random Facilitator
int GeneticAlgorithm::randomFacilitator() {
	return (rand() % facilitators.size());
}

//Get a return on whether a Mutation should occur with given Mutation Rate possibility
bool GeneticAlgorithm::randomMutationRate() {
	return ((rand() % 1600) == 0);
};

//Generate Number of Random Schedules for the given Sample Size as the beginning population of generation 0
void GeneticAlgorithm::generateRandomStartPopulationSchedules() {
	for (int i = 0; i < sampleSize; i++) {
		sampleSchedule generatedSchedule;
		for (int j = 0; j < activities.size(); j++) {
			sampleActivityAssignments tempGeneratedActivity;
			tempGeneratedActivity.numSectionsActivities = 1;
			for (int k = 0; k < pairsDoubleActivities.size(); k++) {
				if ((activities.at(j).activityName == pairsDoubleActivities.at(k).first) ||
					(activities.at(j).activityName == pairsDoubleActivities.at(k).second)) {
					tempGeneratedActivity.numSectionsActivities = 2;
					break;
				}
			}
			tempGeneratedActivity.numActivity = j;
			tempGeneratedActivity.numRoom = randomRoom();
			tempGeneratedActivity.numSlotTime = randomSlotTime(tempGeneratedActivity.numRoom);
			tempGeneratedActivity.numFacilitator = randomFacilitator();
			generatedSchedule.sampleActivities.push_back(tempGeneratedActivity);
		}
		sampleSchedules.push_back(generatedSchedule);
	}
	generateFitnessScoresForSchedules();
	sortFitnessScoresByHighest();
};

//Calculate the Fitness Score for a given Schedule using the given Fitness Function
double GeneticAlgorithm::calcFitnessForSchedule(sampleSchedule tempScheduleCalcFitness) {
	sampleSchedule currentScheduleCalcFitness = tempScheduleCalcFitness;
	double fitnessValueTotal = 0;
	double testFitnessValueActivity = 0;

	for (int j = 0; j < currentScheduleCalcFitness.sampleActivities.size(); j++) {
		testFitnessValueActivity = 0;
		//For Multiple Sections Activities, Fitness Adjustments
		if (currentScheduleCalcFitness.sampleActivities.at(j).numSectionsActivities == 2) {
			string tempOtherSectionActivity;
			int tempTimeSlotSectionActivity;
			//Find Other Section Activity Location for Time Slot Comparison
			for (int k = 0; k < pairsDoubleActivities.size(); k++) {
				if (activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).activityName
					== pairsDoubleActivities.at(k).first) {
					tempOtherSectionActivity = pairsDoubleActivities.at(k).second;
					break;
				}
				else if (activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).activityName
					== pairsDoubleActivities.at(k).second) {
					tempOtherSectionActivity = pairsDoubleActivities.at(k).first;
					break;
				}
			}
			for (int k = 0; k < activities.size(); k++) {
				if (tempOtherSectionActivity == activities.at(k).activityName) {
					tempTimeSlotSectionActivity = currentScheduleCalcFitness.sampleActivities.at(k).numSlotTime;
					break;
				}
			}
			//Fitness Value Time Slots Mutltiple Sections
			if (currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime == tempTimeSlotSectionActivity) {
				testFitnessValueActivity -= 0.5;
			}
			else if ((abs(currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime-tempTimeSlotSectionActivity)) > 4) {
				testFitnessValueActivity += 0.5;
			}
			//Get Location Name Current Activity
			string tempLocationCurrentActivity = "";
			for (int k = 0; k < rooms.at(currentScheduleCalcFitness.sampleActivities.at(j).numRoom).roomName.size(); k++) {
				if (rooms.at(currentScheduleCalcFitness.sampleActivities.at(j).numRoom).roomName.at(k) == ' ') {
					break;
				}
				else {
					tempLocationCurrentActivity.push_back(rooms.at(currentScheduleCalcFitness.sampleActivities.at(j).numRoom).roomName.at(k));
				}
			}
			//Fitness Value, Find and Compare Time Slots of other Multiple Sections
			for (int k = 0; k < pairsDoubleActivities.size(); k++) {
				if ((activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).activityName
					== pairsDoubleActivities.at(k).first) || (activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).activityName
						== pairsDoubleActivities.at(k).second)) {
					continue;
				}
				else {
					int tempTimeSlotSectionOne;
					int tempTimeSlotSectionTwo;
					string tempLocationSectionOne = "";
					string tempLocationSectionTwo = "";
					for (int a = 0; a < activities.size(); a++) {
						if (pairsDoubleActivities.at(k).first == activities.at(a).activityName) {
							tempTimeSlotSectionOne = currentScheduleCalcFitness.sampleActivities.at(a).numSlotTime;
							for (int s = 0; s < rooms.at(currentScheduleCalcFitness.sampleActivities.at(a).numRoom).roomName.size(); s++) {
								if (rooms.at(currentScheduleCalcFitness.sampleActivities.at(a).numRoom).roomName.at(s) == ' ') {
									break;
								}
								else {
									tempLocationSectionOne.push_back(rooms.at(currentScheduleCalcFitness.sampleActivities.at(a).numRoom).roomName.at(s));
								}
							}
						}
						else if (pairsDoubleActivities.at(k).second == activities.at(a).activityName) {
							tempTimeSlotSectionTwo = currentScheduleCalcFitness.sampleActivities.at(a).numSlotTime;
							for (int s = 0; s < rooms.at(currentScheduleCalcFitness.sampleActivities.at(a).numRoom).roomName.size(); s++) {
								if (rooms.at(a).roomName.at(s) == ' ') {
									break;
								}
								else {
									tempLocationSectionTwo.push_back(rooms.at(currentScheduleCalcFitness.sampleActivities.at(a).numRoom).roomName.at(s));
								}
							}
						}
					}
					if (currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime == tempTimeSlotSectionOne) {
						testFitnessValueActivity -= 0.25;
					}
					else if (currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime == tempTimeSlotSectionTwo) {
						testFitnessValueActivity -= 0.25;
					}
					if (abs(currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime - tempTimeSlotSectionOne) == 1) {
						testFitnessValueActivity += 0.5;
						if (((tempLocationSectionOne == "Roman" && (tempLocationCurrentActivity != "Roman" && tempLocationCurrentActivity != "Beach")) 
							|| (tempLocationSectionOne == "Beach" && (tempLocationCurrentActivity != "Roman" && tempLocationCurrentActivity != "Beach")))
							|| ((tempLocationCurrentActivity == "Roman" && (tempLocationSectionOne != "Roman" && tempLocationSectionOne != "Beach"))
							|| (tempLocationCurrentActivity == "Beach" && (tempLocationSectionOne != "Roman" && tempLocationSectionOne != "Beach")))) {
							testFitnessValueActivity -= 0.4;
						}
					}
					else if (abs(currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime - tempTimeSlotSectionTwo) == 1) {
						testFitnessValueActivity += 0.5;
						if (((tempLocationSectionTwo == "Roman" && (tempLocationCurrentActivity != "Roman" && tempLocationCurrentActivity != "Beach")) 
							|| (tempLocationSectionTwo == "Beach" && (tempLocationCurrentActivity != "Roman" && tempLocationCurrentActivity != "Beach")))
							|| ((tempLocationCurrentActivity == "Roman" && (tempLocationSectionTwo != "Roman" && tempLocationSectionTwo != "Beach"))
							|| (tempLocationCurrentActivity == "Beach" && (tempLocationSectionTwo != "Roman" && tempLocationSectionTwo != "Beach")))) {
							testFitnessValueActivity -= 0.4;
						}
					}
					if (abs(currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime - tempTimeSlotSectionOne) == 2) {
						testFitnessValueActivity += 0.25;
					}
					else if (abs(currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime - tempTimeSlotSectionTwo) == 2) {
						testFitnessValueActivity += 0.25;
					}
				}
			}

		}
			
		//For All Activities
		//Same Time Same Room Fitness Adjustments
		for (int k = 0; k < currentScheduleCalcFitness.sampleActivities.size(); k++) {
			if ((currentScheduleCalcFitness.sampleActivities.at(k).numSlotTime ==
				currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime) &&
				(currentScheduleCalcFitness.sampleActivities.at(k).numRoom ==
					currentScheduleCalcFitness.sampleActivities.at(j).numRoom) && (k != j)) {
				testFitnessValueActivity -= 0.5;
			}
		}
		//Room Size Fitness Adjustments
		if (rooms.at(currentScheduleCalcFitness.sampleActivities.at(j).numRoom).capacityRoom <
			activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).capacityActivity) {
			testFitnessValueActivity -= 0.5;
		}
		else if (rooms.at(currentScheduleCalcFitness.sampleActivities.at(j).numRoom).capacityRoom >
			(6 * activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).capacityActivity)) {
			testFitnessValueActivity -= 0.4;
		}
		else if (rooms.at(currentScheduleCalcFitness.sampleActivities.at(j).numRoom).capacityRoom >
			(3 * activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).capacityActivity)) {
			testFitnessValueActivity -= 0.2;
		}
		else {
			testFitnessValueActivity += 0.3;
		}
		//Facilitators Fitness Adjustments
		bool inPrefFacilitators = false;
		bool inOtherFacilitators = false;
		for (int a = 0; a < activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).prefFacilitators.size(); a++) {
			if (facilitators.at(currentScheduleCalcFitness.sampleActivities.at(j).numFacilitator) ==
				activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).prefFacilitators.at(a)) {
				testFitnessValueActivity += 0.5;
				inPrefFacilitators = true;
				break;
			}
		}
		if (inPrefFacilitators == false) {
			for (int a = 0; a < activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).otherFacilitators.size(); a++) {
				if (facilitators.at(currentScheduleCalcFitness.sampleActivities.at(j).numFacilitator) ==
					activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).otherFacilitators.at(a)) {
					testFitnessValueActivity += 0.2;
					inOtherFacilitators = true;
					break;
				}
			}
		}
		if (inPrefFacilitators == false && inOtherFacilitators == false) {
			testFitnessValueActivity -= 0.1;
		}
		//Facilitators Load Fitness Adjustments
		int totalActivityFacilitatorOversees = 0;
		int totalActivityFacilitatorOverseesTimeSlot = 0;
		for (int a = 0; a < currentScheduleCalcFitness.sampleActivities.size(); a++) {
			if (currentScheduleCalcFitness.sampleActivities.at(a).numFacilitator ==
				currentScheduleCalcFitness.sampleActivities.at(j).numFacilitator) {
				totalActivityFacilitatorOversees += 1;
			}
			if ((currentScheduleCalcFitness.sampleActivities.at(a).numSlotTime ==
				currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime) &&
				(currentScheduleCalcFitness.sampleActivities.at(a).numFacilitator ==
					currentScheduleCalcFitness.sampleActivities.at(j).numFacilitator)) {
				totalActivityFacilitatorOverseesTimeSlot += 1;
			}
		}
		if (totalActivityFacilitatorOverseesTimeSlot == 1) {
			testFitnessValueActivity += 0.2;
		}
		else if (totalActivityFacilitatorOverseesTimeSlot > 1) {
			testFitnessValueActivity -= 0.2;
		}
		if (totalActivityFacilitatorOversees > 4) {
			testFitnessValueActivity -= 0.5;
		}
		else if ((totalActivityFacilitatorOversees == 1 || totalActivityFacilitatorOversees == 2) &&
			facilitators.at(currentScheduleCalcFitness.sampleActivities.at(j).numFacilitator) != "Tyler") {
			testFitnessValueActivity -= 0.4;
		}
		//Fitness Value, Find and Compare Time Slots For a Facilitator for Consecutive Time Slots and Location
		string tempLocationCurrentActivity = "";
		for (int k = 0; k < rooms.at(currentScheduleCalcFitness.sampleActivities.at(j).numRoom).roomName.size(); k++) {
			if (rooms.at(currentScheduleCalcFitness.sampleActivities.at(j).numRoom).roomName.at(k) == ' ') {
				break;
			}
			else {
				tempLocationCurrentActivity.push_back(rooms.at(currentScheduleCalcFitness.sampleActivities.at(j).numRoom).roomName.at(k));
			}
		}
		for (int k = 0; k < currentScheduleCalcFitness.sampleActivities.size(); k++) {
			if (activities.at(currentScheduleCalcFitness.sampleActivities.at(j).numActivity).activityName
				== activities.at(k).activityName) {
				continue;
			}
			else if ((currentScheduleCalcFitness.sampleActivities.at(k).numFacilitator ==
				currentScheduleCalcFitness.sampleActivities.at(j).numFacilitator) &&
				(abs(currentScheduleCalcFitness.sampleActivities.at(j).numSlotTime - 
					currentScheduleCalcFitness.sampleActivities.at(k).numSlotTime) == 1)) {
					testFitnessValueActivity += 0.5;
				int tempTimeSlotNum = currentScheduleCalcFitness.sampleActivities.at(k).numSlotTime;
				string tempLocationActivityName = "";
				for (int a = 0; a < rooms.at(currentScheduleCalcFitness.sampleActivities.at(k).numRoom).roomName.size(); a++) {
					if (rooms.at(currentScheduleCalcFitness.sampleActivities.at(k).numRoom).roomName.at(a) == ' ') {
						break;
					}
					else {
						tempLocationActivityName.push_back(rooms.at(currentScheduleCalcFitness.sampleActivities.at(k).numRoom).roomName.at(a));
					}
				}
				if (((tempLocationActivityName == "Roman" && (tempLocationCurrentActivity != "Roman" && tempLocationCurrentActivity != "Beach"))
					|| (tempLocationActivityName == "Beach" && (tempLocationCurrentActivity != "Roman" && tempLocationCurrentActivity != "Beach")))
					|| ((tempLocationCurrentActivity == "Roman" && (tempLocationActivityName != "Roman" && tempLocationActivityName != "Beach"))
					|| (tempLocationCurrentActivity == "Beach" && (tempLocationActivityName != "Roman" && tempLocationActivityName != "Beach")))) {
					testFitnessValueActivity -= 0.4;
				}
			}
		}
		fitnessValueTotal += testFitnessValueActivity;
	}
	return fitnessValueTotal;
};

//Generate Fitness Scores for each Schedule
void GeneticAlgorithm::generateFitnessScoresForSchedules() {
	double currentScheduleFitnessValue = 0;
	double currentFitnessTotal = 0;
	for (int i = 0; i < sampleSchedules.size(); i++) {
		currentScheduleFitnessValue = 0;
		currentScheduleFitnessValue += calcFitnessForSchedule(sampleSchedules.at(i));			
		sampleSchedules.at(i).fitness = currentScheduleFitnessValue;
		currentFitnessTotal += currentScheduleFitnessValue;
	}
	if (currGeneration != 0) {
		cout << "CurrentFitnessAvg: " << currentFitnessTotal / sampleSchedules.size() << endl;
	}
	generationsAvgFitness.push_back(currentFitnessTotal / sampleSchedules.size());
};

//Sort Schedules by fitness Scores (Highest First, Lowest Last)
void GeneticAlgorithm::sortFitnessScoresByHighest() {
	for (int i = 0; i < sampleSchedules.size(); i++) {
		int tempCurrSortPos = i;
		for (int j = i; j < sampleSchedules.size(); j++) {
			if (sampleSchedules.at(j).fitness > sampleSchedules.at(tempCurrSortPos).fitness) {
				tempCurrSortPos = j;
			}
		}
		if (tempCurrSortPos != i) {
			swap(sampleSchedules.at(i), sampleSchedules.at(tempCurrSortPos));
		}
	}
};

//Calculate the Softmax for each Schedule (Probability Distribution) 
void GeneticAlgorithm::calcSoftMaxSchedules() {
	double sumFitnessScheduleExponentialScores = 0;
	for (int i = 0; i < sampleSchedules.size(); i++) {
		double tempExpNum = (exp(sampleSchedules.at(i).fitness));
		sumFitnessScheduleExponentialScores += tempExpNum;
		softMaxSchedulesExponentials.push_back(tempExpNum);
	}
	for (int i = 0; i < softMaxSchedulesExponentials.size(); i++) {
		softmaxSchedulesProbability.push_back(((softMaxSchedulesExponentials.at(i)) / sumFitnessScheduleExponentialScores));
	}
};



//Calculate probability evaluations and probability sum for each Schedule to be used for Random Selection of a parent schedule to produce an offspring
void GeneticAlgorithm::calcSoftmaxSchedulesProbabilityDistributionForRNG() {
	double softMaxProbDistTotal = 0;
	for (int i = 0; i < softmaxSchedulesProbability.size(); i++) {
		softMaxProbDistTotal += softmaxSchedulesProbability.at(i);
		softmaxSchedulesProbabilityDistributionForRNG.push_back(softMaxProbDistTotal);
	}
};

//Get Random Parent Schedule from current sample population using the Probability Distribution for reproduction
int GeneticAlgorithm::randomProbDistNumParentSchedule() {
	int scheduleParentNum = 0;
	double randNumParent = (double)(rand() / (double)RAND_MAX);
	for (int i = 0; i < softmaxSchedulesProbabilityDistributionForRNG.size(); i++) {
		if (i == 0) {
			if ((randNumParent >= 0) && (randNumParent < softmaxSchedulesProbabilityDistributionForRNG.at(i))) {
				scheduleParentNum = i;
				break;
			}
		}
		else {
			if ((randNumParent >= softmaxSchedulesProbabilityDistributionForRNG.at(i - 1)) && (randNumParent < softmaxSchedulesProbabilityDistributionForRNG.at(i))) {
				scheduleParentNum = i;
				break;
			}
		}
	}
	return scheduleParentNum;
};

//Take two parent Schedules of current sample Population, Use Crossover Combination to take half of each parent, produces child Schedule 
void GeneticAlgorithm::calcOffspringScheduleFromParents(sampleSchedule scheduleParentOne, sampleSchedule scheduleParentTwo) {
	int scheduleParentSizeHalf = 0;
	int scheduleParentSize = scheduleParentOne.sampleActivities.size();
	sampleSchedule scheduleOffspringFirst;
	sampleSchedule scheduleOffspringSecond;
	vector<sampleSchedule> offspringVectorsCheckForMutation;
	bool mutationRandomItem;
	int randomCrossoverLine = (rand() % (scheduleParentOne.sampleActivities.size()-1) + 1);
	for (int i = 0; i < randomCrossoverLine; i++) {
		scheduleOffspringFirst.sampleActivities.push_back(scheduleParentOne.sampleActivities.at(i));
		scheduleOffspringSecond.sampleActivities.push_back(scheduleParentTwo.sampleActivities.at(i));
	}
	for (int i = randomCrossoverLine; i < scheduleParentSize; i++) {
		scheduleOffspringFirst.sampleActivities.push_back(scheduleParentTwo.sampleActivities.at(i));
		scheduleOffspringSecond.sampleActivities.push_back(scheduleParentOne.sampleActivities.at(i));
	}
	offspringVectorsCheckForMutation.push_back(scheduleOffspringFirst);
	offspringVectorsCheckForMutation.push_back(scheduleOffspringSecond);
	//Get Random Mutation Value. If True, for the activity at that slot, Get Random (Room, SlotTime, Facilitator).
	for (int i = 0; i < offspringVectorsCheckForMutation.size(); i++) {
		for (int j = 0; j < offspringVectorsCheckForMutation.at(i).sampleActivities.size(); j++) {
			mutationRandomItem = randomMutationRate();
			if (mutationRandomItem == true) {
				offspringVectorsCheckForMutation.at(i).sampleActivities.at(j).numRoom = randomRoom();
				offspringVectorsCheckForMutation.at(i).sampleActivities.at(j).numSlotTime = randomSlotTime(offspringVectorsCheckForMutation.at(i).sampleActivities.at(j).numRoom);
				offspringVectorsCheckForMutation.at(i).sampleActivities.at(j).numFacilitator = randomFacilitator();
			}
		}
	}
	//Add New Offspring to New Generation
	for (int i = 0; i < offspringVectorsCheckForMutation.size(); i++) {
		newGenerationSchedules.push_back(offspringVectorsCheckForMutation.at(i));
	}
};

//Calculates Generations of schedules for given Generation Number
void GeneticAlgorithm::calcGenerationsSchedules() {
	bool ifGenerationOver100LessThan1 = false;
	while (currGeneration < numGenerations+400) { 
		newGenerationSchedules.clear();
		softMaxSchedulesExponentials.clear();
		softmaxSchedulesProbability.clear();
		softmaxSchedulesProbabilityDistributionForRNG.clear();
		
		calcSoftMaxSchedules();
		calcSoftmaxSchedulesProbabilityDistributionForRNG();
		for (int i = 0; i < (sampleSize / 2); i++) {
			calcOffspringScheduleFromParents(sampleSchedules.at(randomProbDistNumParentSchedule()), 
				sampleSchedules.at(randomProbDistNumParentSchedule()));
		}
		sampleSchedules = newGenerationSchedules;
		generateFitnessScoresForSchedules();
		sortFitnessScoresByHighest();
		currGeneration++;
		cout << endl << "Generation Number : " << currGeneration << endl;
		cout << "Generation Best Schedule Fitness: " << sampleSchedules.at(0).fitness << endl;

		if (currGeneration >= numGenerations) {
			double generationsG100PercentDiff = ((generationsAvgFitness.at(currGeneration) - generationsAvgFitness.at((currGeneration - numGenerations))) /
				generationsAvgFitness.at((currGeneration - numGenerations)));
			cout << "Generation Fitness Percent Change (G-100): " << generationsAvgFitness.at(currGeneration)  << " " << generationsAvgFitness.at((currGeneration - numGenerations)) 
				<< " " << generationsG100PercentDiff * 100 << endl;
			if (generationsG100PercentDiff < 0.01) {
				ifGenerationOver100LessThan1 = true;
				break;
			}
		}
	}
};

//Called to run Genetic Algorithm and return a Final and "Best" Schedule
void GeneticAlgorithm::generateSchedule() {
	returnInputDataText();
	generateRandomStartPopulationSchedules();
	returnBestScheduleText();
	calcGenerationsSchedules();
	returnBestScheduleText();
	returnFinalScheduleOutputFile();
};

//Returns Output Data of the Genetic Algorithm for Schedules
void GeneticAlgorithm::returnInputDataText()
{
	cout << endl << "Appendix: " << endl;
	for (int i = 0; i < appendix.size(); i++) {
		cout << "\t" << appendix.at(i).first << " " << appendix.at(i).second << endl;
	}
	cout << "Activities: " << endl;
	for (int i = 0; i < activities.size(); i++) {
		cout << "\t" << activities.at(i).activityName << ", " << activities.at(i).capacityActivity << ", Pref:";
		for (int j = 0; j < activities.at(i).prefFacilitators.size(); j++) {
			cout << " " << activities.at(i).prefFacilitators.at(j);
		}
		cout << ", Other:";
		for (int j = 0; j < activities.at(i).otherFacilitators.size(); j++) {
			cout << " " << activities.at(i).otherFacilitators.at(j);
		}
		cout << endl;
	}
	cout << "Facilitators: " << endl;
	for (int i = 0; i < facilitators.size(); i++) {
		cout << "\t" << facilitators.at(i) << endl;
	}
	cout << "Rooms: " << endl;
	for (int i = 0; i < rooms.size(); i++) {
		cout << "\t" << rooms.at(i).roomName << " " << rooms.at(i).capacityRoom << " ";
		for (int j = 0; j < rooms.at(i).times.size(); j++) {
			cout << rooms.at(i).times.at(j) << " ";
		}
		cout << endl;
	}
}

//Output Best Schedule Text
void GeneticAlgorithm::returnBestScheduleText() {
	cout << endl<< "Best Schedule Generation: " << endl;
	for (int j = 0; j < sampleSchedules.at(0).sampleActivities.size(); j++) {
		cout << activities.at(sampleSchedules.at(0).sampleActivities.at(j).numActivity).activityName << "   "
			<< rooms.at(sampleSchedules.at(0).sampleActivities.at(j).numRoom).roomName << "   "
			<< rooms.at(sampleSchedules.at(0).sampleActivities.at(j).numRoom).times.
			at(sampleSchedules.at(0).sampleActivities.at(j).numSlotTime) << "   "
			<< facilitators.at(sampleSchedules.at(0).sampleActivities.at(j).numFacilitator) << endl;
	}
	cout << endl << "Fitness Value: " << sampleSchedules.at(0).fitness << endl << endl;
};

//Return Final and "Best" Schedule to an Output Text File
void GeneticAlgorithm::returnFinalScheduleOutputFile() {
	ofstream ofFinalSchedule;
	ofFinalSchedule.open("BestScheduleResults.txt");
	if (!ofFinalSchedule.is_open()) {
		cout << "Could not open file" << endl;
	}
	ofFinalSchedule << "Final Schedule " << endl;
	for (int j = 0; j < sampleSchedules.at(0).sampleActivities.size(); j++) {
		ofFinalSchedule << "\t" << activities.at(sampleSchedules.at(0).sampleActivities.at(j).numActivity).activityName << "   "
			<< rooms.at(sampleSchedules.at(0).sampleActivities.at(j).numRoom).roomName << "   "
			<< rooms.at(sampleSchedules.at(0).sampleActivities.at(j).numRoom).times.
			at(sampleSchedules.at(0).sampleActivities.at(j).numSlotTime) << "   "
			<< facilitators.at(sampleSchedules.at(0).sampleActivities.at(j).numFacilitator) << endl;
	}
	ofFinalSchedule << endl << "Fitness Value: " << sampleSchedules.at(0).fitness << endl << endl;
	ofFinalSchedule.close();
}