//Luke Talcott
//2/9/2019
//CS201
//Program 1

#include <iostream>
#include "string"
#include <cstdlib>
#include <ctime>
using namespace std;

int RollDie() {
	int number = 0;

	number = ((rand() % 6) + 1);
	cout << "Die Roll : " << number;

	return number;
}

char rollAgain() {
	char decision;
	int x = 0;

	cout << "    (R)oll again or (H)old? ";

	while (x == 0) {
		cin >> decision;
		cin.ignore();
		decision = toupper(decision);

		switch (decision) {
		case 'R':
			x += 1;
			break;

		case 'H':
			x += 1;
			break;

		default:
			cout << "\nYou must enter R or H" << endl;
			cout << "    (R)oll again or (H)old? ";
		}
	}
	return decision;
}

int main() {
	int x = 0;
	int s = 0;
	int a = 0;
	int e = 0;
	int userScore = 0;
	int AIScore = 0;
	string turn = "Player's Turn";
	int pot = 0;
	int numDie;
	char userChoice;
	char playAgain;

	srand(time(0));

	while (a == 0) {
		x = 0;
		e = 0;
		userScore = 0;
		AIScore = 0;

		while (x == 0) {
			cout << "\nScore   You : " << userScore << " AI : " << AIScore << endl;
			cout << endl;
			s = 0;
			pot = 0;

			if (turn == "Player's Turn") {
				cout << "\nPlayer's Turn	Hit enter to continue ";
				cin.ignore();

				while (s == 0) {
					numDie = RollDie();
					pot += numDie;

					if ((pot + userScore) >= 50) {
						cout << "     Pot : " << pot << "   no need to keep rollng" << endl;
						s += 1;
						x += 1;
						userScore += pot;
					}

					else if (numDie != 1) {
						cout << "    Pot : " << pot;
						userChoice = rollAgain();

						if (userChoice == 'H') {
							cout << endl;
							userScore += pot;
							s += 1;
							turn = "AI Turn";
						}
					}
					else if (numDie == 1) {
						cout << " : BUST\n" << endl;
						s += 1;
						turn = "AI Turn";
					}
				}
			}

			else if (turn == "AI Turn") {
				cout << "\nAI Turn   Hit enter to continue ";
				cin.ignore();

				while (s == 0) {
					numDie = RollDie();
					pot += numDie;

					if ((pot + AIScore) >= 50) {
						cout << "    Pot : " << pot << "   no need for AI to keep rolling" << endl;
						s += 1;
						x += 1;
						AIScore += pot;
					}

					else if (numDie != 1) {
						cout << "    Pot : " << pot << endl;

						if (pot >= 20) {
							AIScore += pot;
							s += 1;
							turn = "Player's Turn";
						}
					}

					else if (numDie == 1) {
						cout << " : BUST\n" << endl;
						s += 1;
						turn = "Player's Turn";
					}
				}
			}
		}

		if (turn == "Player's Turn") {
			cout << "\n\nCongratulations you won !!!\n" << endl;
		}

		else if (turn == "AI Turn") {
			cout << "\n\nAI won\n" << endl;
		}

		cout << "Final Score   You : " << userScore << "   AI : " << AIScore << endl;
		x += 1;

		while (e == 0) {
			cout << "\nDo you want to play the game again? Y or N ";
			cin >> playAgain;
			playAgain = toupper(playAgain);

			switch (playAgain) {
			case 'Y':
				turn = "AI Turn";
				e += 1;
				cin.ignore();
				break;

			case 'N':
				a += 1;
				e += 1;
				break;

			default:
				cout << "\nYou must only enter Y or N." << endl;
			}
		}

	}
	return 0;
}
