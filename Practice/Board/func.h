#pragma once


#define MAXROW 10
#define MAXCOL 10
#define STAGEOBJECT MAXROW * MAXCOL * 2
#define ACTCHAR 101

char stage[MAXROW][MAXCOL][2]; //�ǽð� �������� ������Ʈ ����

int selectStageNum; //������ �������� ��ȣ
int selectStageRow; //������ �������� ��
int selectStageCol; //������ �������� ��
char selectStageObj[STAGEOBJECT]; //������ �������� ������Ʈ

int playerRow; //�÷��̾� ��
int playerCol; //�÷��̾� ��
wchar_t active[ACTCHAR] = L""; //�ൿ(�Է�)


//Ÿ�� ���� (�߰� �� printTile, isMovable �ۼ�)
char tile_player = 'P';	//�÷��̾�
char tile_air = '0';	//��ĭ
char tile_ground = 'G';	//��
char tile_clear = '1';	//Ŭ����

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
};

bool isMovable(char tile_name)
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



//ȭ�鿡 �׸���
void draw()
{
	system("cls");
	for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n");

	for (int i = 0; i < (MAXROW - selectStageRow) / 2; ++i) { for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n"); }
	for (int i = 0; i < selectStageRow; i++)
	{
		for (int i = 0; i < (MAXCOL - selectStageCol) / 2 + 1; ++i) { printTile(tile_ground); }
		for (int j = 0; j < selectStageCol; j++)
		{
			printTile(stage[i][j][0]);
		}
		for (int i = 0; i < (MAXCOL - selectStageCol) / 2 + 1; ++i) { printTile(tile_ground); } if (selectStageCol % 2 == 1) { printTile(tile_ground); } printf("\n");
	}

	for (int i = 0; i < (MAXROW - selectStageRow) / 2; ++i) { for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n"); }
	if (selectStageRow % 2 == 1) { for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n"); }


	for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n\n");

	printf("���� �ൿ : %S\n���� �ൿ�� �Է����ּ��� : ", active);
}

//�������� ����
typedef struct stageInfo {
	const int num;
	const int row;
	const int col;
	char objects[STAGEOBJECT];
} NEWSTAGE;

//�������� ���
NEWSTAGE Stage[2] = {
	{ 1, 6, 6,"\
0 0 0 0 0 0 \
0 0 0 0 0 0 \
0 0 0 1 0 0 \
0 0 0 0 0 0 \
0 0 0 0 0 0 \
0 P 0 0 0 0\0"}
	,{ 2, 4, 9,"\
1 0 0 0 G 0 0 0 0 \
0 0 G 0 G 0 0 P 0 \
0 0 G 0 G 0 0 0 0 \
0 0 G 0 0 0 0 0 0\0"}


};


//�������� �ҷ�����
void stageLoad()
{
	char object[STAGEOBJECT];
	strcpy_s(object, selectStageRow * selectStageCol * 2, selectStageObj);
	char* buffer;
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

//�������� ����
void selectStage(int stageNum)
{
	for (int i = 0; i < sizeof(Stage); ++i)
	{
		if (i + 1 == stageNum)
		{
			selectStageNum = Stage[i].num;
			selectStageRow = Stage[i].row;
			selectStageCol = Stage[i].col;
			strcpy_s(selectStageObj, selectStageRow * selectStageCol * 2, Stage[i].objects);
		}
	}
	stageLoad();
}

//Ŭ����
void stageClear()
{
	selectStage(selectStageNum + 1);
	wcscpy_s(active, ACTCHAR, L"Ŭ����!");
}


//�÷��̾� �̵�
void act(int input)
{
	switch (input)
	{
	case 1: //����
	{
		if (playerCol != 0)
		{
			if (stage[playerRow][playerCol - 1][0] == tile_clear)
			{
				stageClear();
			}
			else if (isMovable(stage[playerRow][playerCol - 1][0]))
			{
				stage[playerRow][playerCol - 1][0] = tile_player;
				stage[playerRow][playerCol][0] = tile_air;
				playerCol--;
				wcscpy_s(active, ACTCHAR, L"�������� �̵�");
			}
		}
	break;
	}
	case 2: //�Ʒ�
	{
		if (playerRow != selectStageRow-1)
		{
			if (stage[playerRow + 1][playerCol][0] == tile_clear)
			{
				stageClear();
			}
			else if (isMovable(stage[playerRow + 1][playerCol][0]))
			{
				stage[playerRow+1][playerCol][0] = tile_player;
				stage[playerRow][playerCol][0] = tile_air;
				playerRow++;
				wcscpy_s(active, ACTCHAR, L"�Ʒ��� �̵�");
			}
		}
		break;
	}
	case 3: //������
	{
		if (playerCol != selectStageCol - 1)
		{
			if (stage[playerRow][playerCol + 1][0] == tile_clear)
			{
				stageClear();
			}
			else
			if (isMovable(stage[playerRow][playerCol + 1][0]))
			{
				stage[playerRow][playerCol + 1][0] = tile_player;
				stage[playerRow][playerCol][0] = tile_air;
				playerCol++;
				wcscpy_s(active, ACTCHAR, L"���������� �̵�");
			}
		}
		break;
	}
	case 5: //��
	{
		if (playerRow != 0)
		{
			if (stage[playerRow - 1][playerCol][0] == tile_clear)
			{
				stageClear();
			}
			else if (isMovable(stage[playerRow - 1][playerCol][0]))
			{
				stage[playerRow - 1][playerCol][0] = tile_player;
				stage[playerRow][playerCol][0] = tile_air;
				playerRow--;
				wcscpy_s(active, ACTCHAR, L"���� �̵�");
			}
		}
		break;
	}
	case 0: //�ʱ�ȭ
	{
		//selectStage(selectStageNum);
		stageLoad();
		break;
	}
	}//switch
}