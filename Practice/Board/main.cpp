#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define MAXROW 10 //최대 행 *수정 가능
#define MAXCOL 13 //최대 열 *수정 가능
#define ACTCHAR 100 //이전 행동 출력 최대 크기 *수정 가능
#define STAGEOBJECT MAXROW * MAXCOL * 2 //오브젝트 정보의 최대 크기

char stage[MAXROW][MAXCOL][2]; //실시간 스테이지 오브젝트 정보를 담을 배열

int selectStageNum; //선택한 스테이지 번호
int selectStageRow; //선택한 스테이지 행
int selectStageCol; //선택한 스테이지 열

int playerRow; //플레이어 행
int playerCol; //플레이어 열
char active[ACTCHAR] = ""; //행동(입력)


//타일 종류 (추가 시 printTile, isMovable 작성)
char tile_player = 'P';	//플레이어
char tile_air = '0';	//빈칸
char tile_ground = 'G';	//땅
char tile_clear = '1';	//클리어
char tile_ball = 'B';

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
	else if (tile_ball == tile_name)
		printf("㉿");
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

//화면에 그리기
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

	printf("　　　　↑　　　재시작：Enter\n이동：←↓→　　종료：ESC\n\n");
	printf("이전 행동 : %s", active);
}

//스테이지에 넣어야할 멤버
typedef struct {
	const int num;
	const int row;
	const int col;
	char objects[STAGEOBJECT];
} NEWSTAGE;

//스테이지 목록
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

//스테이지 선택 및 불러오기
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
			}
			else if (isPush(stage[playerRow][playerCol - 1][0]))
			{
				if (isMove(stage[playerRow][playerCol - 2][0]))
				{
					stage[playerRow][playerCol - 2][0] = tile_ball;
					stage[playerRow][playerCol - 1][0] = tile_player;
					stage[playerRow][playerCol][0] = tile_air;
					playerCol -= 1;
					strcpy_s(active, ACTCHAR, "공을 왼쪽으로 이동");
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
			}
			else if (isPush(stage[playerRow + 1][playerCol][0]))
			{
				if (isMove(stage[playerRow + 2][playerCol][0]))
				{
					stage[playerRow + 2][playerCol][0] = tile_ball;
					stage[playerRow + 1][playerCol][0] = tile_player;
					stage[playerRow][playerCol][0] = tile_air;
					playerRow += 1;
					strcpy_s(active, ACTCHAR, "공을 아래로 이동　");
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
			}
			else if (isPush(stage[playerRow][playerCol + 1][0]))
			{
				if (isMove(stage[playerRow][playerCol + 2][0]))
				{
					stage[playerRow][playerCol + 2][0] = tile_ball;
					stage[playerRow][playerCol + 1][0] = tile_player;
					stage[playerRow][playerCol][0] = tile_air;
					playerCol += 1;
					strcpy_s(active, ACTCHAR, "공을 우측으로 이동");
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
			}
			else if (isPush(stage[playerRow - 1][playerCol][0]))
			{
				if (isMove(stage[playerRow - 2][playerCol][0]))
				{
					stage[playerRow - 2][playerCol][0] = tile_ball;
					stage[playerRow - 1][playerCol][0] = tile_player;
					stage[playerRow][playerCol][0] = tile_air;
					playerRow -= 1;
					strcpy_s(active, ACTCHAR, "공을 위로 이동　　");
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