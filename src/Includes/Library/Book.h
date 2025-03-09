#pragma once
#include <Globals.h>

class Book {
private:
	string title;
	string author;
	string isbn;
	string publisher;
	int copies;
public:
	void getBookDetails() {
		console.SetColor(DARK_BLUE);
		cin.ignore();
		console.Write(L"Enter the title of the book: ");
		getline(cin, title);
		console.Write(L"Enter the author of the book: ");
		getline(cin, author);
		console.Write(L"Enter the ISBN of the book: ");
		getline(cin, isbn);
		console.Write(L"Enter the publisher of the book: ");
		getline(cin, publisher);
		console.Write(L"Enter the number of copies: ");
		cin >> copies;
	}

	void displayBookDetails() {
		console.SetColor(DARK_BLUE);
		console.WriteLine(("Title: " + this->title).c_str());
		console.WriteLine(("Author: " + this->author).c_str());
		console.WriteLine(("ISBN: " + this->isbn).c_str());
		console.WriteLine(("Publisher: " + this->publisher).c_str());
		console.WriteLine(("Copies: " + to_string(this->copies)).c_str());
		console.WriteLine(L"");
	}

	void saveBookDetails(ofstream& file) {
		file << this->title << endl;
		file << this->author << endl;
		file << this->isbn << endl;
		file << this->publisher << endl;
		file << this->copies << endl;
	}

	void loadBookDetails(ifstream& file) {
		getline(file, this->title);
		getline(file, this->author);
		getline(file, this->isbn);
		getline(file, this->publisher);
		file >> this->copies;
	}

};