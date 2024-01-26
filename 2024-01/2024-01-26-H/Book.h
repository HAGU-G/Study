#pragma once
#include <string>

class Book
{
private:
	char* title;
	char* author;
	int pages;
public:

	Book(const char* title,const char* author, int pages = 0);
	Book(const Book& ref);
	Book(Book&& ref) noexcept;

	~Book();
	void displayInfo() const;


	Book& operator=(const Book& ref);
	Book& operator=(Book&& ref) noexcept;
};

