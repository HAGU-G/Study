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
	Result,
	End
};

char numToDes(int num);


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

			if (playerHand >= Rock && playerHand <= Paper)
				state = Result;
			else
			{
				printf("잘못된 입력입니다.\n");
				state = Select;
			}

			break;
		}

		case Result:
		{
			srand(time(NULL));
			computerHand = rand() % 3 + 1;

			printf("컴퓨터 : ");
			numToDes(computerHand);
			printf("\n");
			printf("당신　 : ");
			numToDes(playerHand);

			if (computerHand - playerHand == 1 || (playerHand == Paper && computerHand == Rock))
			{
				printf("\t★승리\n");
				winCount++;
				state = Select;
			}
			else if (playerHand == computerHand)
			{
				printf("\t●무승부\n");
				drawCount++;
				state = Select;
			}
			else
			{
				printf("\tＸ패배\n");
				state = End;
			}

			break;
		}

		case End:
		{
			printf("\n게임 결과 : %d승 %d무 1패\n", winCount, drawCount);
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
		printf("바위");
		break;

	case Scissor:
		printf("가위");
		break;

	case Paper:
		printf("보");
		break;
	}
	return 0;
}