#include <stdio.h>
#include <stdlib.h>

void PrintArray(int* parr, int size);

int insertAt(int* arr, int size, int index, int value);

int insertAt2(int* arr, int size, int index, int value);

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int arrSize = _countof(arr);

	arrSize = insertAt(arr, arrSize, 3, 100);
	printf("%d, ", arrSize);
	PrintArray(arr, arrSize);

	arrSize = insertAt(arr, arrSize, 2, 30);
	printf("%d, ", arrSize);
	PrintArray(arr, arrSize);

	arrSize = insertAt2(arr, arrSize, 5, -5);
	printf("%d, ", arrSize);
	PrintArray(arr, arrSize);

	return 0;
}

void PrintArray(int* parr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", *(parr + i));
	}
	printf("\n\n");
}

int insertAt(int* arr, int size, int index, int value)
{
	*(arr + index) = value;
	return size;
}

int insertAt2(int* arr, int size, int index, int value)
{
	for (int i = size-1; i > index; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[index] = value;

	return size;
}