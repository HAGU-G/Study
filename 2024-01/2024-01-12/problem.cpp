#include<stdio.h>

//������ �Է¹޾� A~F�� ��� ���

int main()
{
	int score = 0;
	printf("����(0~100) �Է�: ");
	scanf("%d", &score);



	if (score > 100 || score < 0)
	{
		printf("�߸��� �����Դϴ�.");
	}
	else
	{
		printf("%d���� ����� ", score);

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

	return 0;
}