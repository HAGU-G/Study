//전역변수와 지역변수의 차이를 발견

#include<stdio.h>

int a; //전역변수

int main()
{
	//자신의 이름을 출력
	printf("%d 조병민\n", a); //초기화를 하지않아도 오류가 발생하지 않음.

	int b; //지역변수
	printf("%d 조병민\n", b); //초기화를 하지않아서 오류발생.
	return 0;
}