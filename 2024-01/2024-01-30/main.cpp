#include <iostream>

class Base
{
public:
	virtual void func()
	{

	}
};


class Derived : public Base
{

};

class Derived2 : public Base
{

};

int main()
{

	Derived* d = new Derived();
	Base* b = d;
	Derived2* d2 = new Derived2();
	
	b = dynamic_cast<Derived*>(b);
	d = dynamic_cast<Derived*>(d2); //예외 상황
	
	if (d == nullptr)
	{
		std::cout << 0 << std::endl;
	}
	else
	{
		std::cout << 1 << std::endl;
	}

	return 0;
}