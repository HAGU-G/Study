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

	operator int() const; //int형 형변환 연산자 오버로딩
	operator std::string() const; //string형 형변환 연산자 오버로딩
};

