#include <stdio.h>
//인덱스 연산자 사용 금지

void PrintArray(int* parr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", *(parr + i));
	}
	printf("\n");
}

void reverseArray(int* array, int size);

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	PrintArray(arr, arrSize);
	reverseArray(arr, arrSize);
	PrintArray(arr, arrSize);

	return 0;
}

void reverseArray(int* array, int size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int temp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = temp;
	}
}
