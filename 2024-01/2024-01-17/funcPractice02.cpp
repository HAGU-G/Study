#include <stdio.h>

void Swap(int a, int b) //�Լ��� �̸��� �������·� ����, ������ �������
{
	int temp = a;
	a = b;
	b = temp;

}


int main()
{
	int x = 10;
	int y = 20;

	Swap(x, y);

	printf("%d %d", x, y);

	return 0;
}