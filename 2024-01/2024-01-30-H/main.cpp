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

	//��Ÿ ���� Ȯ���� ���� �׽�Ʈ �ڵ�
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

void TestRectangleEtc()
{
	std::cout << std::endl << "=============== Rectangle" << std::endl;
	Rectangle rect1 = Rectangle(Point(2, -3), Point(-4, 8));
	Rectangle rect2 = rect1; //���� ������
	std::cout << rect2 << std::endl;
	std::cout << "���簢���� �߽�: " << rect2.GetCenter() << std::endl;
	std::cout << "������: " << rect2.GetLT() << rect2.GetRT() << rect2.GetLB() << rect2.GetRB() << std::endl << std::endl;
	
	rect2.SetLT(Point(2, 3)); //���� �»���� (-4, 8)�̴�. (2, 3)�� ������ x��ǥ�� ���� ������ �Ҵ����� �ʴ´�.
	std::cout << rect2 << std::endl;
	rect2.SetLT(Point(1, 4));
	std::cout << rect2 << std::endl;
	rect2.SetRB(Point(10, -16));
	std::cout << rect2 << std::endl;
	rect2.SetBottomY(3);
	std::cout << rect2 << std::endl;

	rect1 = rect2; //���� ������
	rect1 = Rectangle(Point(2, -3), Point(-4, 8)); //�̵� ���� ������

}

void TestCircleRingEtc()
{
	Circle circle1(Point(1, 1), 3);
	Circle circle2 = circle1; //���� ������
	circle2 = circle1; //���� ������
	circle2 = Circle(Point(1, 2), 4); //�̵� ���� ������

	std::cout << std::endl << "=============== Ring" << std::endl;
	Ring ring1(&circle1, &circle2); //���ɿ��� �ƴϱ� ������ ring1�� ��� ��������� 0�� �ȴ�.
	std::cout << ring1 << std::endl;
	circle2.SetCenter(Point(1, 1));
	ring1 = Ring(&circle1, &circle2); //�̵� ���� ������
	Ring ring2 = ring1; //���� ������
	std::cout << ring2 << std::endl << std::endl;

	ring2.SetCenter(Point(5, 10));
	ring2.SetLargeRadius(30);
	ring2.SetSmallRadius(-60); //0 ���ϸ� �ѱ�� ���� ������ ����.
	std::cout << ring2.GetCenter() << " " << ring2.GetSmallRadius() << " " << ring2.GetLargeRadius() << std::endl;
	ring1 = ring2; //���� ������
	std::cout << ring1 << std::endl;

	std::cout << std::endl << "=============== Circle" << std::endl;

	circle1.SetCenter(Point(3, 4));
	std::cout << circle1 << std::endl;
	circle1.SetRadius(2938);
	std::cout << circle1 << std::endl;
}