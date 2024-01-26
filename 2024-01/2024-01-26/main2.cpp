#include <iostream>
#include "Item.h"


int main()
{

	Item a1 = (Item)"";
	Item a2(10, "ABC");
	Item a = 1;

	int num = (int)a2; //형변환 오버로딩이 되어있으므로 오류가 발생하지 않는다.
	int num1 = a2;
	std::string str2 = a2;


	std::cout << num << num1 << str2 << std::endl;

	return 0;
}