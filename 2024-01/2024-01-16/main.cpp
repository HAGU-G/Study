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



	/*int a;
	double b[20];

	printf("%p\n", &a);
	printf("%p\n", &b);

	int c = (int)&b - (int)&a;
	printf("%d\n", c);
	*/
	// 다른 자료형끼리 연속으로 선언하면 주소는 (자료형 크기 + 20바이트) 차이가 난다??
	// 같은 자료형끼리 연속으로 선언하면 주소는 32바이트 차이가 난다.
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
	//4바이트 이하 - 앞:8 뒤:20
	//8바이트 - 앞:4 뒤:20
	//4바이트 배열 - 앞:12 뒤:12
	//8바이트 배열 - 앞:12 뒤:20



	//int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }; //int형의 주민이 살 수 있는 아파트의 i호들을 지었다.
	//printf("%d\n", arr[2]); //주민.
	//printf("%p\n", &arr[2]); //주민이 살고 있는 호 ex) 101호
	//printf("%p\n", arr); //각 호들을 포함하는 아파트 ex) 코딩아파트
	//printf("%p\n", &arr); //아파트의 주소 ex) 플밍동 어렵로 24-441
	// 


	return 0;
}