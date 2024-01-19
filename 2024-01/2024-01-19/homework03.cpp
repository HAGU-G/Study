#include <stdio.h>
#include <stdlib.h>

void PrintArray(int* parr, int size);

int main()
{

	return 0;
}

void PrintArray(int* parr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", *(parr + i));
	}
	printf("\n\n");
}