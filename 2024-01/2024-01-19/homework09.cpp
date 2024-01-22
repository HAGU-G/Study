#include <stdio.h>
#include <stdlib.h>

int findFirstGreater(int* arr, int size, int value);

int main()
{
	int arr[] = { 1,2,3,5,32,7,4,6,1,34,24,8,23,745,2,4,3,2,35,624,1,2364,312,3,4 };

	printf("%d\n", findFirstGreater(arr, _countof(arr), 3));
	printf("%d\n", findFirstGreater(arr, _countof(arr), 311));
	printf("%d\n", findFirstGreater(arr, _countof(arr), 56));
	printf("%d\n", findFirstGreater(arr, _countof(arr), 124315));

	

	return 0;

}

int findFirstGreater(int* arr, int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > value)
			return i;
	}
	return -1;
}