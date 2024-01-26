#include "Item.h"
#include <iostream>

Item::Item()
	: num(0)
{
	std::cout << "Item()" << std::endl;
}

Item::Item(int n)
	: num(n)
{
	std::cout << "Item(int n)" << std::endl;
}

Item::Item(const std::string& s)
	: name(s)
{
	std::cout << "Item(const std::string& s)" << std::endl;
}

Item::Item(int n, const std::string& s)
	: num(n), name(s)
{
	std::cout << "Item(int n, const std::string& s)" << std::endl;
}

Item::operator int() const
{
	return num;
}

Item::operator std::string() const
{
	return name;
}
