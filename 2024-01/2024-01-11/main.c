//전역변수와 지역변수의 차이를 발견

#include<stdio.h>

int inta; //전역변수

int main()
{
	//자신의 이름을 출력
	printf("%d 조병민\n", inta); //초기화를 하지않아도 오류가 발생하지 않음.
	int intb; //지역변수
	//printf("%d 조병민\n", b); //초기화를 하지않아서 오류발생.
	
	
	
	intb = 10;
	double d;
	double dd;

	//형변환
	d = intb / 3;
	dd = (double)intb / 3;

	int int1 = 1;
	printf("%f\n%f\n", d, dd);




	printf("-------------------\n");
	printf("------- char 자료형\n");
	printf("%c %d\n", '2', '2');
	printf("%c + %c = %c\n",'1','1','1'+'1');

	char en = 'A';
	char ko = '가';
	char ko2[3] = "가";
	printf("%c, %c,, %c%c, %s\n", en, ko, ko2[0], ko2[1], ko2);




	printf("-------------------\n");
	printf("------- 전치/후치 증가 연산\n");
	int plusplus = 1;
	printf("%d\n", plusplus += 1);
	printf("%d\n", plusplus++);
	printf("%d\n\n", ++plusplus);

	int pa = 5;
	int pb;

	pb = ++pa;
	printf("전치 증가 연산\n%d\n", pa);
	printf("%d\n", pb);
	pb = pa++;
	printf("후치 증가 연산\n%d\n", pa);
	printf("%d\n\n", pb);

	int a = 5;
	int b;
	printf("이건 뭘까?A %d\n", ++a + a++ + --a);

	a = 5;
	b = ++a + a++ + --a;
	printf("이건 뭘까?A %d\n", b);

	a = 5;
	printf("이건 뭘까?B %d\n", (a += 1) + a++ + (a -= 1));

	a = 5;
	b = (a += 1) + a++ + (a -= 1);
	printf("이건 뭘까?B %d\n", b);
	//언어마다 규칙이 다르다.

	//c에서는 bool은 전처리기를 이용해야한다.
	//bool p = false;
	return 0;
}