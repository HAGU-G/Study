#include <iostream>

//¸òÀ» ¹İÈ¯ÇÏ´Â ³ª´°¼À ÇÔ¼ö
int Divide(int lhs, int rhs)
{
	if (rhs == 0)
		throw std::invalid_argument("Divide Zero");
	return lhs / rhs;
}

int main()
{
	int input1 = 0;
	int input2 = 0;

	std::cin >> input1 >> input2;


	try
	{
		std::cout << Divide(input1, input2) << std::endl;

	}
	catch (const std::invalid_argument& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "END" << std::endl;

	return 0;
}