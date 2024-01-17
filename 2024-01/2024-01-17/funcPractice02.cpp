#include <stdio.h>

void Swap(int a, int b) //함수의 이름은 동사형태로 지정, 변수는 명사형태
{
	int temp = a;
	a = b;
	b = temp;

}


int main()
{
	int x = 10;
	int y = 20;

	Swap(x, y);

	printf("%d %d", x, y);

	return 0;
}