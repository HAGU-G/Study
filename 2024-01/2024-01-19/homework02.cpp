#include <stdio.h>
#include <stdlib.h>

void PrintArray(int* parr, int size);

void swapArrays(int* a, int aSize, int* b, int bSize);

int main()
{
	int arr1[] = { 1, 2, 3, 4, 5, 6 };
	int arr2[] = { 10, 20, 30, 40, 50, 60 };
	int arr3[] = { 0, 1, 0, 1, 0, 1, 0};


	swapArrays(arr1, _countof(arr1), arr2, _countof(arr2));
	PrintArray(arr1, _countof(arr1));
	PrintArray(arr2, _countof(arr2));
	swapArrays(arr1, _countof(arr1), arr3, _countof(arr3));
	PrintArray(arr1, _countof(arr1));
	PrintArray(arr3, _countof(arr3));
	return 0;
}

void swapArrays(int* a, int aSize, int* b, int bSize)
{
	for (int i = 0; i < bSize; i++)
	{
		int temp = a[i];
		a[i] = b[i];
		b[i] = temp;

		if (i == aSize - 1)
			return;
	}

}


void PrintArray(int* parr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", *(parr + i));
	}
	printf("\n\n");
}