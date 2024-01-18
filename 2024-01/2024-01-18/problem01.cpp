#include <stdio.h>
//인덱스 연산자 사용 금지


void reverseArray(int* array, int size);
void PrintArray(int* parr, int size);

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	PrintArray(arr, arrSize);
	reverseArray(arr, arrSize);
	PrintArray(arr, arrSize);

	return 0;
}

void reverseArray(int* array, int size)
{
	for (int* i = array; i < array + (size / 2); i++)
	{
		int temp = *i;
		*i = *(array + size - (i - array) - 1);
		*(array + size - (i - array) - 1) = temp;
	}
}

void PrintArray(int* parr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", *(parr + i));
	}
	printf("\n");
}