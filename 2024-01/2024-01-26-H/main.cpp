#include <iostream>
#include "String.h"
#include "Book.h"
#include "BankAccount.h"
#include "Student.h"
#include "Time.h"

using namespace std;

Student PleaseMove()
{
	Student temp("나는", "누구", "어디");
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
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;


	//------------------테스트 코드 추가----------------------
	String strC = "CCC";
	String strD;
	strD = "DDDD"; //이동 대입 연산자
	String str5 = strD;


	std::cout << strC + " " << strD + " " << str5 << endl;
	std::cout << strC << strD << str5 << endl;
	std::cout << "D == 5 " << (strD == str5) << endl;
	std::cout << "C != D " << (strC != strD) << endl;
	std::cout << "C >  D " << (strC > strD) << endl;
	std::cout << "D >= 5 " << (strD >= str5) << endl;
	std::cout << "C <  D " << (strC < strD) << endl;
	std::cout << "C <= D " << (strC <= strD) << endl;

	//복사 이동
	Book bk1 = Book("나", "너", 3);
	Book bk2 = bk1; //복사 생성자

	BankAccount ba1("112k3", 30);
	BankAccount ba2 = BankAccount("dkdkdk", 200);
	ba1 = ba2; //복사 생성자

	Student st1("우리","모두","모여");
	st1 = PleaseMove(); //이동 대입 연산자
	Student st2 = PleaseMove();

	Time t1;
	t1 = Time(12, 65, 1); //이동 대입 연산자
	t1 = (1, 2, 3); //이동 대입 연산자

	return 0;
}