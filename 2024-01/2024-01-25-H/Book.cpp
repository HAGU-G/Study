#include "Book.h"
#include <iostream>

Book::Book(const char* title, const char* author, int pages) : title(nullptr), author(nullptr), pages(pages)
{
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);
}

Book::~Book()
{
	delete[] title;
	delete[] author;
	title = nullptr;
	author = nullptr;
}

void Book::displayInfo() const
{
	std::cout << "Book: " << title << std::endl << "Author: " << author << std::endl << "Pages: " << pages << std::endl;
}
