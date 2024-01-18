#include <stdio.h>
#include <stdlib.h>
//인덱스 연산자 사용 금지

int countElement(int* arr, int size, int element);

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 3, 7, 3 };
	int arrSize = _countof(arr);

	printf("%d\n", countElement(arr, arrSize, -4233));
	printf("%d\n", countElement(arr, arrSize, 3));
	printf("%d\n", countElement(arr, arrSize, 7));


	return 0;
}

int countElement(int* arr, int size, int element)
{
	int count = 0;
	for (int* i = arr; i < arr + size; i++)
	{
		if (*i == element)
			count++;
	}

	return count;
}
