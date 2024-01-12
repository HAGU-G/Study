//양의 정수를 입력받아 (아닐경우 재입력)
//1부터 입력받은 양의 정수까지 합을 출력하는 프로그램
// ex) 5 => 1 + 2 + 3 + 4 + 5

#include<stdio.h>

int main()
{
	int num = 0;
	int sum = 0;
	
	
	printf("양의 정수 입력 : ");
	scanf("%d", &num);

	while (num <= 0) //재입력
	{
		printf("양의 정수가 아닙니다. 재입력 : ");
		scanf("%d", &num);
	}
	
	//printf("1");
	//for (int i = 0; i < num; ++i)
	//{
	//	sum += i+1;
	//	if (i+1 < num)
	//	{
	//		printf(" + %d", i + 2);
	//	}
	//	else
	//	{
	//		printf(" = %d", sum);
	//	}
	//}

	//for (int i = 0; i < num; ++i)
	//	{
	//	sum += i+1;
	//	if (i+1 != num)
	//	{
	//		printf("%d + ", i + 1);
	//	}
	//	else
	//	{
	//		printf("%d", i + 1);
	//	}
	//}
	//printf(" = %d", sum);

	
	for (int i = 0; i < num; ++i)
	{
		sum += i + 1;
	}

	printf("1 + ... + %d = %d\n\n", num, sum);
	printf("1");
	for (int i = 0; num >=2 && i < num-1; ++i)
	{
		printf(" + %d", i + 2);
	}
	printf(" = %d", sum);
	
	

	return 0;
}