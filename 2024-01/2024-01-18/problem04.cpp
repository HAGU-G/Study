#include <stdio.h>
#include <stdlib.h>
//인덱스 연산자 사용 금지

int calculateDistance(int* arr, int size, int element1, int element2);

int main()
{
	int arr[] = { 9, 100, 1, 0, 4, 4, 0, 6, 0, 1, 200 };
	printf("%d\n", calculateDistance(arr, _countof(arr), 100, 6));
	int arr2[] = { 1, 2, 3, 4, 5, -6, 7, 8, 9 };
	printf("%d\n", calculateDistance(arr2, _countof(arr2), 6, 2));
	int arr3[] = { 0, 0, 0, 0, 1, 1, 1, 1, 2, 0, 2, 1 };
	printf("%d\n", calculateDistance(arr3, _countof(arr3), 0, 1));

	return 0;
}

int calculateDistance(int* arr, int size, int element1, int element2)
{
	int* loc1 = nullptr, * loc2 = nullptr;

	for (int* i = arr; i < arr + size; i++)
	{
		if (*i == element1 && loc1 == nullptr)
			loc1 = i;
		if (*i == element2 && loc2 == nullptr)
			loc2 = i;
	}

	if (loc1 == nullptr || loc2 == nullptr)
		return -1;
	if (loc1 - loc2 < 0)
		return loc2 - loc1;
	return loc1 - loc2;
}
