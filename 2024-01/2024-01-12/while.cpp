#include<stdio.h>

int main()
{
	int i = 1;
	while (i <= 10) //���ǽĿ� true�� ������ ��� �ݺ��ȴ�.
	{
		printf("%d ", i);
		++i;
	}

	printf("\n");

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", i);
	}


	return 0;
	
}