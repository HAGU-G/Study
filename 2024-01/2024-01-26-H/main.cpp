#include <iostream>
#include "String.h"

using namespace std;

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

	String str4; //������ string���� �Ǿ��־ String���� ���� �� ��� ����.
	cout << "���ڿ� �Է�: ";
	cin >> str4;
	cout << "�Է��� ���ڿ�: " << str4 << endl;


	//�׽�Ʈ �ڵ� �߰�
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

	return 0;
}