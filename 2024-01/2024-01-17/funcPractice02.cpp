#include <stdio.h>

void SwapValue(int a, int b) //함수의 이름은 동사형태로 지정, 변수는 명사형태
{
	int temp = a;
	a = b;
	b = temp;
}

void SwapAddress(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void SwapReference(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


int main()
{
	int x = 10;
	int y = 20;

	SwapValue(x, y);
	printf("Value %d %d\n", x, y);

	SwapAddress(&x, &y);
	printf("Address %d %d\n", x, y);

	SwapReference(x, y);
	printf("Reference %d %d\n", x, y);

	int a = 10;
	int& ref = a;
	//ref는 a와 똑같은 역할을 한다.
	//선언과 동시에 초기화를 해야한다.

	printf("%d %d\n", &a, &ref); //10 10
	ref++;
	printf("%d %d\n", a, ref); //11 11


	return 0;
}