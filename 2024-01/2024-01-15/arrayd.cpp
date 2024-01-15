#include <stdio.h>
#include <stdlib.h>
#include <string>

int main()
{
	char str[1024] = "hello";
	char str2[1024];

	strcpy_s(str2, str);



	return 0;
}