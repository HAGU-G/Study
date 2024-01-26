#include <iostream>
#include "String.h"

String GetName()
{
	std::cout << "====== 2 ======" << std::endl;
	String res("ABC");
	std::cout << "====== 3 ======" << std::endl;
	return res;
}

int main()
{
	std::cout << "====== 1 ======" << std::endl;
	String a = (String("dfd"));
	String b = a;
	std::cout << "====== 4 ======" << std::endl;

	//String s1("Hello");
	//String s2("World");
	//String s3(s1); //자기 자신(동일 클래스)를 인자로 받는 경우, 복사생성자를 호출한다.
	
	//s2 = s1;
	//할당 연산자는 비트대 비트로 복사를 한다. strData는 주소값을 들고 있으므로 얕은 복사가 된다.
	//프로그램 종료 후 s2가 해제되면 strData는 nullptr이 아니기 때문에 있는 동적할당된 것을 delete한다.
	//s1가 해제 될때 s1의 strData도 nullptr이 아니기 때문에 delete를 시도하고 그 곳에는 아무것도 없기 때문에 오류가 발생한다.
	//해결 방법)
	//할당연산자를 깊은복사가 되도록 오버로딩하면 된다.


	//std::cout << s1.GetLen() << std::endl;
	//std::cout << s1.GetStrData() << std::endl;

	//std::cout << s2.GetLen() << std::endl;
	//std::cout << s2.GetStrData() << std::endl;


	return 0;
}