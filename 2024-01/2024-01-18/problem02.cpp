#include <stdio.h>
//인덱스 연산자 사용 금지

void findMaxMin(int* arr, int size, int** max, int** min);

int main()
{
	int arr[10] = { -511, 4, 83, 4, 2, 10, 1, 8, 9 ,10 };
	int* min, * max = nullptr;
	findMaxMin(arr, sizeof(arr)/sizeof(arr[0]), &max, &min);
	printf("min: %d, max: %d\n", *max, *min);


	return 0;
}

void findMaxMin(int* arr, int size, int** max, int** min)
{
	int maxnum = *arr, minnum = *arr; //삭제
	*max = arr;
	*min = arr;
	for (int* i = arr; i < arr + size; i++)
	{
		if (*i > maxnum) //*i > **max
		{
			maxnum = *i; //삭제
			*max = i;
		}
		if (*i < minnum) //*i < **min
		{
			minnum = *i; //삭제
			*min = i;
		}
	}
}
