#include <stdio.h>

void PrintArray(int parr[], int size);
//int* parr == int parr[] �Ű������� �� �ΰ��� ���¸� parr�� int�� ���������̴�.
//parr[2] ó�� ����� �ƹ����Գ� �����൵ �Ȱ���. ������ �������� int* parr�� ���Ѵ�.
//�Լ����� �迭�� �Ű������� ���� ���� ����� ���� �޾ƿ��� ���� ����.

//2���� �迭�� �ѱ涧�� ��� ���� ����� ��� �޾ƿ��� ���� ����.
//��� �޾ƿ� �迭�� (int*)�� ����ȯ�� ������Ѵ�.

int main()
{
	int arr[4] = { 1,2,3,4 };
	PrintArray(arr,4);

	return 0;
}

void PrintArray(int parr[],int size)
{
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", parr[i]);
	}
	printf("\n");
}
