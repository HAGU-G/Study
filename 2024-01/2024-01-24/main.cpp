#include <iostream>
#include <iomanip>
#include "Vector2.h" //상대경로
#include "Color.h"

//클래스 멤버 함수의 선언과 정의 분리


int main()
{
	//Color red(1.0f, 0.0f, 0.0f);
	//Color blue(0.0f, 0.0f, 1.0f);
	//Color purple = Color::MixColors(red, blue);

	//unsigned int color32 = Color::GetColor32(purple);
	//std::cout << std::hex << std::setfill('0') << std::setw(8) << color32 << std::endl; //16진수 형태로 나오도록 (FF000000)

	//Color color = Color::GetColor(color32);
	//color.Print();	// (1.0, 0.0, 0.0)

	//Vector2 point(10, 20);
	//std::cout << point.GetX() << point.GetY() << std::endl;


	Vector2 a(2, 3);
	Vector2 b(4, 5);

	Vector2 ret1 = Vector2::Add(a, b);
	Vector2 ret2 = a.Add(b);
	Vector2 ret3 = Add(a, b);
	Vector2 ret4 = a + b;

	ret1.Print();
	ret2.Print();
	ret3.Print();
	ret4.Print();
	

	return 0;
}
