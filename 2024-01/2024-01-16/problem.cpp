#include <stdio.h>
#include <stdlib.h>

int main()
{

//1��
	{
		int arrlen = 0;
		int arr[100] = { 0 };

		printf("������ ���� �Է�: ");
		scanf_s("%d", &arrlen);
		printf("���� �Է�: ");
		for (int i = 0; i < arrlen; i++)
		{
			scanf_s("%d", &arr[i]);
		}

		for (int i = 0; i < arrlen; i++)
		{
			if (i % 2 == 1)
			{
				printf("%d ", arr[i]);
			}
		}

		printf("\n");
		for (int i = 0; i < arrlen; i++)
		{
			if (i % 2 == 0)
			{
				printf("%d ", arr[i]);
			}
		}
		printf("\n", arr[0]);
	}

//2��
	{
		//*ptr = 30; a�� 30�� ����
		//*ptr = 10; b�� 10�� ����
		// 30 10 10�� ��µȴ�.

		int a = 10;
		int b = 20;

		int* ptr;

		ptr = &a;
		*ptr = 30;

		ptr = &b;
		*ptr = 10;

		printf("%d\n", a);
		printf("%d\n", b);
		printf("%d\n", *ptr);
	}

//3��
	{
		// ��¿��� *Ʋ�� : �����Ϳ����ڿ� ��巹�������ڸ� �򰥷��� �ݴ�� ������
		// 112 1
		// 116 5
		// 120 9
		// 124 2
		// arr + i �� arr[i]�� �ּҰ�
		// *(arr +i)�� arr[i]�� �� 

		int arr[10] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };

		printf("%d\n", arr); //100�� ��µȴٰ� ����
		for (int i = 3; i < 7; i++)
		{
			printf("%d %d\n", arr + i, *(arr + i));
		}

	}

//4��
	{
		int arr[10][10] = { 0 };
		int row = 0;
		int col = 0;

		//��� �Է�
		scanf_s("%d %d", &row, &col);

		//��� �Է�
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				scanf_s("%d", &arr[i][j]);
			}
		}

		//�ջ�
		for (int i = 0; i < row; i++)
		{
			int sum = 0;
			for (int j = 0; j < col; j++)
			{
				sum += arr[i][j];
			}
			printf("%d\n", sum);
		}

	}

//5��
	{
		//arr�� ���� �ּҴ� 100�̶�� ����
		int arr[3][3] = { 0 };
		printf("%d\n", &arr);	//100	: arr�� �迭������
		printf("%d\n", arr);	//100	: arr[i]�� �����ּ�
		printf("%d\n", *arr);	//100	: arr[0] *Ʋ��

		printf("%d\n", &arr[0]);	//100	: arr[0]�� �ּ� = arr
		printf("%d\n", arr[0]);		//100	: arr[0][i]�� ���� �ּ�
		printf("%d\n", *arr[0]);	//0		: arr[0][0]
		
		printf("%d\n", &arr[0][0]);	//100	: arr[0][0]�� �ּ�
		printf("%d\n", arr[0][0]);	//0		: arr[0][0]�� ��


	}

//6��
	{
		//���� �ּҴ� 100
		int arr[3][3] = { 0 };

		printf("%d\n", &arr[0][0]);		// 100	: arr[0]
		printf("%d\n", arr[0] + 1);		// 104	: arr[0][1]
		printf("%d\n", &arr[0] + 1);	// 112	: arr[1]
		printf("%d\n", arr + 1);		// 112	: arr[1]
		printf("%d\n", &arr + 1);		// 136	: arr		�迭 �����ʹ� int���� 3x3�迭�̱� ������ 36�� �þ��.


	}

//7��
	{
		int arr[3][4] = {
			{ 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12}
		};

		int(*ptr)[4] = arr; //*Ʋ�� 1���� �迭 �����Ϳ� �򰥸�

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {

				//printf("%d ", *ptr[i][j]);	//ptr[i][j]�� �̹� arr[i][j]�� ���� ���̴�.
				printf("%d ", ptr[i][j]);		//int���� �����Ϳ������� �ǿ����ڰ� �� �� ����.

			}
			printf("\n");
		}

		int a = 10;

	}

	return 0;
}