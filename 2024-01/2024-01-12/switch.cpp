#include<stdio.h>


int main()
{
	printf("�� ����	: 1\n");
	printf("�ҷ�����: 2\n");
	printf("����	: 3\n");
	printf("ũ����	: 4\n");

	int inputNum = 0;
	scanf("%d", &inputNum);

	switch (inputNum)
	{
	case 1:
		printf("�� ����\n");
		break;
	case 2:
		printf("�ҷ�����\n");
		break;
	case 3:
		printf("����\n");
		break;
	case 4:
		printf("ũ����\n");
		break;
	default:
		printf("�߸��� �Է��Դϴ�.\n");
		break;
	}


	return 0;
}