#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch = '0';

	while (true)
	{
		ch = getchar(); //입력버퍼의 한글자씩 가져온다.
		if (ch == '\n') //가져온 글자가 개행이면 break
			break;
		putchar(ch); //한글자씩 출력
	}

	return 0;
}