#include <stdio.h>
#include <stdlib.h>

double calculateRangeAverage(int* arr, int start, int end);

int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	printf("%f\n", calculateRangeAverage(arr, 2, 4));

	printf("%f\n", calculateRangeAverage(arr, 3, 6));
	return 0;
}

double calculateRangeAverage(int* arr, int start, int end)
{
	int count = end - start + 1;
	int sum = 0;
	for (int i = start; i <= end; i++)
	{
		sum += arr[i];
	}
	return (double)sum / count;
}