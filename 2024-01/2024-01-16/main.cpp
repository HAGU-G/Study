#include <stdio.h>
#include <stdlib.h>

int main()
{

		int arr[10];
		int(*p_arr)[10] = &arr;
		int a[3] = {1, 2, 30};
		int b[3];
		int* ptr = a;
		int* ptrb = b;

		printf("%d\n", sizeof(p_arr+1));
		printf("%d\n", p_arr);
		printf("%d\n", p_arr + 1);


		int arr2[7][10];
		p_arr = arr2; //�������� �۵��Ѵ�.

		//�迭 ������ p_arr



	/*int a;
	double b[20];

	printf("%p\n", &a);
	printf("%p\n", &b);

	int c = (int)&b - (int)&a;
	printf("%d\n", c);
	*/
	// �ٸ� �ڷ������� �������� �����ϸ� �ּҴ� (�ڷ��� ũ�� + 20����Ʈ) ���̰� ����??
	// ���� �ڷ������� �������� �����ϸ� �ּҴ� 32����Ʈ ���̰� ����.
	// 
	//int, int 28
	//int, double 32
	//int, int[] 40
	//int, double[] 40
	//double, int 20
	//double, double 24
	//double, int[] 32
	//double, double[] 32
	//int[n], int 20
	//double[n], int 20
	//double[n], double 24
	//int[n], double 24
	//int[], int[] 24
	//double[] double[] 32
	//
	//4����Ʈ ���� - ��:8 ��:20
	//8����Ʈ - ��:4 ��:20
	//4����Ʈ �迭 - ��:12 ��:12
	//8����Ʈ �迭 - ��:12 ��:20



	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }; //int���� �ֹ��� �� �� �ִ� ����Ʈ�� iȣ���� ������.
	//printf("%d\n", arr[2]); //�ֹ�.
	//printf("%p\n", &arr[2]); //�ֹ��� ��� �ִ� ȣ ex) 101ȣ
	//printf("%p\n", arr); //�� ȣ���� �����ϴ� ����Ʈ ex) �ڵ�����Ʈ
	//printf("%p\n", &arr); //����Ʈ�� �ּ� ex) �ùֵ� ��Ʒ� 24-441
	// 


	return 0;
}