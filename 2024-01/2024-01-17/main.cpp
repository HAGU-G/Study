#include <stdio.h>

//여기는 전역 영역

int itemCnt = 0; //전역변수
int money = 100; //단점이 있기 때문에 쓰지 않는 것이 좋다.

void BuyItem(int cost, int buyCnt)
{
	//여기는 지역1 영역
	itemCnt += buyCnt;
	money -= cost * buyCnt;
	printf("아이템(%d골드)을 %d개 구매했습니다.\n", cost, buyCnt);
	printf("\t아이템 개수 : %d\n", buyCnt);
	printf("\t잔액 : %d\n", money);

}


int main()
{
	//여기는 지역2 영역
	
	//아이템 구매
	/*++itemCnt;
	money -= 10;
	printf("아이템을 구매했습니다.\n");
	printf("\t아이템 개수 : %d\n", itemCnt);
	printf("\t잔액 : %d\n", money);
	++itemCnt;
	money -= 10;
	printf("아이템을 구매했습니다.\n");
	printf("\t아이템 개수 : %d\n", itemCnt);
	printf("\t잔액 : %d\n", money);
	++itemCnt;
	money -= 20;
	printf("아이템을 구매했습니다.\n");
	printf("\t아이템 개수 : %d\n", itemCnt);
	printf("\t잔액 : %d\n", money);
	++itemCnt;
	money -= 10;
	printf("아이템을 구매했습니다.\n");
	printf("\t아이템 개수 : %d\n", itemCnt);
	printf("\t잔액 : %d\n", money);
	++itemCnt;
	money -= 30;
	printf("아이템을 구매했습니다.\n");
	printf("\t아이템 개수 : %d\n", itemCnt);
	printf("\t잔액 : %d\n", money);*/

	BuyItem(10, 3);
	BuyItem(1, 2);

	return 0;
}