#include <stdio.h>

void PrintArray(int parr[], int size);
//int* parr == int parr[] 매개변수가 앞 두가지 형태면 parr은 int의 포인터형이다.
//parr[2] 처럼 사이즈를 아무렇게나 적어줘도 똑같다. 컴파일 과정에서 int* parr로 변한다.
//함수에서 배열을 매개변수로 받을 때는 사이즈도 같이 받아오는 것이 좋다.

//2차원 배열을 넘길때는 행과 열의 사이즈를 모두 받아오는 것이 좋다.
//대신 받아올 배열은 (int*)로 형변환을 해줘야한다.

int main()
{
	int arr[4] = { 1,2,3,4 };
	PrintArray(arr,4);

	return 0;
}

void PrintArray(int parr[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", parr[i]);
	}
	printf("\n");
}
