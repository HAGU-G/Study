#include <stdio.h>
#include <stdlib.h>

void PrintArray(int* parr, int size);

void reverseRange(int* arr, int start, int end);

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	reverseRange(arr, 1, 8);
	PrintArray(arr, _countof(arr));
	reverseRange(arr, 2, 6);
	PrintArray(arr, _countof(arr));
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

void reverseRange(int* arr, int start, int end)
{
	for (int i = start; i < (start + end) / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[end - (i - start)];
		arr[end - (i - start)] = temp;
	}
}