#include <stdio.h>

void SwapValue(int a, int b) //�Լ��� �̸��� �������·� ����, ������ �������
{
	int temp = a;
	a = b;
	b = temp;
}

void SwapAddress(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapReference(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


int main()
{
	int x = 10;
	int y = 20;

	SwapValue(x, y);
	printf("Value %d %d\n", x, y);

	SwapAddress(&x, &y);
	printf("Address %d %d\n", x, y);

	SwapReference(x, y);
	printf("Reference %d %d\n", x, y);

	int a = 10;
	int& ref = a;
	//ref�� a�� �Ȱ��� ������ �Ѵ�.
	//����� ���ÿ� �ʱ�ȭ�� �ؾ��Ѵ�.

	printf("%d %d\n", &a, &ref); //10 10
	ref++;
	printf("%d %d\n", a, ref); //11 11


	return 0;
}