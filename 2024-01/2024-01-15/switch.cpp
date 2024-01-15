#include <stdio.h>

int main()
{
	int score = 0;
	int grade = 0;
	printf("점수 입력 : ");
	scanf_s("%d", &score);

	if (score < 0 || score > 100)
	{
		printf("잘못 입력하셨습니다.");
		return 0;
	}

	grade = score / 10;
	switch (grade)
	{
	case 10:
	case 9:
		printf("A");
		break;

	case 8:
		printf("B");
		break;

	case 7:
		printf("C");
		break;

	case 6:
		printf("D");
		break;

	default:
		printf("F");
		break;
	}


	return 0;
}