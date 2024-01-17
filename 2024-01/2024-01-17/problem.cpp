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
			printf("����%d�� �������� %d�� ����ϴ�.\n", i, useCnt[i]);
		}

		//��� ���� - ����
		//����0�� �������� 1�� ����ϴ�.
		//����1�� �������� 1�� ����ϴ�.
		//����2�� �������� 1�� ����ϴ�.
		//����3�� �������� 0�� ����ϴ�.
		//����4�� �������� 2�� ����ϴ�.
	}

	//3
	{
		rec(5);

		//��� ���� - ����
		//54321

		//���� ���
		//5432112345
		//�Լ� �ȿ��� �ٸ� �Լ��� ȣ���Ѵٰ� �Լ��� ����Ǵ� ���� �ƴϴ�.
		//���� �������� ȣ��� �Լ����� �������ٱ��� �����ؾ� �ϳ��� ����ȴ�.
		//5 �� rec(4); �� 4 rec(3); �� 3 rec(2); �� 1 rec(0); �� rec(0); ����
		//�� 1 �� rec(1); ����...
	}

	return 0;
}

//2
void useItem(int itemNum)
{
	useCnt[itemNum]++;
}
