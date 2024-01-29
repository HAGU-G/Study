#include "Book.h"
#include <iostream>

Book::Book(const char* title, const char* author, int pages) : title(nullptr), author(nullptr), pages(pages)
{
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);
}

Book::Book(const Book& ref)
	:title(nullptr), author(nullptr), pages(ref.pages)
{
	title = new char[strlen(ref.title) + 1];
	strcpy_s(title, strlen(ref.title) + 1, ref.title);
	author = new char[strlen(ref.author) + 1];
	strcpy_s(author, strlen(ref.author) + 1, ref.author);
}

Book::Book(Book&& ref) noexcept
	:title(ref.title), author(ref.author), pages(ref.pages)
{
	ref.title = ref.author = nullptr;
}

Book::~Book()
{
	if (title)
		delete[] title;
	if (author)
		delete[] author;
	title = nullptr;
	author = nullptr;
}

void Book::displayInfo() const
{
	std::cout << "Book: " << title << std::endl << "Author: " << author << std::endl << "Pages: " << pages << std::endl;
}

Book& Book::operator=(const Book& ref)
{
	title = new char[strlen(ref.title) + 1];
	strcpy_s(title, strlen(ref.title) + 1, ref.title);
	author = new char[strlen(ref.author) + 1];
	strcpy_s(author, strlen(ref.author) + 1, ref.author);
	
	return *this;
}

Book& Book::operator=(Book&& ref) noexcept
{
	title = ref.title;
	author = ref.author;
	pages = ref.pages;

	ref.title = ref.author = nullptr;

	return *this;
}
