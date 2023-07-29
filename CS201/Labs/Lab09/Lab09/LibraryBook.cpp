// Luke Talcott
// ldt9gn@mail.umkc.edu
// 3/20/19
// CS201L Lab 09
#include "LibraryBook.h"
//#include <iostream>
//#include <string>
//using namespace std;

//All functions and the constructors for the class LibraryBook.

//Sets orginal variables in class blank and checkedout to false when created.
LibraryBook::LibraryBook() {
	checkedOut = false;
	title = " ";
	author = " ";
	ISBN = " ";
}

//sets the input variables to the clase of title, author and isbn for the assigned variables in the class and checkedout to false when the object is made.
LibraryBook::LibraryBook(string Title, string Author, string isbn) {
	title = Title;
	author = Author;
	ISBN = isbn;
	checkedOut = false;
}

//Checkout sets the oject book for the class to checked-out by setting the variable checkedout to true.
void LibraryBook::CheckOut() {
	checkedOut = true;
}

//Checkedin sets the object book for the class checked-in by setting the variable to checkedin to true.
void LibraryBook::CheckIn() {
	checkedOut = false;
}

//Returns the title of the object book.
string LibraryBook::getTitle() {
	return title;
}

//Returns the author of the object book.
string LibraryBook::getAuthor() {
	return author;
}

//Returns the ISBN of the object book.
string LibraryBook::getISBN() {
	return ISBN;
}

//Checks to see if the object book is checked in or checked out.
bool LibraryBook::IsCheckedOut() {
	return checkedOut;
}