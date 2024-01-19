#include <stdio.h>
#include <stdlib.h>
//인덱스 연산자 사용 금지

int findMode(int* arr, int size);

int main()
{	
	int arr[] = { 2, 1, 1, 2, 2 };
	printf("%d\n", findMode(arr, _countof(arr)));
	int arr2[] = { 5, 3, 3, 7, 8, 1, -1, 2 };
	printf("%d\n", findMode(arr2, _countof(arr2)));
	int arr3[] = { -1, 0, 0, -152, 100, 12 };
	printf("%d\n", findMode(arr3, _countof(arr3)));
	
	return 0;
}

int findMode(int* arr, int size)
{
	int mod = 0;
	int modCount = 0;
	for (int* i = arr, num = 0; i < arr + size; i++)
	{
		if (i != arr && *i == num) //연속해서 만나는 같은 값은 뛰어넘었다.
			continue;

		//남은 인덱스가 최빈값의 최빈정도보다 적을 경우 함수를 종료한다.
		//위 조건을 추가하면 의미 없는 계산을 줄일 수 있다.

		num = *i;
		int count = 1;
		for (int* j = i + 1; j < arr + size; j++)
		{
			if (*j == num)
				count++;
		}
		if (count > modCount)
		{
			mod = num;
			modCount = count;
		}
	}
	return mod;
}
