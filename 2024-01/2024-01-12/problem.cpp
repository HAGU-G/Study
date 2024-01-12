#include<stdio.h>

//점수를 입력받아 A~F의 등급 출력

int main()
{
	int score = 0;
	printf("점수(0~100) 입력: ");
	scanf("%d", &score);



	if (score > 100 || score < 0)
	{
		printf("잘못된 점수입니다.");
	}
	else
	{
		printf("%d점의 등급은 ", score);

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