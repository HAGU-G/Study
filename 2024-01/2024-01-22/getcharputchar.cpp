#include <stdio.h>
#include <stdlib.h>

int main()
{
	char ch = '0';

	while (true)
	{
		ch = getchar(); //�Է¹����� �ѱ��ھ� �����´�.
		if (ch == '\n') //������ ���ڰ� �����̸� break
			break;
		putchar(ch); //�ѱ��ھ� ���
	}

	return 0;
}