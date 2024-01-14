#pragma once
#include<stdio.h>
#include<locale.h>
#include<wchar.h>
#include<windows.h>

#define MAXROW 10
#define MAXCOL 10
#define STAGEOBJECT MAXROW * MAXCOL * 2

wchar_t stage[MAXROW][MAXCOL][2]; //실시간 스테이지 오브젝트 정보

int selectStageNum; //선택한 스테이지 번호
int selectStageRow; //선택한 스테이지 행
int selectStageCol; //선택한 스테이지 열
wchar_t selectStageObj[STAGEOBJECT]; //선택한 스테이지 오브젝트


//타일 종류
wchar_t tile_player[2] = L"＆"; //플레이어
wchar_t tile_ground[2] = L"▩"; //땅

//화면에 그리기
void draw()
{
	system("cls");
	for (int i = 0; i < MAXCOL + 2; ++i) { printf("%S", tile_ground); } printf("\n");

	for (int i = 0; i < (MAXROW - selectStageRow) / 2; ++i) { for (int i = 0; i < MAXCOL + 2; ++i) { printf("%S", tile_ground); } printf("\n"); }
	for (int i = 0; i < selectStageRow; i++)
	{
		for (int i = 0; i < (MAXCOL - selectStageCol) / 2 + 1; ++i) { printf("%S", tile_ground); }
		for (int j = 0; j < selectStageCol; j++)
		{
			printf("%S", stage[i][j]);
		}
		for (int i = 0; i < (MAXCOL - selectStageCol) / 2 + 1; ++i) { printf("%S", tile_ground); } if (selectStageCol % 2 == 1) { printf("%S", tile_ground); } printf("\n");
	}

	for (int i = 0; i < (MAXROW - selectStageRow) / 2; ++i) { for (int i = 0; i < MAXCOL + 2; ++i) { printf("%S", tile_ground); } printf("\n"); }
	if (selectStageRow % 2 == 1) { for (int i = 0; i < MAXCOL + 2; ++i) { printf("%S", tile_ground); } printf("\n"); }


	for (int i = 0; i < MAXCOL + 2; ++i) { printf("%S", tile_ground); } printf("\n\n");

	printf("행동을 입력해주세요 : ");
}

//스테이지 정보
typedef struct stageInfo {
	const int num;
	const int row;
	const int col;
	wchar_t objects[STAGEOBJECT];
} NEWSTAGE;

//스테이지 목록
NEWSTAGE Stage[1] = {
	{ 1, 6, 6,L"\
　,　,　,　,　,　,\
　,　,　,　,　,　,\
　,　,　,　,　,　,\
　,　,　,　,　,　,\
　,　,　,　,　,　,\
＆,　,　,　,　,　"}



};

//스테이지 불러오기
void stageLoad()
{
	wchar_t* object = selectStageObj;
	wchar_t* buffer;
	wchar_t* token = wcstok_s(object, L",", &buffer);
	for (int i = 0; i < selectStageRow; i++)
	{
		for (int j = 0; j < selectStageCol; j++)
		{
			wcscpy_s(stage[i][j], 2, token);
			token = wcstok_s(NULL, L",", &buffer);
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
			selectStageRow = Stage[i].row;
			selectStageCol = Stage[i].col;
			wcscpy_s(selectStageObj, 72, Stage[i].objects);
		}
	}
	stageLoad();
}

//이동
void move()
{}