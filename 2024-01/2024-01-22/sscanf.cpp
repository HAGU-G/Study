#include <stdio.h>
#include <stdlib.h>

int main()
{
	char sa[] = "123";
	int a = 0;

	sscanf(sa, "%d", &a); //���ۿ��� ������ ���·� a�� �Է��Ѵ�.
	printf("%d", a);


	sprintf(sa, "%d", 321); //���ۿ� ������ ���·� 321�� ����Ѵ�.
	printf("%s", sa);
}

//�Է��� ���ۿ��� �������� ��.
//����� ���۷� �������� ��.