#include <stdio.h>
//Point Ÿ���� ����ü�� �����ϰ�
//��� �Լ� swapXY�� �����.
//Point�� int Ÿ���� x, y�� ��� ������ ������ �ְ�
//swapXY�� x�� y�� ���� �ٲ��ִ� ����� �Ѵ�.

struct Point
{
	int x, y;

	void swapXY()
	{
		int temp = x;
		x = y;
		y = temp;
	}
};

int main()
{
	Point pos = { 3, 4 };
	pos.swapXY();
	printf("(%d, %d)\n", pos.x, pos.y);



	return 0;
}