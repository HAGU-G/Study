//����������
//����1 ����2 ��3
//�÷��̾ �� ������ ����, n�� n���� ���·� ���Ӱ�� ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum
{
	Rock = 1,
	Scissor,
	Paper,
	Select,
	Compare,
	Result
};

char numToChar(int num);
void compare(int player, int npc);


int main()
{
	int state = Select; //���� �ܰ�
	int winCount = 0;
	int drawCount = 0;

	//�÷��̾�� ��ǻ���� ��
	int playerHand = 0;
	int computerHand = 0;


	while (true)
	{
		switch (state)
		{
		case Select:
		{
			printf("\n--------------------------\n");
			printf("���� : 1\n���� : 2\n�� : 3\n\n");
			printf("�ȳ��� ����, ����������! : ");
			scanf_s("%d", &playerHand);

			if (playerHand >= 1 && playerHand <= 3)
				state = Compare;
			else
			{
				printf("�߸��� �Է��Դϴ�.\n");
				state = Select;
			}

			break;
		}

		case Compare:
		{
			srand(time(NULL));
			computerHand = rand() % 3 + 1;

			if (computerHand - playerHand == 1 || (playerHand == 3 && computerHand == 1))
			{
				printf("%d %d �¸�\n", playerHand, computerHand);
				winCount++;
				state = Select;
			}
			else if (playerHand == computerHand)
			{

				printf("%d %d ���º�\n", playerHand, computerHand);
				drawCount++;
				state = Select;
			}
			else
			{

				printf("%d %d �й�\n", playerHand, computerHand);
				state = Result;
			}

			break;
		}

		case Result:
		{
			printf("\n���� ��� : %d�� %d�� 1��\n", winCount, drawCount);
			return 0;
			break;
		}

		}//switch
	}
	return 0;
}

char numToChar(int num)
{
	return 0;
}
void compare(int player, int npc)
{
	return;
}