#include <stdio.h>

struct Time
{
	int h = 0, m = 0, s = 0;
	int MemberFunc() //��� �Լ�, ��� ������ ����� �� �ִ�.
	{
		return h * 3600 + m * 60 + s;
	}
};

int TotalSec(Time* t);

int main()
{
	Time t = { 1, 22, 48 };
	printf("%d\n", TotalSec(&t));
	printf("%d\n", t.MemberFunc());
	

	return 0;
}

int TotalSec(Time* t)
{
	return t->h * 3600 + t->m * 60 + t->s;
}