#include <stdio.h>
#include <stdlib.h>

void PrintArray(int* parr, int size);

int removeAt(int* arr, int size, int index);

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int arrSize = _countof(arr);

	arrSize = removeAt(arr, arrSize, 3);
	printf("%d, ", arrSize);
	PrintArray(arr, arrSize);

	arrSize = removeAt(arr, arrSize, 2);
	printf("%d, ", arrSize);
	PrintArray(arr, arrSize);

	arrSize = removeAt(arr, arrSize, 5);
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

int removeAt(int* arr, int size, int index)
{
	int resize = 0;
	for (int i = 0, j = 0; i < size; i++)
	{
		if (i != index)
		{
			arr[j] = arr[i];
			j++;
			resize++;
		}
	}
	return resize;
}