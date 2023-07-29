//Luke Talcott
//ldt9gn@mail.umkc.edu
//4/17/2019
//Program 4 - Recursive

#include <string>
#include <iostream>
using namespace std;

//Program starts with 13 tokens, takes tokens you want to reach and within how many turns you can get to it, with a limit of turns and if at all, and returns within how many if possible.  

//Recursive function to run token taking game. Takes starting tokens goal and how many turns to be completed in and auto starts tokens at 13. Runs until goal found or turns run out and returns the result.
void TokenTakingGame(int tokensGoal, int turnsLeft, int totalTokens = 13) {
	//If tokens goal found, lets user know with how many turn remaing.
	if (totalTokens == tokensGoal) {
		cout << "\nSolution found with " << turnsLeft << " turn(s) remaining." << endl;
	}
	//If solution never found and turns run out, lets the user know not found within the number of turns given.
	else if (turnsLeft == 0) {
		cout << "Sorry, solution wasn't found within allotted turns." << endl;
	}
	//Checks if tokens is divisible evenly. If so, returns the the function itself with the total tokens cut in half.
	else if (totalTokens % 2 == 0) {
		totalTokens /= 2;
		cout << "Reducing by half, you get " << totalTokens << " tokens." << endl;
		TokenTakingGame(tokensGoal, turnsLeft - 1, totalTokens);
	}
	//Lastly, after all other options are checked, adds 25 tokens to the current amount and runs itself recursively again.
	else {
		totalTokens += 25;
		cout << "Adding 25, you get " << totalTokens << " tokens." << endl;
		TokenTakingGame(tokensGoal, turnsLeft - 1, totalTokens);
	}
}

//Main function to run program.
int main() {
	//Variables used.
	int numTokensGoal;
	int numTurns;
	char playGame = 'Y';

	//Runs with a do while loop.
	do {
		//Runs switch loop to continously play the token game until N is entered to stop playing.
		switch (playGame) {

		//If Y entered are eaquals the character, asks user for tokens goal and number turns it would liked to be found in and runs the recursive funtion.
		case 'Y':
			cout << "Enter the number of tokens you want to reach:" << endl;
			cin >> numTokensGoal;

			cout << "What is the number of turns:" << endl;
			cin >> numTurns;

			cout << "Searching for solution within " << numTurns << " turn(s)..." << endl;

			TokenTakingGame(numTokensGoal, numTurns);

			cout << "Would you like to play again? [Y/N]" << endl;
			cin >> playGame;
			break;

		//Output to let user know to enter y or n if not entered before.
		default:
			cout << "You must enter valid option." << endl;
			cout << "Would you like to play again? [Y/N]" << endl;
			cin >> playGame;
		}

		playGame = toupper(playGame);

		//Runs until char enterd eqauls N.
	} while (playGame != 'N');
	
	//Once player decides to stop playing with N, outputs message and ends.
	cout << "Thanks for playing!" << endl;

	system("pause");
	return 0;
}