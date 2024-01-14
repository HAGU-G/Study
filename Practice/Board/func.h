#pragma once


#define MAXROW 10
#define MAXCOL 10
#define STAGEOBJECT MAXROW * MAXCOL * 2
#define ACTCHAR 101

char stage[MAXROW][MAXCOL][2]; //실시간 스테이지 오브젝트 정보

int selectStageNum; //선택한 스테이지 번호
int selectStageRow; //선택한 스테이지 행
int selectStageCol; //선택한 스테이지 열
char selectStageObj[STAGEOBJECT]; //선택한 스테이지 오브젝트

int playerRow; //플레이어 행
int playerCol; //플레이어 열
wchar_t active[ACTCHAR] = L""; //행동(입력)


//타일 종류 (추가 시 printTile, isMovable 작성)
char tile_player = 'P';	//플레이어
char tile_air = '0';	//빈칸
char tile_ground = 'G';	//땅
char tile_clear = '1';	//클리어

void printTile(char tile_name)
{
	if (tile_player == tile_name)
		printf("＆");
	else if (tile_air == tile_name)
		printf("　");
	else if (tile_ground == tile_name)
		printf("▩");
	else if (tile_clear == tile_name)
		printf("★");
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



//화면에 그리기
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

	printf("이전 행동 : %S\n다음 행동을 입력해주세요 : ", active);
}

//스테이지 정보
typedef struct stageInfo {
	const int num;
	const int row;
	const int col;
	char objects[STAGEOBJECT];
} NEWSTAGE;

//스테이지 목록
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


//스테이지 불러오기
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

	//플레이어 위치 확인
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

//스테이지 선택
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

//클리어
void stageClear()
{
	selectStage(selectStageNum + 1);
	wcscpy_s(active, ACTCHAR, L"클리어!");
}


//플레이어 이동
void act(int input)
{
	switch (input)
	{
	case 1: //왼쪽
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
				wcscpy_s(active, ACTCHAR, L"왼쪽으로 이동");
			}
		}
	break;
	}
	case 2: //아래
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
				wcscpy_s(active, ACTCHAR, L"아래로 이동");
			}
		}
		break;
	}
	case 3: //오른쪽
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
				wcscpy_s(active, ACTCHAR, L"오른쪽으로 이동");
			}
		}
		break;
	}
	case 5: //위
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
				wcscpy_s(active, ACTCHAR, L"위로 이동");
			}
		}
		break;
	}
	case 0: //초기화
	{
		//selectStage(selectStageNum);
		stageLoad();
		break;
	}
	}//switch
}