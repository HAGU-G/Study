#include<stdio.h>


int main()
{
	printf("새 게임	: 1\n");
	printf("불러오기: 2\n");
	printf("설정	: 3\n");
	printf("크레딧	: 4\n");

	int inputNum = 0;
	scanf("%d", &inputNum);

	switch (inputNum)
	{
	case 1:
		printf("새 게임\n");
		break;
	case 2:
		printf("불러오기\n");
		break;
	case 3:
		printf("설정\n");
		break;
	case 4:
		printf("크레딧\n");
		break;
	default:
		printf("잘못된 입력입니다.\n");
		break;
	}


	return 0;
}