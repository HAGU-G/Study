#include <stdio.h>
#define _countof(array) (sizeof(array) / sizeof(array[0]))

int main()
{
	int num = 0;
	int array[5] = { 1, 2, 3, 4, 5 };
	int arrLen = _countof(array);
	

	for (int i = 0; i < arrLen; i++)
	{
		printf("%d\n", array[i]);
	}


	char test[] = "abcd";
	char test2[4];
	for (int i = 0; i < 3; i++)
	{
		test2[i] = test[i + 1];
	}
	test2[3] = '\0';
	printf("%s", test2);


	

	return 0;
}