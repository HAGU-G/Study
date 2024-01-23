#include <iostream>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//함수 오버로딩 : 이름이 같고 매개변수가 다른 함수
//인자의 자료형에 따라 함수를 자동으로 선택한다. 컴파일타임에 결정된다.
void Swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//함수의 기본값
//인자를 넘기지 않으면 기본값으로 실행한다.
void Function(int num = 123)
{
	std::cout << num << std::endl;
}

int main()
{
	int x = 0, y = 0;
	Swap(x, y);

	double i = 0, j = 0;
	Swap(i, j);


	return 0;
}