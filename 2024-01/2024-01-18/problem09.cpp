#include <stdio.h>
#include <stdlib.h>

//인덱스 연산자 사용 금지

int removeElement(int* arr, int size, int element);
void PrintArray(int* parr, int size);


int main()
{
	int a[] = { 1, 2, 4, 3, 2, 2, 6 };
	int aResize = 0;

	aResize = removeElement(a, _countof(a), 2);

	PrintArray(a, aResize);
	printf("\n%d", aResize);

	return 0;
}

int removeElement(int* arr, int size, int element)
{
	//for (int* ptr = arr; ptr < arr + size; ++ptr)
	//{
	//	if (*ptr == element)
	//	{
	//		for (int* ptr2 = ptr + 1; ptr2 < arr + size; ++ptr2)
	//		{
	//			*(ptr2 - 1) = *ptr2;
	//		}
	//		--ptr;
	//		--size;
	//	}
	//}
	int resize = 0;
	for (int* i = arr, *j = arr; i < arr + size; i++)
	{
		if (*i != element)
		{
			*j = *i;
			j++;
			resize++;
		}
	}
	return resize;
}

void PrintArray(int* parr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", *(parr + i));
	}
}