#include <stdio.h>
//인덱스 연산자 사용 금지


int calculateRangeSum(int* arr, int start, int end);


int main()
{
	int arr[] = { 1, 20, 300, 4000, 50000, 600000 };

	printf("%d\n", calculateRangeSum(arr, 2, 3));
	printf("%d\n", calculateRangeSum(arr, 0, 5));
	printf("%d\n", calculateRangeSum(arr, 1, 4));


	return 0;
}

int calculateRangeSum(int* arr, int start, int end)
{
	int sum = 0;
	for (int* i = arr + start; i <= arr + end; i++)
	{
		sum += *i;
	}
	return sum;
}
