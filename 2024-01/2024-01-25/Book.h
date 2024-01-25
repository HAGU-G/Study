#pragma once
#include <string>
class Book
{
private:
	std::string title;
	std::string author;
	int pages;
public:
	Book(const std::string& title, const std::string& author, int pages);

	void displayInfo();
};

