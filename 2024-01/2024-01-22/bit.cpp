#include <stdio.h>

int main()
{
	//비트연산자
	int a = 106, b = 83;

	printf("a & b = %d\n", a & b);
	printf("a | b = %d\n", a | b);
	printf("a ^ b = %d\n", a ^ b);
	printf("~a = %d\n", ~a);
	printf("a << 1 = %d\n", a<<1);
	printf("a >> 1 = %d\n", a>>1);

	return 0;

}