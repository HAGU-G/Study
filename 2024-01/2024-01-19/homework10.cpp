#include <stdio.h>
#include <stdlib.h>

int findLast(int* arr, int size, int value);

int main()
{
	int arr[] = { 1,2,3,1,2,-1,4,-5,6,3,4,-1,1,2,3,5,2,3 }; //18°³

	int index = findLast(arr, _countof(arr), 3);
	printf("arr[%d] : %d\n", index, arr[index]);

	index = findLast(arr, _countof(arr), 1);
	printf("arr[%d] : %d\n", index, arr[index]);

	index = findLast(arr, _countof(arr), -1);
	printf("arr[%d] : %d\n", index, arr[index]);

	printf("find -6 : %d", findLast(arr, _countof(arr), -6));


	return 0;
}

int findLast(int* arr, int size, int value)
{
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] == value)
			return i;
	}

	return -1;
}