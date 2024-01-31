#include <iostream>

class Equals
{
private :
	int number;
public:
	Equals(int n) : number(n)
	{

	}

	bool operator()(int x)
	{
		return number == x;
	}
};

int main()
{
	Equals b(123);
	std::cout << b(12) << std::endl;


	return 0;
}