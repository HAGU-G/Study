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
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;

	String str4; //과제에 string으로 되어있어서 String으로 수정 후 기능 구현.
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;


	//테스트 코드 추가
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

	return 0;
}