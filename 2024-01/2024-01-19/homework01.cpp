#include <stdio.h>
#include <stdlib.h>

void copyArray(int* dest, int dSize, int* source, int sSize);
void PrintArray(int* parr, int size);

int main()
{
	int source[5] = { 1, 2, 3, 4 ,5 };
	int dest[100] = { 0 };
	copyArray(dest, _countof(dest), source, _countof(source));
	PrintArray(dest, _countof(dest));

	int source2[105] = { 3, 3, 1, 0 , 8, 2, 3, 8, 6, 123, 645 };
	copyArray(dest, _countof(dest), source2, _countof(source2));
	PrintArray(dest, _countof(dest));

	return 0;
}

void copyArray(int* dest, int dSize, int* source, int sSize)
{
	for (int i = 0; i < sSize; i++)
	{
		dest[i] = source[i];
		if (i == dSize - 1)
			return;
	}

}
void PrintArray(int* parr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", *(parr + i));
	}
	printf("\n\n");
}