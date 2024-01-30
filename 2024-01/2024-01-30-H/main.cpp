#include <iostream>
#include "String.h"
#include "Point.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Ring.h"

//�׽�Ʈ �ڵ�
void TestString();
void TestShapeMain();
void TestShapeEtc();

int main()
{
	std::cout << "======String======" << std::endl;
	//TestString();
	std::cout << std::endl;
	std::cout << "======Shape main======" << std::endl;
	//TestShapeMain();
	std::cout << std::endl;
	std::cout << "======Shape etc.======" << std::endl;
	TestShapeEtc();
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
		std::cout << "���� ���ڿ�!" << std::endl;
	else
		std::cout << "�������� ���� ���ڿ�!" << std::endl;

	String str4;
	std::cout << "���ڿ� �Է�: ";
	std::cin >> str4;
	std::cout << "�Է��� ���ڿ�: " << str4 << std::endl;


	//------------------�׽�Ʈ �ڵ� �߰�----------------------
	String strC = "CCC";
	String strD;
	strD = "DDDD"; //�̵� ���� ������
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
		std::cout << "����: " << shapes[i]->Area() << std::endl;
		std::cout << "�ѷ�: " << shapes[i]->Round() << std::endl;
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

void TestShapeEtc()
{
	Rectangle rect1 = Rectangle(&Point(2, -3), &Point(-4, 8));
	std::cout << rect1 << std::endl;
	Rectangle rect2 = rect1; //���� ������
	std::cout << rect2 << std::endl;
	std::cout << rect2.GetCenter() << std::endl;
	std::cout << rect2.GetLT() << rect2.GetRT() << rect2.GetLB() << rect2.GetRB() << std::endl;
	rect2.SetLT((2, 3)); //���� �»���� (-4, 8)�̴�. (2, 3)�� ������ x��ǥ�� ���� ������ �Ҵ����� �ʴ´�.
	rect2.SetLT((1, 4));



	rect1 = rect2; //���� ������
	std::cout << rect1 << std::endl;


}