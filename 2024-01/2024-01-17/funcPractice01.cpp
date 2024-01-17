#include <stdio.h>

//숫자 두개를 받아서 합을 반환하는 함수

int Plus(int lhs, int rhs) //lhs 좌변 rhs 우변
{
	return lhs + rhs;
}

int main()
{
	printf("%d", Plus(3, 5));


	return 0;
}


//프로그램 흐름
//main()
//Plus(int, int)  >> printf 함수 안의 매개변수들 부터 해결을 해야한다.
//printf()
//return 0;