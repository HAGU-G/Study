#include <stdio.h>
#include <stdlib.h>

int main()
{
	//다차원 배열을 1차원 배열로 표현했을때
	//배열의 요소에 접근하는 방법

	int arr2d[3][4] = { 0 };
	int arr[3 * 4] = { 0 };
	int a = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; i < 4; j++)
		{
			a = arr2d[i][j];
			a = arr[i * 4 + j];
			//arr3d[3][4][5];
			//a = arr3d[(i * 5 + j) * 4 + k)];
		}
	}



	return 0;
}