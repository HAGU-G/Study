#include <iostream>

struct Base
{
	int a = 1;
};

struct Derived1 : public Base
{
	float x = 3.14;
};

struct Derived2 : public Base
{
	int y = 3;
};

int main()
{
	Base* b = new Derived1();
	Derived1* d1 = static_cast<Derived1*>(b);

	std::cout << d1->x << std::endl;

	Derived2* d2 = (Derived2*)b;
	std::cout << d2->y << std::endl;

	return 0;

}