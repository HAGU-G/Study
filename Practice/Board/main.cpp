#include"func.h"

int main()
{
	//������
	setlocale(LC_ALL, "korean");

	//�������� �������� �ʱ�ȭ
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			wcscpy_s(stage[i][j], 2, L"��");
		}
	}

	do
	{

	} while (true);
	selectStage(1);
	draw();	draw();

}