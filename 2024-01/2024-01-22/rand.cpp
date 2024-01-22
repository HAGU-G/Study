#include <stdio.h>
#include <stdlib.h> //rand, srand
#include <time.h> //time

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", rand());
	}

	return 0;
}