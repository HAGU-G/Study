#include<stdio.h>

int main()
{
	//������ �Է¹޾� ¦������ Ȯ��
	int number = 0;

	printf("���� �Է�: ");
	scanf("%d", &number); //����ó���� �ߴٰ� ����
	printf("\n�Էµ� ���� %d��(��) ", number);

	bool isEven = (number % 2) == 0;

	if (number == 0)
	{
		printf("0�Դϴ�.\n");
	}
	else if (isEven)
	{
		printf("¦���Դϴ�.\n");
	}
	else
	{
		printf("Ȧ���Դϴ�.\n");
	}

	

	return 0;
}