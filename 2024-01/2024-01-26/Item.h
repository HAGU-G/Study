#pragma once
#include <string>
class Item
{
private:
	int num;
	std::string name;

public:
	Item();
	explicit Item(int n);
	Item(const std::string& s);
	Item(int n, const std::string& s);

	operator int() const; //int�� ����ȯ ������ �����ε�
	operator std::string() const; //string�� ����ȯ ������ �����ε�
};

