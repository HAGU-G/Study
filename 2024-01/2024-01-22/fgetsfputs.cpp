#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[20] = "";

	fgets(str, 20, stdin); //gets�� ��ü�� �Լ�.
	//stdin(ǥ���Է�)���� ���ڿ��� 20byte ��ŭ �Է¹޴´�. (�������� �ι���)
	puts(str); //���ڿ��� ����Ѵ�.
	fputs(str, stdout); //���ڿ��� stdout(ǥ�����)���� ����Ѵ�.

}