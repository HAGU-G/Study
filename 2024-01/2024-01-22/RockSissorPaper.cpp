//가위바위보
//바위1 가위2 보3
//플레이어가 질 때까지 진행, n승 n무의 형태로 게임결과 출력
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
	int state = Select; //현재 단계
	int winCount = 0;
	int drawCount = 0;

	//플레이어와 컴퓨터의 패
	int playerHand = 0;
	int computerHand = 0;


	while (true)
	{
		switch (state)
		{
		case Select:
		{
			printf("\n--------------------------\n");
			printf("바위 : 1\n가위 : 2\n보 : 3\n\n");
			printf("안내면 진다, 가위바위보! : ");
			scanf_s("%d", &playerHand);

			if (playerHand >= 1 && playerHand <= 3)
				state = Compare;
			else
			{
				printf("잘못된 입력입니다.\n");
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
				printf("%d %d 승리\n", playerHand, computerHand);
				winCount++;
				state = Select;
			}
			else if (playerHand == computerHand)
			{

				printf("%d %d 무승부\n", playerHand, computerHand);
				drawCount++;
				state = Select;
			}
			else
			{

				printf("%d %d 패배\n", playerHand, computerHand);
				state = Result;
			}

			break;
		}

		case Result:
		{
			printf("\n게임 결과 : %d승 %d무 1패\n", winCount, drawCount);
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