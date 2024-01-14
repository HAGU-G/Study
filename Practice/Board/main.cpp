#include"func.h"

int main()
{
	//로케일
	setlocale(LC_ALL, "korean");

	//스테이지 공백으로 초기화
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			wcscpy_s(stage[i][j], 2, L"　");
		}
	}

	do
	{

	} while (true);
	selectStage(1);
	draw();	draw();

}