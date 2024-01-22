#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[20] = "";

	fgets(str, 20, stdin); //gets를 대체한 함수.
	//stdin(표준입력)에서 문자열을 20byte 만큼 입력받는다. (마지막은 널문자)
	puts(str); //문자열을 출력한다.
	fputs(str, stdout); //문자열을 stdout(표준출력)으로 출력한다.

}