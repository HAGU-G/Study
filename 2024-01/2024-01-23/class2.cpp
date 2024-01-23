#include <iostream>
#include <string>

class MyClass
{
private:
	int number = 0;

public:
	//생성자 : 초기화를 한다. 동적할당해주는 역할을 한다.
	//반환형은 없으며 함수 이름은 자신의 클래스 이름을 사용한다.
	MyClass() : MyClass(0) //멤버이니셜라이저에서 다른 생성자 호출이 가능하다.
	{
		std::cout << "MyClass()" << std::endl;
	}

	MyClass(int n) //생성자 오버로딩
		: number(n)//멤버 이니셜라이저 (초기화) 한줄 넘기지 않아도 됨. ,를 써서 여러개 사용 가능
	{
		//number = n; 해당 방법으로 초기화 해줄수도 있다.
		std::cout << "MyClass(int) "<< number << std::endl;
	}

	//소멸자 : 정리하는 역할. 동적할당했던 것을 해제하는 등의 임무를 수행한다.
	//반환형은 없으며 함수 이름은 자신의 클래스 이름을 사용한다. 앞에 ~를 붙여줘야한다.
	~MyClass()
	{
		std::cout << "~MyClass() " << number << std::endl;
	}

	void PrintThis()
	{
		std::cout << "number : " << number << std::endl;
		std::cout << "나의 주소는 " << this << std::endl;
	}
};//MyClass

void TestLocalObject()
{
	std::cout << "TestLocalObject() 시작" << std::endl;
	MyClass obj3(4); //생성자 호출
	std::cout << "TestLocalObject() 끝" << std::endl;

} //소멸자 호출

MyClass obj(1);//생성자 호출(매개변수가 있는 생성자)

int main()
{
	std::cout << "main 시작" << std::endl;
	MyClass obj1(2);//생성자는 여러개가 호출될 수도 있다.
	MyClass obj2(3);
	TestLocalObject();
	std::cout << "main 끝" << std::endl;
	return 0;
} //소멸자 호출