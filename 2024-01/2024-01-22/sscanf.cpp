#include <stdio.h>
#include <stdlib.h>

int main()
{
	char sa[] = "123";
	int a = 0;

	sscanf(sa, "%d", &a); //버퍼에서 정수의 형태로 a에 입력한다.
	printf("%d", a);


	sprintf(sa, "%d", 321); //버퍼에 정수의 형태로 321을 출력한다.
	printf("%s", sa);
}

//입력은 버퍼에서 가져오는 것.
//출력은 버퍼로 내보내는 것.