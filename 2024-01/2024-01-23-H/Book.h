#pragma once
#include <string>

class Book
{
private:
	std::string title;
	std::string author;
	int pages;
public:

	Book(std::string title = "", std::string author = "", int pages = 0) : title(title), author(author), pages(pages);
};

