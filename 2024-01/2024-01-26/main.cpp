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
	//String s3(s1); //�ڱ� �ڽ�(���� Ŭ����)�� ���ڷ� �޴� ���, ��������ڸ� ȣ���Ѵ�.
	
	//s2 = s1;
	//�Ҵ� �����ڴ� ��Ʈ�� ��Ʈ�� ���縦 �Ѵ�. strData�� �ּҰ��� ��� �����Ƿ� ���� ���簡 �ȴ�.
	//���α׷� ���� �� s2�� �����Ǹ� strData�� nullptr�� �ƴϱ� ������ �ִ� �����Ҵ�� ���� delete�Ѵ�.
	//s1�� ���� �ɶ� s1�� strData�� nullptr�� �ƴϱ� ������ delete�� �õ��ϰ� �� ������ �ƹ��͵� ���� ������ ������ �߻��Ѵ�.
	//�ذ� ���)
	//�Ҵ翬���ڸ� �������簡 �ǵ��� �����ε��ϸ� �ȴ�.


	//std::cout << s1.GetLen() << std::endl;
	//std::cout << s1.GetStrData() << std::endl;

	//std::cout << s2.GetLen() << std::endl;
	//std::cout << s2.GetStrData() << std::endl;


	return 0;
}