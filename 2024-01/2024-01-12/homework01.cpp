#include<stdio.h>

int main()
{

	//1
	int score = 0;
	printf("점수 입력: ");
	scanf("%d", &score);

	if (score > 100 || score < 0)
	{
		printf("잘못 입력하셨습니다.");
	}
	else
	{
		if (score >= 90)
		{
			printf("A");
		}
		else if (score >= 80)
		{
			printf("B");
		}
		else if (score >= 70)
		{
			printf("C");
		}
		else if (score >= 60)
		{
			printf("D");
		}
		else
		{
			printf("F");
		}

	}

	//2
	int num2 = 0;
	printf("자연수 입력: ");
	scanf("%d", &num2);

	for (int i = 1; i <= num2; i++)
	{
		if (num2 % i == 0)
		{
			printf("%d", i);
			if (i < num2)
			{
				printf(", ");
			}
		}
	}

	//3
	int num3 = 0;

}