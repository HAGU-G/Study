#include <stdio.h>

int main()
{
	int score = 0;
	int grade = 0;
	printf("���� �Է� : ");
	scanf_s("%d", &score);

	if (score < 0 || score > 100)
	{
		printf("�߸� �Է��ϼ̽��ϴ�.");
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