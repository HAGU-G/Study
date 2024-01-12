#include<stdio.h>


int main()
{
	////n까지의 3의 배수 출력
	//int num = 0;

	//printf("정수를 입력 : ");
	//scanf("%d", &num);

	//for (int i = 1; i <= num; ++i)
	//{

	//	if (i % 3 != 0)
	//	{
	//		continue;
	//	}
	//	printf("%d ", i);
	//}

	//구구단 출력
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