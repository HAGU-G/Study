#include "Book.h"
#include <iostream>

Book::Book(std::string title, std::string author, int pages) : title(title), author(author), pages(pages)
{
}

void Book::displayInfo()
{
	std::cout << "Book: " << title << std::endl << "Author: " << author << std::endl << "Pages: " << pages << std::endl;
}
