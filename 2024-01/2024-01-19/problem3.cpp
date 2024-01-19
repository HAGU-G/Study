#include <stdio.h>
//Point 타입의 구조체를 생성하고
//멤버 함수 swapXY를 만든다.
//Point는 int 타입의 x, y를 멤버 변수로 가지고 있고
//swapXY는 x와 y의 값을 바꿔주는 기능을 한다.

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