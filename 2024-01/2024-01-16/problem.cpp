#include <stdio.h>
#include <stdlib.h>

int main()
{

//1번
	{
		int arrlen = 0;
		int arr[100] = { 0 };

		printf("숫자의 개수 입력: ");
		scanf_s("%d", &arrlen);
		printf("숫자 입력: ");
		for (int i = 0; i < arrlen; i++)
		{
			scanf_s("%d", &arr[i]);
		}

		for (int i = 0; i < arrlen; i++)
		{
			if (i % 2 == 1)
			{
				printf("%d ", arr[i]);
			}
		}

		printf("\n");
		for (int i = 0; i < arrlen; i++)
		{
			if (i % 2 == 0)
			{
				printf("%d ", arr[i]);
			}
		}
		printf("\n", arr[0]);
	}

//2번
	{
		//*ptr = 30; a에 30을 저장
		//*ptr = 10; b에 10을 저장
		// 30 10 10이 출력된다.

		int a = 10;
		int b = 20;

		int* ptr;

		ptr = &a;
		*ptr = 30;

		ptr = &b;
		*ptr = 10;

		printf("%d\n", a);
		printf("%d\n", b);
		printf("%d\n", *ptr);
	}

//3번
	{
		// 출력예상 *틀림 : 포인터연산자와 어드레스연산자를 헷갈려서 반대로 생각함
		// 112 1
		// 116 5
		// 120 9
		// 124 2
		// arr + i 는 arr[i]의 주소값
		// *(arr +i)는 arr[i]의 값 

		int arr[10] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };

		printf("%d\n", arr); //100이 출력된다고 가정
		for (int i = 3; i < 7; i++)
		{
			printf("%d %d\n", arr + i, *(arr + i));
		}

	}

//4번
	{
		int arr[10][10] = { 0 };
		int row = 0;
		int col = 0;

		//행렬 입력
		scanf_s("%d %d", &row, &col);

		//요소 입력
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				scanf_s("%d", &arr[i][j]);
			}
		}

		//합산
		for (int i = 0; i < row; i++)
		{
			int sum = 0;
			for (int j = 0; j < col; j++)
			{
				sum += arr[i][j];
			}
			printf("%d\n", sum);
		}

	}

//5번
	{
		//arr의 시작 주소는 100이라고 가정
		int arr[3][3] = { 0 };
		printf("%d\n", &arr);	//100	: arr의 배열포인터
		printf("%d\n", arr);	//100	: arr[i]의 시작주소
		printf("%d\n", *arr);	//100	: arr[0] *틀림

		printf("%d\n", &arr[0]);	//100	: arr[0]의 주소 = arr
		printf("%d\n", arr[0]);		//100	: arr[0][i]의 시작 주소
		printf("%d\n", *arr[0]);	//0		: arr[0][0]
		
		printf("%d\n", &arr[0][0]);	//100	: arr[0][0]의 주소
		printf("%d\n", arr[0][0]);	//0		: arr[0][0]의 값


	}

//6번
	{
		//시작 주소는 100
		int arr[3][3] = { 0 };

		printf("%d\n", &arr[0][0]);		// 100	: arr[0]
		printf("%d\n", arr[0] + 1);		// 104	: arr[0][1]
		printf("%d\n", &arr[0] + 1);	// 112	: arr[1]
		printf("%d\n", arr + 1);		// 112	: arr[1]
		printf("%d\n", &arr + 1);		// 136	: arr		배열 포인터는 int형의 3x3배열이기 때문에 36씩 늘어난다.


	}

//7번
	{
		int arr[3][4] = {
			{ 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 9, 10, 11, 12}
		};

		int(*ptr)[4] = arr; //*틀림 1차원 배열 포인터와 헷갈림

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {

				//printf("%d ", *ptr[i][j]);	//ptr[i][j]는 이미 arr[i][j]와 같은 값이다.
				printf("%d ", ptr[i][j]);		//int형은 포인터연산자의 피연산자가 될 수 없다.

			}
			printf("\n");
		}

		int a = 10;

	}

	return 0;
}