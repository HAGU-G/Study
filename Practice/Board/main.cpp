#include<stdio.h>
#include<locale.h>
#include<wchar.h>
#include<windows.h>
#include"func.h"

int main()
{
	int input;

	//������(����� ���� ����)
	setlocale(LC_ALL, "korean");
	
	selectStage(3);
	do
	{

		draw();

		rewind(stdin);
		if (scanf_s("%d", &input) == true)
		{
				act(input);
		}
	} while (input != 9);


}