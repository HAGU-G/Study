//����������
//����1 ����2 ��3
//�÷��̾ �� ������ ����, n�� n���� ���·� ���Ӱ�� ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum
{
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
	int player = 0;
	int npc = 0;


	while (true)
	{
		switch (state)
		{
		case Select:
		{
			printf("\n--------------------------\n");
			printf("���� : 1\n���� : 2\n�� : 3\n\n");
			printf("�ȳ��� ����, ����������! : ");
			scanf("%d", &player);

			if (player >= 1 && player <= 3)
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
			npc = rand() % 3 + 1;

			if (npc - player == 1 || (player == 3 && npc == 1))
			{
				printf("%d %d �¸�\n", player, npc);
				winCount++;
				state = Select;
			}
			else if (player == npc)
			{

				printf("%d %d ���º�\n", player, npc);
				drawCount++;
				state = Select;
			}
			else
			{

				printf("%d %d �й�\n", player, npc);
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