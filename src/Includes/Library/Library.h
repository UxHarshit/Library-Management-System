#pragma once
#include <Globals.h>
#include <Library/Book.h>

class Library
{
private:
	map<string, Book> books;
	const string filename = "books.txt";
public:

	Library() {
		ifstream file(filename);
		//Book::loadBookDetails(file);
	}
};