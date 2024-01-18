#include <stdio.h>
#include <stdlib.h>
//인덱스 연산자 사용 금지


void swapElements(int* arr, int size, int index1, int index2);
void PrintArray(int* parr, int size);

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int arrSize = _countof(arr);

	PrintArray(arr, arrSize);
	swapElements(arr, arrSize, 0, 7);
	PrintArray(arr, arrSize);
	swapElements(arr, arrSize, 1, 2);
	PrintArray(arr, arrSize);
	swapElements(arr, arrSize, -1, 5);
	PrintArray(arr, arrSize);

	return 0;
}

void swapElements(int* arr, int size, int index1, int index2)
{
	if (arr + index1 < arr || arr + index1 > arr + size)
		return;
	if (arr + index2 < arr || arr + index2 > arr + size)
		return;

	int temp = *(arr + index1);
	*(arr + index1) = *(arr + index2);
	*(arr + index2) = temp;
}

void PrintArray(int* parr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", *(parr + i));
	}
	printf("\n");
}