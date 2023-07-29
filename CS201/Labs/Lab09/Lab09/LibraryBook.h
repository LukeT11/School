#pragma once
// Luke Talcott
// ldt9gn@mail.umkc.edu
// 3/20/19
// CS201L Lab 09

//#include <iostream>
#include <string>
using namespace std;

//Class LibraryBook used for main program.

class LibraryBook {
	public:
		LibraryBook();
		LibraryBook(string title, string author, string ISBN);
		void CheckOut();
		void CheckIn();
		bool IsCheckedOut();
		string getTitle();
		string getAuthor();
		string getISBN();

	private:
		bool checkedOut;
		string title;
		string author;
		string ISBN;
};

