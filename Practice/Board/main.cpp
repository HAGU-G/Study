#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>
#include <conio.h>
#include "func.h"

int main()
{
	int input;

	//������(����� ���� ����)
	setlocale(LC_ALL, "korean");
	
	selectStage(1);
	do
	{

		draw();

		//rewind(stdin);

		input = _getch();
		act(input);


		/*if (scanf_s("%d", &input) == true)
		{
				act(input);
		}*/
	} while (input != 9);


}