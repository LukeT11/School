// Luke Talcott
// ldt9gn@mail.umkc.edu
// 3/6/19
// CS201L Lab 07

#include <iostream>
#include "string"
#include <vector>
#include <stdexcept>
#include <cstdlib>
using namespace std;
#include "lab07.h";

//Main function to run program.
int main() { //Vectors and variables used to run program.
	vector<double> miles;
	vector<double> gallons;
	char key = 'Y';
	double total;
	bool yes = true;

	while (yes == true) { //Run until boolean set to false.
		try {//Use this to test inputs to make sure they are acceptable.
			while (key != 'N') { //Run until key eqauls N.

				switch (key) {//Switch statement to keep adding tanks with miles and gallons or to stop.
				case 'Y': //If key equals Y, calls function to ask for miles and gallons. Then asks if they would like to add another tank.
					miles.push_back(GetMiles());
					gallons.push_back(GetGallons());

					cout << "Would you like to enter another tank? (Enter Y or N) ";
					cin >> key;
					cout << endl;
					key = toupper(key);
					break;

				case 'N': //If key equals N, break out of the loop.
					break;

				default: //If key isn't Y or N, keep asking until one is chosen.
					cout << "Enter a valid option. Enter Y or N? ";
					cin >> key;
					cout << endl;
					key = toupper(key);
					break;
				}
			}
			total = GetMPG(miles, gallons); //Calls function to calculate the miles per gallon using the miles and gallons vertex's.

			cout << total << " miles per gallon" << endl; //Prints statment with mpg.

			yes = false; //Sets boolean to false to end the program.
		}

		catch (exception& ok) { //Used this "exception" catch instead so if its on gallons and its not an acceptable input, then it will reset back to asking for miles again and removing the last miles input of the vertex that way miles and gallons vertex's keep the same number of inputs.
			//Tells them the error that gallons input was not acceptable and removes last miles input if there was one in order to keep vertex's balanced the same.
			cout << ok.what() << endl;
			if (miles.size() >= 1) {
				miles.pop_back();
			}
		}

		catch (runtime_error& excpt) { //Catch to let them know miles input not acceptable.
			cout << excpt.what() << endl;
		}
	}

	system("pause");
	return 0;
}
