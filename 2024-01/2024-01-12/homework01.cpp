#include<stdio.h>

int main()
{

	//1
	int score = 0;
	printf("���� �Է�: ");
	scanf("%d", &score);

	if (score > 100 || score < 0)
	{
		printf("�߸� �Է��ϼ̽��ϴ�.");
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
	printf("�ڿ��� �Է�: ");
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