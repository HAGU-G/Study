#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define MAXROW 10 //�ִ� �� *���� ����
#define MAXCOL 13 //�ִ� �� *���� ����
#define ACTCHAR 100 //���� �ൿ ��� �ִ� ũ�� *���� ����
#define STAGEOBJECT MAXROW * MAXCOL * 2 //������Ʈ ������ �ִ� ũ��

char stage[MAXROW][MAXCOL][2]; //�ǽð� �������� ������Ʈ ������ ���� �迭

int selectStageNum; //������ �������� ��ȣ
int selectStageRow; //������ �������� ��
int selectStageCol; //������ �������� ��

int playerRow; //�÷��̾� ��
int playerCol; //�÷��̾� ��
char active[ACTCHAR] = ""; //�ൿ(�Է�)


//Ÿ�� ���� (�߰� �� printTile, isMovable �ۼ�)
char tile_player = 'P';	//�÷��̾�
char tile_air = '0';	//��ĭ
char tile_ground = 'G';	//��
char tile_clear = '1';	//Ŭ����
char tile_ball = 'B';

void printTile(char tile_name)
{
	if (tile_player == tile_name)
		printf("��");
	else if (tile_air == tile_name)
		printf("��");
	else if (tile_ground == tile_name)
		printf("��");
	else if (tile_clear == tile_name)
		printf("��");
	else if (tile_ball == tile_name)
		printf("��");
};
bool isMove(char tile_name)
{
	if (tile_air == tile_name)
	{
		return true;
	}
	else
	{
		return false;
	}

}
bool isPush(char tile_name)
{
	if (tile_ball == tile_name)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//ȭ�鿡 �׸���
void draw()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });
	for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n");

	for (int i = 0; i < (MAXROW - selectStageRow) / 2; ++i) { for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n"); }
	for (int i = 0; i < selectStageRow; i++)
	{
		for (int i = 0; i < (MAXCOL - selectStageCol) / 2 + 1; ++i) { printTile(tile_ground); }
		for (int j = 0; j < selectStageCol; j++)
		{
			printTile(stage[i][j][0]);
		}
		for (int i = 0; i < (MAXCOL - selectStageCol) / 2 + 1; ++i) { printTile(tile_ground); } if (MAXCOL % 2 != selectStageCol % 2) { printTile(tile_ground); } printf("\n");
	}

	for (int i = 0; i < (MAXROW - selectStageRow) / 2; ++i) { for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n"); }
	if (MAXROW % 2 != selectStageRow % 2) { for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n"); }


	for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n\n");

	printf("���������衡��������ۣ�Enter\n�̵������桡�����᣺ESC\n\n");
	printf("���� �ൿ : %s", active);
}

//���������� �־���� ���
typedef struct {
	const int num;
	const int row;
	const int col;
	char objects[STAGEOBJECT];
} NEWSTAGE;

//�������� ���
NEWSTAGE Stage[5] = {
	{ 1, 6, 6,
	"0 0 0 0 0 0 "
	"0 0 0 0 0 0 "
	"0 0 0 1 0 0 "
	"0 0 0 0 0 0 "
	"0 0 0 0 0 0 "
	"0 P 0 0 0 0"}
	, { 2, 4, 9,
	"1 0 0 0 G 0 0 0 0 "
	"0 0 G 0 G 0 0 P 0 "
	"0 0 G 0 G 0 0 0 0 "
	"0 0 G 0 0 0 0 0 0"}
	,{ 3, 7, 3,
	"P G 1 "
	"0 G 0 "
	"0 G 0 "
	"0 G 0 "
	"B 0 0 "
	"0 G 0 "
	"0 0 0"}
	,{ 4, 10, 10,
	"0 0 0 0 G 0 0 0 0 P "
	"0 0 0 B 0 0 0 0 0 0 "
	"0 G G G G G G B B G "
	"0 G 0 1 G 0 0 0 0 G "
	"0 G 0 G G 0 0 0 0 G "
	"0 0 B 0 G B G 0 0 G "
	"0 G 0 G 0 0 G 0 0 G "
	"0 0 0 0 0 0 G G 0 0 "
	"G G G 0 G B 0 0 0 0 "
	"G G G 0 0 0 G G 0 0"}
	,{ 5, 4, 4,
	"0 0 0 0 "
	"0 0 B P "
	"0 0 0 0 "
	"0 0 0 0"}


};

//�������� ���� �� �ҷ�����
void selectStage(int stageNum)
{
	char object[STAGEOBJECT] = "";
	char* buffer = nullptr;

	for (int i = 0; i < sizeof(Stage); ++i)
	{
		if (i + 1 == stageNum)
		{
			selectStageNum = Stage[i].num;
			selectStageRow = Stage[i].row;
			selectStageCol = Stage[i].col;
			strcpy_s(object, STAGEOBJECT, Stage[i].objects);
		}
	}

	//������Ʈ ��ġ
	char* token = strtok_s(object, " ", &buffer);
	for (int i = 0; i < selectStageRow; i++)
	{
		for (int j = 0; j < selectStageCol; j++)
		{
			stage[i][j][0] = token[0];
			token = strtok_s(NULL, " ", &buffer);
		}
	}

	//�÷��̾� ��ġ Ȯ��
	for (int i = 0; i < selectStageRow; i++)
	{
		for (int j = 0; j < selectStageCol; j++)
		{
			if (stage[i][j][0] == tile_player)
			{
				playerRow = i;
				playerCol = j;
			}
		}
	}
}

//Ŭ����
void stageClear()
{
	selectStage(selectStageNum + 1);
	strcpy_s(active, ACTCHAR, "Ŭ����!�������� ��");
}

//�÷��̾� �̵�
void act(int input)
{
	switch (input)
	{
	case 75: //����
	{
		if (playerCol != 0)
		{
			if (stage[playerRow][playerCol - 1][0] == tile_clear)
			{
				stageClear();
			}
			else if (isMove(stage[playerRow][playerCol - 1][0]))
			{
				stage[playerRow][playerCol - 1][0] = tile_player;
				stage[playerRow][playerCol][0] = tile_air;
				playerCol--;
				strcpy_s(active, ACTCHAR, "�������� �̵� ����");
			}
			else if (isPush(stage[playerRow][playerCol - 1][0]))
			{
				if (isMove(stage[playerRow][playerCol - 2][0]))
				{
					stage[playerRow][playerCol - 2][0] = tile_ball;
					stage[playerRow][playerCol - 1][0] = tile_player;
					stage[playerRow][playerCol][0] = tile_air;
					playerCol -= 1;
					strcpy_s(active, ACTCHAR, "���� �������� �̵�");
				}
			}
		}
		break;
	}
	case 80: //�Ʒ�
	{
		if (playerRow != selectStageRow - 1)
		{
			if (stage[playerRow + 1][playerCol][0] == tile_clear)
			{
				stageClear();
			}
			else if (isMove(stage[playerRow + 1][playerCol][0]))
			{
				stage[playerRow + 1][playerCol][0] = tile_player;
				stage[playerRow][playerCol][0] = tile_air;
				playerRow++;
				strcpy_s(active, ACTCHAR, "�Ʒ��� �̵����� ��");
			}
			else if (isPush(stage[playerRow + 1][playerCol][0]))
			{
				if (isMove(stage[playerRow + 2][playerCol][0]))
				{
					stage[playerRow + 2][playerCol][0] = tile_ball;
					stage[playerRow + 1][playerCol][0] = tile_player;
					stage[playerRow][playerCol][0] = tile_air;
					playerRow += 1;
					strcpy_s(active, ACTCHAR, "���� �Ʒ��� �̵���");
				}
			}
		}
		break;
	}
	case 77: //������
	{
		if (playerCol != selectStageCol - 1)
		{
			if (stage[playerRow][playerCol + 1][0] == tile_clear)
			{
				stageClear();
			}
			else if (isMove(stage[playerRow][playerCol + 1][0]))
			{
				stage[playerRow][playerCol + 1][0] = tile_player;
				stage[playerRow][playerCol][0] = tile_air;
				playerCol++;
				strcpy_s(active, ACTCHAR, "���������� �̵� ��");
			}
			else if (isPush(stage[playerRow][playerCol + 1][0]))
			{
				if (isMove(stage[playerRow][playerCol + 2][0]))
				{
					stage[playerRow][playerCol + 2][0] = tile_ball;
					stage[playerRow][playerCol + 1][0] = tile_player;
					stage[playerRow][playerCol][0] = tile_air;
					playerCol += 1;
					strcpy_s(active, ACTCHAR, "���� �������� �̵�");
				}
			}
		}
		break;
	}
	case 72: //��
	{
		if (playerRow != 0)
		{
			if (stage[playerRow - 1][playerCol][0] == tile_clear)
			{
				stageClear();
			}
			else if (isMove(stage[playerRow - 1][playerCol][0]))
			{
				stage[playerRow - 1][playerCol][0] = tile_player;
				stage[playerRow][playerCol][0] = tile_air;
				playerRow--;
				strcpy_s(active, ACTCHAR, "���� �̵������� ��");
			}
			else if (isPush(stage[playerRow - 1][playerCol][0]))
			{
				if (isMove(stage[playerRow - 2][playerCol][0]))
				{
					stage[playerRow - 2][playerCol][0] = tile_ball;
					stage[playerRow - 1][playerCol][0] = tile_player;
					stage[playerRow][playerCol][0] = tile_air;
					playerRow -= 1;
					strcpy_s(active, ACTCHAR, "���� ���� �̵�����");
				}
			}
		}
		break;
	}
	case 13: //�ʱ�ȭ
	{
		selectStage(selectStageNum);
		break;
	}
	}//switch
}

int main()
{
	//�ܼ� ����
	{
		system("mode con:cols=30 lines=18");
		CONSOLE_CURSOR_INFO cursorVisivle = { 100, FALSE };
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorVisivle);
	}

	int input;
	selectStage(1);

	do
	{
		draw();
		input = _getch();
		act(input);

		/*if (scanf_s("%d", &input) == true)
		{
				act(input);
		}*/
	} while (input != 27);

}