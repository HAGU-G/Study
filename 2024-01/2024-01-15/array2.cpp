#include <stdio.h>
#include <stdlib.h>

int main()
{

	int n = 0;
	int arr[1000] = {0};
	int sum = 0;
	double avr = 0.0;
	int max = 0;
	int min = 0;

	printf("입력할 수의 개수 :");
	scanf_s("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf_s("%d", &arr[i]);
	}

	printf("입력한 숫자 : ");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
	}
	avr = (double)sum / n;
	printf("\n합계 : %d\n평균 : %f\n", sum, avr);

	max = arr[0];
	min = arr[0];
	for (int i = 1; i < n; i++)
	{

		if (arr[i] >= max)
		{
			max = arr[i];
		}
		if (arr[i] <= min)
		{
			min = arr[i];
		}
	}
	printf("최댓값 : %d\n", max);
	printf("최솟값 : %d\n\n\n", min);




	int mid[1000] = { 0 };
	for (int i = 0; i < n; i++)
	{
		mid[i] = arr[i];
	}

	//정렬
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (mid[j] > mid[i])
			{
				int temp = mid[i];
				mid[i] = mid[j];
				mid[j] = temp;
			}
		}
	}
	printf("정렬된 숫자 : ");
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", mid[i]);
	}
	
	int midn = 0;
	if (n % 2 == 0) { midn = n / 2 - 1; }
	else { midn = n / 2; }
	printf("중간값 : %d\n\n", mid[midn]);


	return 0;
}