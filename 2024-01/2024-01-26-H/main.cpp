#include <iostream>
#include "String.h"
#include "Book.h"
#include "BankAccount.h"
#include "Student.h"
#include "Time.h"

using namespace std;

Student PleaseMove()
{
	Student temp("����", "����", "���");
	return temp;
}

int main(void)
{
	String strA;
	String strB;
	cout << strA + strB << endl;

	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;
	
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str2)
		cout << "���� ���ڿ�!" << endl;
	else
		cout << "�������� ���� ���ڿ�!" << endl;

	String str4;
	cout << "���ڿ� �Է�: ";
	cin >> str4;
	cout << "�Է��� ���ڿ�: " << str4 << endl;


	//------------------�׽�Ʈ �ڵ� �߰�----------------------
	String strC = "CCC";
	String strD;
	strD = "DDDD"; //�̵� ���� ������
	String str5 = strD;


	std::cout << strC + " " << strD + " " << str5 << endl;
	std::cout << strC << strD << str5 << endl;
	std::cout << "D == 5 " << (strD == str5) << endl;
	std::cout << "C != D " << (strC != strD) << endl;
	std::cout << "C >  D " << (strC > strD) << endl;
	std::cout << "D >= 5 " << (strD >= str5) << endl;
	std::cout << "C <  D " << (strC < strD) << endl;
	std::cout << "C <= D " << (strC <= strD) << endl;

	//���� �̵�
	Book bk1 = Book("��", "��", 3);
	Book bk2 = bk1; //���� ������

	BankAccount ba1("112k3", 30);
	BankAccount ba2 = BankAccount("dkdkdk", 200);
	ba1 = ba2; //���� ������

	Student st1("�츮","���","��");
	st1 = PleaseMove(); //�̵� ���� ������
	Student st2 = PleaseMove();

	Time t1;
	t1 = Time(12, 65, 1); //�̵� ���� ������
	t1 = (1, 2, 3); //�̵� ���� ������

	return 0;
}