#include <iostream>

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

//�Լ� �����ε� : �̸��� ���� �Ű������� �ٸ� �Լ�
//������ �ڷ����� ���� �Լ��� �ڵ����� �����Ѵ�. ������Ÿ�ӿ� �����ȴ�.
void Swap(double& a, double& b)
{
	double temp = a;
	a = b;
	b = temp;
}

//�Լ��� �⺻��
//���ڸ� �ѱ��� ������ �⺻������ �����Ѵ�.
void Function(int num = 123)
{
	std::cout << num << std::endl;
}

int main()
{
	int x = 0, y = 0;
	Swap(x, y);

	double i = 0, j = 0;
	Swap(i, j);


	return 0;
}