#include<stdio.h>

int main()
{
	int i = 1;
	while (i <= 10) //조건식에 true를 넣으면 계속 반복된다.
	{
		printf("%d ", i);
		++i;
	}

	printf("\n");

	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", i);
	}


	return 0;
	
}