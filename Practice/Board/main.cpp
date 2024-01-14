#include"func.h"

int main()
{
	int input;

	//로케일
	setlocale(LC_ALL, "korean");
	selectStage(1);

	do
	{

		draw();

		rewind(stdin);
		if (scanf_s("%d", &input) == true)
		{
			switch (input)
			{
			case 1:
			{
				move(input);
				wcscpy_s(active, 101, L"왼쪽으로 이동");
				break;
			}
			case 2:
			{
				wcscpy_s(active, 101, L"아래로 이동");
				break;
			}
			case 3:
			{
				wcscpy_s(active, 101, L"오른쪽으로 이동");
				break;
			}
			case 4:
			{
				wcscpy_s(active, 101, L"위로 이동");
				break;
			}

			}
		}
	} while (input != 9);


}