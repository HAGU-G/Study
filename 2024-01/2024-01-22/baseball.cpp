//야구 게임
//컴퓨터가 세 개의 숫자를 고르고 플레이어가 그 숫자를 맞추는 방식
//같은 숫자가 있다면 그 개수만큼 n ball
//숫자가 같고 위치도 알맞다면 n strike
//3 strike가 나오면 승리
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBERS 3 //다른 개수의 숫자로도 게임을 할 수 있도록 숫자의 개수를 정의


enum {
	Guess,
	End
};

bool isNumbers(char* str, int size);
void bufferClear();
void charToInt(char* str, int* num, int sSize, int nSize);
int checkAnswer(int* answer, int* guess, int size);

int main()
{
	srand(time(NULL));
	int computerNum[NUMBERS] = { 0 };
	int playerGuess[NUMBERS] = { 0 };
	char inputNum[NUMBERS+1] = {'\0'};
	int state = Guess;
	int count = 1;

	//서로 다른 숫자 n개 뽑기
	for (int i = 0; i < _countof(computerNum); i++)
	{
		bool isSame = false;
		do
		{
			computerNum[i] = rand() % 10;
			for (int j = 0; j < i; j++)
			{
				if (computerNum[j] == computerNum[i])
				{
					isSame = true;
					break;
				}
				else
					isSame = false;
			}
		} while (isSame);
	}
	printf("컴퓨터가 숫자 0 ~ 9 중 %d개를 정했습니다.\n야구 게임을 진행합니다!\n", NUMBERS);
	printf("입력 예 : 013, 829, 470\n\n");
	
	//무슨 숫자가 나왔는지 확인하기 위한 테스트코드
	//for (int i = 0; i < _countof(computerNum); i++)
	//{
	//	printf("%d", computerNum[i]);
	//}

	while (true)
	{
		switch (state)
		{
		case Guess: //추측 단계
		{
			printf("\n(%d회차) 숫자 %d개를 입력해주세요 : ", count,NUMBERS);
			scanf_s("%s", inputNum, unsigned _countof(inputNum));
			while (!isNumbers(inputNum, _countof(inputNum)) )
			{
				bufferClear();
				printf("(%d회차) 숫자 %d개를 입력해주세요 : ", count, NUMBERS);
				scanf_s("%s", inputNum, unsigned _countof(inputNum));
			}

			charToInt(inputNum, playerGuess, _countof(inputNum), _countof(playerGuess));

			if (checkAnswer(computerNum, playerGuess, _countof(computerNum)) == NUMBERS)
				state = End;
			else
				count++;

			break;
		}

		case End: //게임 종료
		{
			printf("\n%d회 만에 정답을 맞췄습니다!\n컴퓨터의 숫자 :", count);
			for (int i = 0; i < _countof(computerNum); i++)
			{
				printf("%d", computerNum[i]);
			}
			printf("\n");

			return 0;
			break;
		}
		}//switch
	}



	return 0;
}



//입력된 것이 숫자인지 검사, 맞을 경우 true
bool isNumbers(char* str, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return false;
	}
	return true;
}

//입력버퍼 비우기 : 한 번 이상 입력 받은 후 사용
void bufferClear()
{
	char temp = '\0';
	while (temp != '\n')
	{
		temp = getchar();
	}
}

//char로 입력된 숫자를 int 배열로 복사
void charToInt(char* str, int* num, int sSize, int nSize)
{
	for (int i = 0; i < nSize; i++)
	{
		num[i] = str[i] - 48;
	}
}

//정답과 추측을 비교하여 n스트라이크 n볼을 출력. 스트라이크의 수를 반환
int checkAnswer(int* answer, int* guess, int size)
{
	int strike = 0;
	int ball = 0;
	for (int i = 0; i < size; i++)
	{
		if (answer[i] == guess[i])
		{
			strike++;
			continue;
		}

		for (int j = 0; j < size; j++)
		{
			if (answer[j] == guess[i])
			{
				ball++;
				break;
			}
		}
	}
	printf("%d Strike / %d ball\n", strike, ball);

	return strike;
}
