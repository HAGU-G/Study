#include <iostream>
#include <iomanip>
#include "Vector2.h" //상대경로
#include "Color.h"

//클래스 멤버 함수의 선언과 정의 분리


int main()
{
	Vector2 a(2, 3);
	Vector2 b(4, 5);

	Vector2 ret1 = Vector2::Add(a, b);
	Vector2 ret2 = a.Add(b);
	Vector2 ret3 = Add(a, b);
	Vector2 ret4 = a + b;
	Vector2 ret5 = a - b;

	Vector2 ret6 = a * 3.f;
	Vector2 ret7 = 3.f * a;
	Vector2 ret8 = ret6 / 3.f;

	Vector2 ret9 = -ret8;
	Vector2 ret10 = +ret9;

	ret6.Print();
	ret7.Print();
	ret8.Print();
	ret9.Print();
	ret10.Print();
	std::cout << (ret9 == ret10) << std::endl;
	std::cout << (ret9 != ret10) << std::endl;


	Vector2 ret11;
	ret11 -= ret8;
	ret11 -= 3.f;

	ret11.Print();

	++ret11;


	std::cout << ret9 << std::endl;

	return 0;
}
