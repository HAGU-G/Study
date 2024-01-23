#include <iostream>
#include <string>

class MyClass
{
private:
	int number = 0;

public:
	//������ : �ʱ�ȭ�� �Ѵ�. �����Ҵ����ִ� ������ �Ѵ�.
	//��ȯ���� ������ �Լ� �̸��� �ڽ��� Ŭ���� �̸��� ����Ѵ�.
	MyClass() : MyClass(0) //����̴ϼȶ��������� �ٸ� ������ ȣ���� �����ϴ�.
	{
		std::cout << "MyClass()" << std::endl;
	}

	MyClass(int n) //������ �����ε�
		: number(n)//��� �̴ϼȶ����� (�ʱ�ȭ) ���� �ѱ��� �ʾƵ� ��. ,�� �Ἥ ������ ��� ����
	{
		//number = n; �ش� ������� �ʱ�ȭ ���ټ��� �ִ�.
		std::cout << "MyClass(int) "<< number << std::endl;
	}

	//�Ҹ��� : �����ϴ� ����. �����Ҵ��ߴ� ���� �����ϴ� ���� �ӹ��� �����Ѵ�.
	//��ȯ���� ������ �Լ� �̸��� �ڽ��� Ŭ���� �̸��� ����Ѵ�. �տ� ~�� �ٿ�����Ѵ�.
	~MyClass()
	{
		std::cout << "~MyClass() " << number << std::endl;
	}

	void PrintThis()
	{
		std::cout << "number : " << number << std::endl;
		std::cout << "���� �ּҴ� " << this << std::endl;
	}
};//MyClass

void TestLocalObject()
{
	std::cout << "TestLocalObject() ����" << std::endl;
	MyClass obj3(4); //������ ȣ��
	std::cout << "TestLocalObject() ��" << std::endl;

} //�Ҹ��� ȣ��

MyClass obj(1);//������ ȣ��(�Ű������� �ִ� ������)

int main()
{
	std::cout << "main ����" << std::endl;
	MyClass obj1(2);//�����ڴ� �������� ȣ��� ���� �ִ�.
	MyClass obj2(3);
	TestLocalObject();
	std::cout << "main ��" << std::endl;
	return 0;
} //�Ҹ��� ȣ��