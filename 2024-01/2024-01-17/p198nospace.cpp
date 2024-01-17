#include <stdio.h>

void test(const char* txt)
{
	printf("%s\n", txt);
}

int main()
{
	const char* dd = "x";
	printf("%s\n", dd);
	char aa[] = "dddddddddddfd";
	test("ddfs");
	dd = aa;
	printf("%s", dd);

	char b = '1';
	aa = b;

	const int ddf = 2;
	ddf = 3;

	return 0;
}