#include"func.h"

int main()
{
	int input;

	//������
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
				wcscpy_s(active, 101, L"�������� �̵�");
				break;
			}
			case 2:
			{
				wcscpy_s(active, 101, L"�Ʒ��� �̵�");
				break;
			}
			case 3:
			{
				wcscpy_s(active, 101, L"���������� �̵�");
				break;
			}
			case 4:
			{
				wcscpy_s(active, 101, L"���� �̵�");
				break;
			}

			}
		}
	} while (input != 9);


}