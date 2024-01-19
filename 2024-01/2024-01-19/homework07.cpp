#include <stdio.h>
#include <stdlib.h>

int countGreater(int* arr, int size, int value);

int main()
{
	int arr[] = { 1,7,3,6,5,4,2,10,9,8 }; //1~10
	printf("%d\n", countGreater(arr, _countof(arr), 3));
	printf("%d\n", countGreater(arr, _countof(arr), 10));
	printf("%d\n", countGreater(arr, _countof(arr), 5));

	return 0;
}

int countGreater(int* arr, int size, int value)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > value)
			count++;
	}
	return count;
}
