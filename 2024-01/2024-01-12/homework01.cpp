#include<stdio.h>

int main()
{
	int problemNum = 0;
	do
	{
		rewind(stdin);
		printf("--------------------------------\n문제선택 : 1 ~ 8\n종료\t : 0\n번호를 입력해주세요 : ");
		scanf("%d", &problemNum);

		printf("\n%d번 문제)\n", problemNum);
		rewind(stdin);
		switch (problemNum)
		{
		case 1:
		{
			int score = 0;
			printf("점수 입력: ");
			scanf("%d", &score);

			if (score > 100 || score < 0)
			{
				printf("잘못 입력하셨습니다.");
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
			break;
		}
		case 2:
		{
			int num2 = 0;
			printf("자연수 입력: ");
			scanf("%d", &num2);

			for (int i = 1; i <= num2; ++i)
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
			break;
		}
		case 3:
		{
			int num3 = 0;
			printf("자연수 입력: ");
			scanf("%d", &num3);
			for (int i = 1; i <= num3; ++i)
			{
				if (i % 10 % 3 == 0)
				{
					printf("* ");
				}
				else
				{
					printf("%d ", i);
				}
			}
			break;
		}
		case 4:
		{
			int num4 = 0;
			printf("자연수 입력: ");
			scanf("%d", &num4);
			for (int i = 1; i <= num4; ++i)
			{
				for (int j = 1; j <= i; ++j)
				{
					printf("%d ", j);
				}
				printf("\n");
			}
			break;
		}
		case 5:
		{
			int num5 = 0;
			printf("자연수 입력: ");
			scanf("%d", &num5);
			for (int i = num5; i > 0; --i)
			{
				for (int j = i; j > 0; --j)
				{
					printf("%d ", j);
				}
				printf("\n");
			}
			break;
		}
		case 6:
		{
			int num6 = 0;
			printf("자연수 입력: ");
			scanf("%d", &num6);
			for (int i = num6; i > 0; --i)
			{
				for (int j = 1; j <= i; ++j)
				{
					printf("%d ", j);
				}
				printf("\n");
			}
			break;
		}
		case 7:
		{
			int num7 = 0;
			printf("자연수 입력: ");
			scanf("%d", &num7);
			for (int i = 1; i <= num7; ++i)
			{
				for (int j = 1, k = 1; j <= i; ++j, k += 2)
				{
					printf("%d ", k);
				}
				printf("\n");
			}
			break;
		}
		case 8:
		{
			int num8 = 0;
			printf("자연수 입력: ");
			scanf("%d", &num8);
			for (int i = 1, j = 1; i <= num8; ++i, j += 2)
			{
				for (int k = 1; k <= j; ++k)
				{
					printf("%d ", k);
				}
				printf("\n");
			}
			break;
		}//case 8
		}//swtich

		printf("\n\n\n");
	} while (problemNum != 0);
}