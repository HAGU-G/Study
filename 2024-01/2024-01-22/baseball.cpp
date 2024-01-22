//�߱� ����
//��ǻ�Ͱ� �� ���� ���ڸ� ���� �÷��̾ �� ���ڸ� ���ߴ� ���
//���� ���ڰ� �ִٸ� �� ������ŭ n ball
//���ڰ� ���� ��ġ�� �˸´ٸ� n strike
//3 strike�� ������ �¸�
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBERS 3 //�ٸ� ������ ���ڷε� ������ �� �� �ֵ��� ������ ������ ����


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

	//���� �ٸ� ���� n�� �̱�
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
	printf("��ǻ�Ͱ� ���� 0 ~ 9 �� %d���� ���߽��ϴ�.\n�߱� ������ �����մϴ�!\n", NUMBERS);
	printf("�Է� �� : 013, 829, 470\n\n");
	
	//���� ���ڰ� ���Դ��� Ȯ���ϱ� ���� �׽�Ʈ�ڵ�
	//for (int i = 0; i < _countof(computerNum); i++)
	//{
	//	printf("%d", computerNum[i]);
	//}

	while (true)
	{
		switch (state)
		{
		case Guess: //���� �ܰ�
		{
			printf("\n(%dȸ��) ���� %d���� �Է����ּ��� : ", count,NUMBERS);
			scanf_s("%s", inputNum, unsigned _countof(inputNum));
			while (!isNumbers(inputNum, _countof(inputNum)) )
			{
				bufferClear();
				printf("(%dȸ��) ���� %d���� �Է����ּ��� : ", count, NUMBERS);
				scanf_s("%s", inputNum, unsigned _countof(inputNum));
			}

			charToInt(inputNum, playerGuess, _countof(inputNum), _countof(playerGuess));

			if (checkAnswer(computerNum, playerGuess, _countof(computerNum)) == NUMBERS)
				state = End;
			else
				count++;

			break;
		}

		case End: //���� ����
		{
			printf("\n%dȸ ���� ������ ������ϴ�!\n��ǻ���� ���� :", count);
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



//�Էµ� ���� �������� �˻�, ���� ��� true
bool isNumbers(char* str, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return false;
	}
	return true;
}

//�Է¹��� ���� : �� �� �̻� �Է� ���� �� ���
void bufferClear()
{
	char temp = '\0';
	while (temp != '\n')
	{
		temp = getchar();
	}
}

//char�� �Էµ� ���ڸ� int �迭�� ����
void charToInt(char* str, int* num, int sSize, int nSize)
{
	for (int i = 0; i < nSize; i++)
	{
		num[i] = str[i] - 48;
	}
}

//����� ������ ���Ͽ� n��Ʈ����ũ n���� ���. ��Ʈ����ũ�� ���� ��ȯ
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
