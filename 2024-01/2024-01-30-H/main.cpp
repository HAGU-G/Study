#include <iostream>
#include "String.h"
#include "Point.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ring.h"

//테스트 코드
void TestString();
void TestShapeMain();

void TestRectangleEtc();
void TestCircleRingEtc();

int main()
{
	std::cout << "========== String ==========" << std::endl;
	TestString();
	std::cout << std::endl;
	std::cout << "========== Shape main ==========" << std::endl;
	TestShapeMain();
	std::cout << std::endl;

	//기타 동작 확인을 위한 테스트 코드
	std::cout << "========== Shape etc. ==========" << std::endl;
	TestRectangleEtc();
	TestCircleRingEtc();
	std::cout << std::endl;

	return 0;
}



void TestString()
{

	String strA;
	String strB;
	std::cout << strA + strB << std::endl;

	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	std::cout << str1 << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str3 << std::endl;

	str1 += str2;
	if (str1 == str2)
		std::cout << "동일 문자열!" << std::endl;
	else
		std::cout << "동일하지 않은 문자열!" << std::endl;

	String str4;
	std::cout << "문자열 입력: ";
	std::cin >> str4;
	std::cout << "입력한 문자열: " << str4 << std::endl;


	//------------------테스트 코드 추가----------------------
	String strC = "CCC";
	String strD;
	strD = "DDDD"; //이동 대입 연산자
	String str5 = strD;

	std::cout << strC + " " << strD + " " << str5 << std::endl;
	std::cout << strC << strD << str5 << std::endl;
	std::cout << "D == 5 " << (strD == str5) << std::endl;
	std::cout << "C != D " << (strC != strD) << std::endl;
	std::cout << "C >  D " << (strC > strD) << std::endl;
	std::cout << "D >= 5 " << (strD >= str5) << std::endl;
	std::cout << "C <  D " << (strC < strD) << std::endl;
	std::cout << "C <= D " << (strC <= strD) << std::endl;


	return;
}

void TestShapeMain()
{
	Point* pos1 = new Point(-10, 10);
	Point* pos2 = new Point(10, -10);

	Shape* shapes[4];
	shapes[0] = new Rectangle(pos1, pos2);
	shapes[1] = new Circle(pos1, 5);
	shapes[2] = new Circle(pos1, 10);
	shapes[3] = new Ring((Circle*)shapes[1], (Circle*)shapes[2]);

	for (int i = 0; i < 4; ++i)
	{
		std::cout << shapes[i] << std::endl;
		std::cout << "넓이: " << shapes[i]->Area() << std::endl;
		std::cout << "둘레: " << shapes[i]->Round() << std::endl;
		std::cout << std::endl;
	}

	for (int i = 3; i >= 0; --i)
	{
		delete shapes[i];
	}
	delete pos2;
	delete pos1;

	return;
}

void TestRectangleEtc()
{
	std::cout << std::endl << "=============== Rectangle" << std::endl;
	Rectangle rect1 = Rectangle(Point(2, -3), Point(-4, 8));
	Rectangle rect2 = rect1; //복사 생성자
	std::cout << rect2 << std::endl;
	std::cout << "직사각형의 중심: " << rect2.GetCenter() << std::endl;
	std::cout << "꼭지점: " << rect2.GetLT() << rect2.GetRT() << rect2.GetLB() << rect2.GetRB() << std::endl << std::endl;
	
	rect2.SetLT(Point(2, 3)); //원래 좌상단은 (-4, 8)이다. (2, 3)은 우측의 x좌표와 같기 때문에 할당하지 않는다.
	std::cout << rect2 << std::endl;
	rect2.SetLT(Point(1, 4));
	std::cout << rect2 << std::endl;
	rect2.SetRB(Point(10, -16));
	std::cout << rect2 << std::endl;
	rect2.SetBottomY(3);
	std::cout << rect2 << std::endl;

	rect1 = rect2; //대입 연산자
	rect1 = Rectangle(Point(2, -3), Point(-4, 8)); //이동 대입 연산자

}

void TestCircleRingEtc()
{
	Circle circle1(Point(1, 1), 3);
	Circle circle2 = circle1; //복사 생성자
	circle2 = circle1; //대입 연산자
	circle2 = Circle(Point(1, 2), 4); //이동 대입 연산자

	std::cout << std::endl << "=============== Ring" << std::endl;
	Ring ring1(&circle1, &circle2); //동심원이 아니기 때문에 ring1의 모든 멤버변수는 0이 된다.
	std::cout << ring1 << std::endl;
	circle2.SetCenter(Point(1, 1));
	ring1 = Ring(&circle1, &circle2); //이동 대입 연산자
	Ring ring2 = ring1; //복사 생성자
	std::cout << ring2 << std::endl << std::endl;

	ring2.SetCenter(Point(5, 10));
	ring2.SetLargeRadius(30);
	ring2.SetSmallRadius(-60); //0 이하를 넘기면 값이 변하지 않음.
	std::cout << ring2.GetCenter() << " " << ring2.GetSmallRadius() << " " << ring2.GetLargeRadius() << std::endl;
	ring1 = ring2; //대입 연산자
	std::cout << ring1 << std::endl;

	std::cout << std::endl << "=============== Circle" << std::endl;

	circle1.SetCenter(Point(3, 4));
	std::cout << circle1 << std::endl;
	circle1.SetRadius(2938);
	std::cout << circle1 << std::endl;
}