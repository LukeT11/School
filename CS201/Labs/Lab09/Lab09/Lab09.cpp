// Luke Talcott
// ldt9gn@mail.umkc.edu
// 3/20/19
// CS201L Lab 09

#include "LibraryBook.h";
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <vector>

//Main function to run the program.

//Vectors, strings, input file variable, output file variable used for the program.
int main() {
	ifstream file;
	ofstream output;
	string title;
	string author;
	string ISBN;
	vector<LibraryBook> books;
	string theISBN;

//Opens the input file "books.txt" 
	file.open("books.txt");

//Checks to see if the file could be opened. If it couldn't, returns an error and ends the program.
	if (!file.is_open()) {
		cout << "Could not open" << endl;
		return 1;
	}

//While loop to read everything out file until end of file is reached, creating objects for books to a class using the information of a book's title, author, and ISBN number. Entering each object into a vector.
	while (!file.eof()) {
		getline(file, title);
		getline(file, author);
		getline(file, ISBN);

		LibraryBook myBook(title, author, ISBN);
		books.push_back(myBook);
	}

//Closes the file when finished.
	file.close();

//Opens the input file "isbns.txt" to check ISBN's for books in and out.
	file.open("isbns.txt");

//Checks to see if the file could be opened. If it couldn't, returns an error and ends the program.
	if (!file.is_open()) {
		cout << "Could not open" << endl;
		return 1;
	}

//Runs a while loop until the end of the file is reached. It grabs the ISBN from the input file, compares it to the vector of books and there ISBN's until it finds the book. Then it checks it in or out depending if it has been previously checked out or not.
	while (!file.eof()) {
		file >> theISBN;

		for (int i = 0; i < books.size(); i++) {
			if (books.at(i).getISBN() == theISBN) {
				if (books.at(i).IsCheckedOut()) {
					books.at(i).CheckIn();
				} else {
					books.at(i).CheckOut();
				}
			}
		}
	}

//Closes the file when end of file is reached.
	file.close();

//Opens the input file "checkedout.txt" to output books that are currently checkedout.
	output.open("checkedout.txt");

//Checks to see if the file could be opened. If it couldn't, returns an error and ends the program.
	if (!output.is_open()) {
		cout << "Could not open" << endl;
		return 1;
	}

//Enters in set information to format the output file.
	output << "Books checked out:" << "\n" << endl;
	output << "------------------" << "\n\n\n" << endl;
	output << "Title  Author  ISBN" << endl;

//Runs a for loop to check every book object in the vector to see if it is checkedout. If it is checkedout, it outputs the books title, author, and ISBN to the file and adds to the books that are currently checked out.
	for (int i = 0; i < books.size(); i++) {
		if (books.at(i).IsCheckedOut()) {
			output << "\n" << books.at(i).getTitle() << "       ";
			output << books.at(i).getAuthor() << "       ";
			output << books.at(i).getISBN() << endl;
		}
	}

//Closes the output file when all books have been checked.
	output.close();

//Pauses output and return 0 to end the program.
	system("pause");
	return 0;
}