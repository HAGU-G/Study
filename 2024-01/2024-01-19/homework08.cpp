#include <stdio.h>
#include <stdlib.h>

int countLess(int* arr, int size, int value);

int main()
{
	int arr[] = { 1,7,3,6,5,4,2,10,9,8 }; //1~10
	printf("%d\n", countLess(arr, _countof(arr), 7));
	printf("%d\n", countLess(arr, _countof(arr), -1));
	printf("%d\n", countLess(arr, _countof(arr), 2));

	return 0;
}

int countLess(int* arr, int size, int value)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < value)
			count++;
	}
	return count;
}
