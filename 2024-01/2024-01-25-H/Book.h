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
	~Book();
	void displayInfo() const;
};

