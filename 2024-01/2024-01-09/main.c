#include<stdio.h>

int main()
{

	/*printf("%d\n", sizeof(char));
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(short));
	printf("%d\n", sizeof(long));
	printf("%d\n", sizeof(long long));
	printf("%d\n", sizeof(float));
	printf("%d\n", sizeof(double));

	char char1 = 1;
	char char2 = 2;
	char resultchar = 0;

	short short1 = 300;
	short short2 = 500;
	short resultshort = 0;

	printf("%d", sizeof(char1+char2));*/

	/*int int1 = 6;
	int int2 = 5;

	printf("%d ", int1 + int2);
	printf("%d ", int1 - int2);
	printf("%d ", int1 * int2);
	printf("%d ", int1 / int2);
	printf("%d\n", int1 % int2);


	int playerHp = 10;
	int playerAtk = 3;
	int monsterHp = 100;
	int monsterAtk = 1;

	printf("플레이어가 몬스터를 공격\n");
	monsterHp = monsterHp - playerAtk;
	// monsterHp -= playerAtk;
	printf("몬스터가 데미지 %d을(를) 받았다. 몬스터의 남은 체력 %d\n", playerAtk, monsterHp);

	printf("플레이어가 체력을 회복\n");
	playerHp = playerHp + 10;
	printf("플레이어의 현재 체력 %d\n", playerHp);*/

	/*int num = 10;
	printf("num의 값 : %d\n", num);
	num++;
	printf("num++ 후 : %d\n", num);
	++num;
	printf("++num 후 : %d\n", num);
	num--;
	printf("num-- 후 : %d\n", num);
	--num;
	printf("--num 후 : %d\n", num);

	printf("---------------------------\n");

	int num1 = 10;
	int num2 = 20;
	int a;
	int b;

	a = ++num1;
	printf("a : %d, num1 : %d\n", a, num1);
	//11, 11

	b = num2++;
	printf("b : %d, num2 : %d\n", b, num2);
	//20, 21


	printf("%d\n", num1++);
	//11 이후 num1은 12*/

	/*int compare1, compare2;
	int result1, result2, result3, result4;

	compare1 = 1;
	compare2 = 2;

	result1 = compare1 < compare2;
	printf("%d\n", result1);

	result2 = (compare1 < compare2);
	printf("%d\n", result2);*/

	/*int inputNum;
	printf("정수를 입력하세요 :\n");
	scanf_s("%d", &inputNum);
	printf("입력한 정수 : %d\n", inputNum);*/

	/*
	int integer1;
	int integer2;
	int integer3;

	printf("정수를 3개 입력하시오.\n");
	scanf_s("%d %d %d", &integer1, &integer2, &integer3);
	printf("입력된 정수는 %d, %d, %d 입니다.\n\n",integer1, integer2, integer3);

	int scoreKorean;
	int scoreEnglish;
	int scoreMath;

	printf("국어 점수를 입력하시오.\n");
	scanf_s("%d", &scoreKorean);
	printf("영어 점수를 입력하시오.\n");
	scanf_s("%d", &scoreEnglish);
	printf("수학 점수를 입력하시오.\n");
	scanf_s("%d", &scoreMath);

	printf("국어 : %d \n영어 : %d \n수학 : %d \n총합 점수 : %d\n", scoreKorean, scoreEnglish, scoreMath, scoreKorean + scoreEnglish + scoreMath);
	printf("평균 : %d\n", (scoreKorean + scoreEnglish + scoreMath) / 3);
	*/


	int playerHp;
	int playerAtk;
	int playerDef;

	int monsterHp;
	int monsterAtk;
	int monsterDef;

	char atkKey;

	printf("플레이어의 체력, 공격력, 방어력을 입력하시오.\n");
	scanf_s("%d%d%d", &playerHp, &playerAtk, &playerDef);
	printf("고블린의 체력, 공격력, 방어력을 입력하시오.\n");
	scanf_s("%d%d%d", &monsterHp, &monsterAtk, &monsterDef);

	printf("\n[플레이어]\n체력 : %d\n공격력 : %d\n방어력 : %d\n", playerHp, playerAtk, playerDef);
	printf("[고블린]\n체력 : %d\n공격력 : %d\n방어력 : %d\n", monsterHp, monsterAtk, monsterDef);

	printf("\n고블린을 공격하려면 a를 입력하시오.\n");
	scanf_s(" %c", &atkKey, 1);
	printf("입력된 키 : %c\n", atkKey);

	if (atkKey == 'a')
	{
		printf("\n고블린은 플레이어에게 %d만큼의 공격을 받았다!\n", playerAtk);
		monsterHp -= playerAtk;
		printf("고블린의 남은 체력 %d\n", monsterHp);
	}
	else
	{
		printf("공격 실패!\n");
	}



	/*
	int num1 = 2;
	int num2 = 3;
	int num3 = 5;
	int result1, result2, result3;

	result1 = (num1 > 0) && (num2 < 10);
	result2 = (num1 <= 2) || (num2 > 5);
	result3 = !num2;
	*/

}
