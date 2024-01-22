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
	Result,
	End
};

char numToDes(int num);


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

			if (playerHand >= Rock && playerHand <= Paper)
				state = Result;
			else
			{
				printf("�߸��� �Է��Դϴ�.\n");
				state = Select;
			}

			break;
		}

		case Result:
		{
			srand(time(NULL));
			computerHand = rand() % 3 + 1;

			printf("��ǻ�� : ");
			numToDes(computerHand);
			printf("\n");
			printf("��š� : ");
			numToDes(playerHand);

			if (computerHand - playerHand == 1 || (playerHand == Paper && computerHand == Rock))
			{
				printf("\t�ڽ¸�\n");
				winCount++;
				state = Select;
			}
			else if (playerHand == computerHand)
			{
				printf("\t�ܹ��º�\n");
				drawCount++;
				state = Select;
			}
			else
			{
				printf("\t���й�\n");
				state = End;
			}

			break;
		}

		case End:
		{
			printf("\n���� ��� : %d�� %d�� 1��\n", winCount, drawCount);
			return 0;
			break;
		}

		}//switch
	}
	return 0;
}


char numToDes(int num)
{
	switch (num)
	{
	case Rock:
		printf("����");
		break;

	case Scissor:
		printf("����");
		break;

	case Paper:
		printf("��");
		break;
	}
	return 0;
}