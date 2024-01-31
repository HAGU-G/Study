#include <iostream>

bool Equals(int num1, int num2)
{
	return num1 == num2;
}
bool NotEquals(int num1, int num2)
{
	return num1 != num2;
}
class Square
{
public:
	int operator()(int n) const
	{
		return n * n;
	}
};
int MyFunc(int n)
{
	return n * (n / 15) / 2;
}

int Sum(int* arr, int size, const Square& sq)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += sq(arr[i]);
	}
	return sum;
}

int main()
{
	bool (*name)(int, int) = nullptr; //함수 포인터 선언
	name = Equals;
	name = NotEquals;

	std::cout << Equals << std::endl;
	std::cout << Equals(1, 2) << std::endl;
	std::cout << name(1, 2) << std::endl;

	//int (*fp)(int) = Square;
	//std::cout << fp(3) << std::endl;

	int arr[5] = { 1,2,3,4,5 };
	std::cout << Sum(arr, 5, Square()) << std::endl;

	return 0;
}