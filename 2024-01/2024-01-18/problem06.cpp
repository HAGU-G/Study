#include <stdio.h>
#include <stdlib.h>
//�ε��� ������ ��� ����

int contains(int* arr, int size, int element);

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	printf("%d\n", contains(arr, _countof(arr), 4));
	printf("%d\n", contains(arr, _countof(arr), 100));

	return 0;
}

int contains(int* arr, int size, int element)
{
	for (int* i = arr; i < arr + size; i++)
	{
		if (*i == element)
			return 1;
	}
	return 0;
}
