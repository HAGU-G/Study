#include<stdio.h>

int main()
{
	printf("1.\n"); // 1
	double double1, double2;
	printf("두 실수\v 입력: ");
	scanf("%lf %lf", &double1, &double2);
	printf("%0.2f + %0.1f = %0.2f\n", double1, double2, double1 + double2);
	//printf에 double과 float이 전달되면 자동으로 double형으로 변환
	//printf는 %lf나 %f 상관 없다.

	printf("\n2.\n"); // 2
	double weight;
	double height;
	printf("체중(kg) 입력: ");
	scanf("%lf", &weight);
	printf("키(m) 입력: ");
	scanf("%lf", &height);
	printf("BMI : %f\n", (weight / (height * height)));

	printf("\n3.\n"); // 3
	char alphabet;
	scanf(" %c", &alphabet); //scanf는 return값도 입력받는다.
	printf("%c", alphabet + 1);

	return 0;

}