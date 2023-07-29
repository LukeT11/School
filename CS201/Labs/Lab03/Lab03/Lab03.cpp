//Luke Talcott
//2/6/2019
//lab03
//ldt9gn@mail.umkc.edu

#include <iostream>
#include "string"
using namespace std;

int main() {
	double childrenPrice = 10.95, adultPrice = 19.99, seniorPrice = 18.99, vipPrice = 7.99, totalPrice = 0, allDaysPrice = 0;
	int childrenTickets = 0, adultTickets = 0, seniorTickets = 0, vipTickets = 0;
	int day, x = 0;
	char choice;

	cout << "Welcome to Fun Park Menu System !!" << endl;

	for (day = 1; day <= 3; ++day) {
		childrenTickets = 0, adultTickets = 0, seniorTickets = 0, vipTickets = 0;
		cout << "Starting day " << day << endl;
		x = 0;

		while (x == 0) {
			cout << "Enter (C)hild, (A)dult, (S)enior, (V)IP or (Q)quit >> ";
			cin >> choice;
			choice = toupper(choice);

			switch (choice) {
			case 'C':
				cout << "\nHow many children? ";
				cin >> childrenTickets;
				cout << endl;
				break;

			case 'A':
				cout << "\nHow many adults? ";
				cin >> adultTickets;
				cout << endl;
				break;

			case 'S':
				cout << "\nHow many seniors? ";
				cin >> seniorTickets;
				cout << endl;
				break;

			case 'V':
				cout << "\nHow many VIP? ";
				cin >> vipTickets;
				cout << endl;
				break;

			case 'Q':
				totalPrice = (childrenTickets * childrenPrice) + (adultTickets * adultPrice) + (seniorTickets * seniorPrice) + (vipTickets * vipPrice);

				cout << "\nDay " << day << endl;
				cout << "	Child " << childrenTickets << " @ " << childrenPrice << " = " << (childrenTickets * childrenPrice) << endl;
				cout << "	Adult " << adultTickets << " @ " << adultPrice << " = " << (adultTickets * adultPrice) << endl;
				cout << "	Senior " << seniorTickets << " @ " << seniorPrice << " = " << (seniorTickets * seniorPrice) << endl;
				cout << "	VIP " << vipTickets << " @ " << vipPrice << " = " << (vipTickets * vipPrice) << endl;

				cout << "\n	Total = " << totalPrice << "\n\n";

				allDaysPrice += totalPrice;

				if (day == 3) {
					cout << "\n\nThe total for all days is " << allDaysPrice << "\n\n";
					x += 1;
				}
				else {
					x += 1;
				}
				break;

			default:
				cout << endl;
				break;
			}
		}
	}



	system("pause");
	return 0;

}