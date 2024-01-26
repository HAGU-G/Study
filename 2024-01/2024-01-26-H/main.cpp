#include <iostream>
#include "String.h"
using namespace std;

int main(void)
{
	String strA;
	String strB;
	String strC = strA + strB;
	cout << strC.GetStrData() << endl;

	//String str1 = "I like ";
	//String str2 = "string class";
	//String str3 = str1 + str2;

	//cout << str1 << endl;
	//cout << str2 << endl;
	//cout << str3 << endl;

	//str1 += str2;
	//if (str1 == str3)
	//	cout << "동일 문자열!" << endl;
	//else
	//	cout << "동일하지 않은 문자열!" << endl;

	//String str4;
	//cout << "문자열 입력: ";
	//cin >> str4;
	//cout << "입력한 문자열: " << str4 << endl;*/


	//참조
	//크다 작다 : strcmp
	//복사 이동 생성자, 할당연산자

	return 0;
}