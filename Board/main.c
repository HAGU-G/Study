#include<stdio.h>

int main()
{
	//3차원 배열을 활용한 2차원 배열 위 문자열 출력
	//전각문자를 사용하여 6x6 보드를 만들 예정

	char table[6][6][3]; //행, 열, 문자열 길이(null 포함)

	//배열 초기화
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				table[i][j][k] = '\0';
			}
		}
	}

	//문자열 복사와 출력
	for (int i = 0; i < 6; i++) //행 반복
	{
		for (int j = 0; j < 6; j++) //열 반복
		{
			//문자열 복사
			strcpy_s(table[i][j],3,"□");

			//출력
			//printf("%s", table[i][j]); 
			//문자열 복사 과정에서 생긴 오류로 인해 각 타일의 길이가 변하지 않도록 아래의 코드를 사용
			printf("%c%c", table[i][j][0],table[i][j][1]);

		}
		printf("\n");

	}

}
