#include<stdio.h>


int main()
{
	////n������ 3�� ��� ���
	//int num = 0;

	//printf("������ �Է� : ");
	//scanf("%d", &num);

	//for (int i = 1; i <= num; ++i)
	//{

	//	if (i % 3 != 0)
	//	{
	//		continue;
	//	}
	//	printf("%d ", i);
	//}

	//������ ���
	for (int i = 2; i <= 9; ++i)
	{
		for (int j = 1; j <= 9; ++j)
		{
			printf("%d x %d = %d\n", i, j, i * j);
		}
	}

	printf("\n\n");

	for (int i = 1; i <= 9; ++i)
	{
		for (int j = 2; j <= 9; ++j)
		{
			printf("%dx%d=%d\t", j, i, i * j);
		}
		printf("\n");
	}

}