#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, int pages)
	: title(title), author(author), pages(pages)
{
}

void Book::displayInfo()
{
	std::cout << "Book: " << title << ", Author: " << author << ", Pages: " << pages << std::endl;
}

