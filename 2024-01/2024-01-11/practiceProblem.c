#include<stdio.h>

int main()
{
	printf("1.\n"); // 1
	double double1, double2;
	printf("두 실수 입력: ");
	scanf("%lf %lf", &double1, &double2);
	printf("%0.2lf + %0.1lf = %0.2lf\n", double1, double2, double1 + double2);

	printf("\n2.\n"); // 2
	double weight;
	double height;
	printf("체중(kg) 입력: ");
	scanf("%lf", &weight);
	printf("키(m) 입력: ");
	scanf("%lf", &height);
	printf("BMI : %lf\n", (weight / (height * height)));

	printf("\n3.\n"); // 3
	char alphabet;
	scanf(" %c", &alphabet);
	printf("%c", alphabet + 1);



}