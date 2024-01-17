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
		p_arr = arr2; //문제없이 작동한다.

		//배열 포인터 p_arr



	return 0;
}