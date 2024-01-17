//16:50 ~ 17:03
#include <stdio.h>

//1
int parity(int n)
{
	if (n % 2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//2
int useCnt[5] = { 0 };
void useItem(int itemNum);

//3
void rec(int n)
{
	if (n == 0) return;
	printf("%d", n);
	rec(n - 1);
	printf("%d", n);
}


int main()
{
	//1
	{
		printf("%d\n", parity(5));
		printf("%d\n", parity(-2));
		printf("%d\n", parity(6));
	}

	//2
	{

		useItem(4);
		useItem(2);
		useItem(1);
		useItem(4);
		useItem(0);

		for (int i = 0; i < 5; i++)
		{
			printf("슬롯%d의 아이템을 %d번 썼습니다.\n", i, useCnt[i]);
		}

		//출력 예상 - 정답
		//슬롯0의 아이템을 1번 썼습니다.
		//슬롯1의 아이템을 1번 썼습니다.
		//슬롯2의 아이템을 1번 썼습니다.
		//슬롯3의 아이템을 0번 썼습니다.
		//슬롯4의 아이템을 2번 썼습니다.
	}

	//3
	{
		rec(5);

		//출력 예상 - 오답
		//54321

		//실제 출력
		//5432112345
		//함수 안에서 다른 함수를 호출한다고 함수가 종료되는 것이 아니다.
		//가장 마지막에 호출된 함수부터 마지막줄까지 실행해야 하나씩 종료된다.
		//5 → rec(4); → 4 rec(3); → 3 rec(2); → 1 rec(0); → rec(0); 종료
		//→ 1 → rec(1); 종료...
	}

	return 0;
}

//2
void useItem(int itemNum)
{
	useCnt[itemNum]++;
}
