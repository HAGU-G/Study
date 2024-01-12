#include<stdio.h>

int main()
{
	//정수를 입력받아 짝수인지 확인
	int number = 0;

	printf("정수 입력: ");
	scanf("%d", &number); //예외처리는 했다고 가정
	printf("\n입력된 정수 %d은(는) ", number);

	bool isEven = (number % 2) == 0;

	if (number == 0)
	{
		printf("0입니다.\n");
	}
	else if (isEven)
	{
		printf("짝수입니다.\n");
	}
	else
	{
		printf("홀수입니다.\n");
	}

	

	return 0;
}