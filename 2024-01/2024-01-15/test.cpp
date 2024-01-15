#include <stdio.h>

int main()
{
	int num = 0;
	printf("자연수 입력: ");
	scanf_s("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d", 2*j-1);
		}
		printf("\n");
	}

	return 0;
}