#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define MAXROW 10 //최대 행 *수정 가능
#define MAXCOL 14 //최대 열 *수정 가능
#define ACTCHAR 200 //이전 행동 출력 최대 크기 *수정 가능
#define STAGEOBJECT MAXROW * MAXCOL * 2 //오브젝트 정보의 최대 크기

char stage[MAXROW][MAXCOL][2]; //실시간 스테이지 오브젝트 정보를 담을 배열
int selectStageNum; //선택한 스테이지 번호
int selectStageRow; //선택한 스테이지 행
int selectStageCol; //선택한 스테이지 열

int playerRow; //플레이어 위치 : 행
int playerCol; //플레이어 위치 : 열
int moveCount = 0; //움직인 횟수
char active[ACTCHAR] = ""; //이전 행동 기록
int stageMoveCount[6] = { 0 };

//타일 종류 (추가 시 printTile, isMove, isPush 작성)
char tile_player = 'P';	//플레이어
char tile_air = '0';	//빈칸
char tile_ground = 'G';	//땅
char tile_clear = '1';	//클리어
char tile_ball = 'B';	//공

void printTile(char tile_name)
{
	if (tile_player == tile_name)
		printf("♀");
	else if (tile_air == tile_name)
		printf("　");
	else if (tile_ground == tile_name)
		printf("▩");
	else if (tile_clear == tile_name)
		printf("♨");
	else if (tile_ball == tile_name)
		printf("㉿");
};
bool isMove(char tile_name)
{
	return tile_air == tile_name;
}
bool isPush(char tile_name)
{
	return tile_ball == tile_name;
}

//게임화면
void draw()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 0 });

	for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n");
	for (int i = 0; i < (MAXROW - selectStageRow) / 2; ++i) { for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n"); }

	for (int i = 0; i < selectStageRow; i++)
	{
		for (int i = 0; i < (MAXCOL - selectStageCol) / 2 + 1; ++i) { printTile(tile_ground); }
		for (int j = 0; j < selectStageCol; j++) { printTile(stage[i][j][0]); }
		for (int i = 0; i < (MAXCOL - selectStageCol) / 2 + 1; ++i) { printTile(tile_ground); } if (MAXCOL % 2 != selectStageCol % 2) { printTile(tile_ground); } printf("\n");
	}

	for (int i = 0; i < (MAXROW - selectStageRow) / 2; ++i) { for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n"); }
	if (MAXROW % 2 != selectStageRow % 2) { for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n"); }
	for (int i = 0; i < MAXCOL + 2; ++i) { printTile(tile_ground); } printf("\n");

	printf("\n　　　　↑　　　재시작：Enter\n이동：←↓→　　종료　：ESC\n\n");
	printf("%s　　\n\n", active);
	printf("< Stage %d > -- %d턴 째　", selectStageNum, moveCount);
}

//스테이지에 넣어야할 정보
typedef struct {
	const int num;
	const int row;
	const int col;
	char objects[STAGEOBJECT];
} NEWSTAGE;

//스테이지 목록
NEWSTAGE Stage[] = {
	{ 1, 6, 6,
	"0 0 0 0 0 0 "
	"0 0 0 0 0 0 "
	"0 0 0 0 0 1 "
	"0 0 0 0 0 0 "
	"0 0 0 0 0 0 "
	"0 P 0 0 0 0"}
	, { 2, 4, 9,
	"1 0 0 0 G 0 0 0 0 "
	"0 0 G 0 G 0 P 0 0 "
	"0 0 G 0 G 0 0 0 0 "
	"0 0 G 0 0 0 0 0 0"}
	,{ 3, 7, 9,
	"G G 0 0 0 0 G G G "
	"G G 0 B G 1 G G G "
	"P G 0 0 G 0 G G G "
	"0 G G B B 0 0 0 0 "
	"0 G 0 0 G G G G G "
	"0 B 0 0 G G G G G "
	"G G 0 0 G G G G G"}
	,{ 4, 5, 7,
	"G 0 0 0 P G G "
	"G 0 0 B B 1 G "
	"G 0 0 0 B 0 G "
	"G 0 0 0 0 G G "
	"G G G 0 0 0 0 "
	"G G G G 0 G G"}
	,{ 5, 5, 4,
	"0 B 0 G "
	"0 0 B P "
	"1 B B B "
	"0 B 0 0 "
	"G 0 0 G"}
	,{ 6, 10, 14,
	"0 0 0 0 0 0 0 B 0 G G G G 0 "
	"0 0 0 0 0 G 0 B 0 0 0 G 1 0 "
	"0 0 G G G 0 B 0 0 G 0 G G 0 "
	"G 0 0 0 B B B B G 0 0 0 G 0 "
	"0 B B 0 G P G 0 G 0 B 0 B 0 "
	"0 B 0 0 G 0 G 0 G 0 0 0 G 0 "
	"0 G G B 0 0 0 0 G G G 0 G 0 "
	"0 G 0 0 G G G G G 0 0 B B 0 "
	"0 0 B 0 0 0 0 G 0 B 0 0 B 0 "
	"0 0 0 0 0 0 0 0 0 G G 0 0 0"}
	,{ 7, 10, 14,
	"0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
	"0 0 0 0 0 0 0 0 0 0 0 0 P 0 "
	"0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
	"0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
	"0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
	"0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
	"0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
	"0 0 0 0 0 0 0 0 0 0 G B 1 0 "
	"0 0 0 0 0 0 0 0 0 0 0 0 0 0 "
	"0 0 0 0 0 0 0 0 0 0 0 0 0 0"}


};

//스테이지 선택 및 불러오기
void selectStage(int stageNum)
{
	moveCount = 1;
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

	//오브젝트 배치
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

//클리어
void stageClear()
{
	stageMoveCount[selectStageNum - 1] = moveCount;
	selectStage(selectStageNum + 1);
	strcpy_s(active, ACTCHAR, "클리어!　　　　 　");
}

//플레이어 이동
void act(int input)
{
	switch (input)
	{
	case 75: //왼쪽
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
				strcpy_s(active, ACTCHAR, "왼쪽으로 이동 　　");
				moveCount++;
			}
			else if (playerCol > 1)
			{
				if (isPush(stage[playerRow][playerCol - 1][0]))
				{
					if (isMove(stage[playerRow][playerCol - 2][0]))
					{
						stage[playerRow][playerCol - 2][0] = tile_ball;
						stage[playerRow][playerCol - 1][0] = tile_player;
						stage[playerRow][playerCol][0] = tile_air;
						playerCol -= 1;
						strcpy_s(active, ACTCHAR, "공을 왼쪽으로 이동");
						moveCount++;
					}
				}
			}
		}
		break;
	}
	case 80: //아래
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
				strcpy_s(active, ACTCHAR, "아래로 이동　　 　");
				moveCount++;
			}
			else if (playerRow < selectStageRow - 2)
			{
				if (isPush(stage[playerRow + 1][playerCol][0]))
				{
					if (isMove(stage[playerRow + 2][playerCol][0]))
					{
						stage[playerRow + 2][playerCol][0] = tile_ball;
						stage[playerRow + 1][playerCol][0] = tile_player;
						stage[playerRow][playerCol][0] = tile_air;
						playerRow += 1;
						strcpy_s(active, ACTCHAR, "공을 아래로 이동　");
						moveCount++;
					}
				}
			}
		}
		break;
	}
	case 77: //오른쪽
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
				strcpy_s(active, ACTCHAR, "오른쪽으로 이동 　");
				moveCount++;
			}
			else if (playerCol < selectStageCol - 2)
			{
				if (isPush(stage[playerRow][playerCol + 1][0]))
				{
					if (isMove(stage[playerRow][playerCol + 2][0]))
					{
						stage[playerRow][playerCol + 2][0] = tile_ball;
						stage[playerRow][playerCol + 1][0] = tile_player;
						stage[playerRow][playerCol][0] = tile_air;
						playerCol += 1;
						strcpy_s(active, ACTCHAR, "공을 우측으로 이동");
						moveCount++;
					}
				}
			}
		}
		break;
	}
	case 72: //위
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
				strcpy_s(active, ACTCHAR, "위로 이동　　　 　");
				moveCount++;
			}
			else if (playerRow > 1)
			{
				if (isPush(stage[playerRow - 1][playerCol][0]))
				{
					if (isMove(stage[playerRow - 2][playerCol][0]))
					{
						stage[playerRow - 2][playerCol][0] = tile_ball;
						stage[playerRow - 1][playerCol][0] = tile_player;
						stage[playerRow][playerCol][0] = tile_air;
						playerRow -= 1;
						strcpy_s(active, ACTCHAR, "공을 위로 이동　　");
						moveCount++;
					}
				}
			}
		}
		break;
	}
	case 13: //초기화
	{
		selectStage(selectStageNum);
		break;
	}
	}//switch
}

int main()
{
	//콘솔 설정
	{
		system("mode con:cols=34 lines=20");
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

	} while (!(input == 27 || selectStageNum == 7));

	if (selectStageNum == 7)
	{
		draw();
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 4, 2 });
			printf("Stage 1 : %d", stageMoveCount[0]);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 4, 3 });
			printf("Stage 2 : %d", stageMoveCount[1]);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 4, 4 });
			printf("Stage 3 : %d", stageMoveCount[2]);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 4, 5 });
			printf("Stage 4 : %d", stageMoveCount[3]);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 4, 6 });
			printf("Stage 5 : %d", stageMoveCount[4]);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 4, 7 });
			printf("Stage 6 : %d", stageMoveCount[5]);
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 4, 9 });
			printf("　　　　　　　　ＥＮＤ！");
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0, 18 });
			printf("2024-01-18 조병민　　　　");
		}
		input = _getch();
	}
	return 0;
}