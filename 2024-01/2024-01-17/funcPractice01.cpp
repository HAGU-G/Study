#include <stdio.h>

//���� �ΰ��� �޾Ƽ� ���� ��ȯ�ϴ� �Լ�

int Plus(int lhs, int rhs) //lhs �º� rhs �캯
{
	return lhs + rhs;
}

int main()
{
	printf("%d", Plus(3, 5));


	return 0;
}


//���α׷� �帧
//main()
//Plus(int, int)  >> printf �Լ� ���� �Ű������� ���� �ذ��� �ؾ��Ѵ�.
//printf()
//return 0;