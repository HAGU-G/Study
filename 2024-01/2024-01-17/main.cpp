#include <stdio.h>

//����� ���� ����

int itemCnt = 0; //��������
int money = 100; //������ �ֱ� ������ ���� �ʴ� ���� ����.

void BuyItem(int cost, int buyCnt)
{
	//����� ����1 ����
	itemCnt += buyCnt;
	money -= cost * buyCnt;
	printf("������(%d���)�� %d�� �����߽��ϴ�.\n", cost, buyCnt);
	printf("\t������ ���� : %d\n", buyCnt);
	printf("\t�ܾ� : %d\n", money);

}


int main()
{
	//����� ����2 ����
	
	//������ ����
	/*++itemCnt;
	money -= 10;
	printf("�������� �����߽��ϴ�.\n");
	printf("\t������ ���� : %d\n", itemCnt);
	printf("\t�ܾ� : %d\n", money);
	++itemCnt;
	money -= 10;
	printf("�������� �����߽��ϴ�.\n");
	printf("\t������ ���� : %d\n", itemCnt);
	printf("\t�ܾ� : %d\n", money);
	++itemCnt;
	money -= 20;
	printf("�������� �����߽��ϴ�.\n");
	printf("\t������ ���� : %d\n", itemCnt);
	printf("\t�ܾ� : %d\n", money);
	++itemCnt;
	money -= 10;
	printf("�������� �����߽��ϴ�.\n");
	printf("\t������ ���� : %d\n", itemCnt);
	printf("\t�ܾ� : %d\n", money);
	++itemCnt;
	money -= 30;
	printf("�������� �����߽��ϴ�.\n");
	printf("\t������ ���� : %d\n", itemCnt);
	printf("\t�ܾ� : %d\n", money);*/

	BuyItem(10, 3);
	BuyItem(1, 2);

	return 0;
}