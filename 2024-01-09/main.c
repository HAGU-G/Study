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

	printf("�÷��̾ ���͸� ����\n");
	monsterHp = monsterHp - playerAtk;
	// monsterHp -= playerAtk;
	printf("���Ͱ� ������ %d��(��) �޾Ҵ�. ������ ���� ü�� %d\n", playerAtk, monsterHp);

	printf("�÷��̾ ü���� ȸ��\n");
	playerHp = playerHp + 10;
	printf("�÷��̾��� ���� ü�� %d\n", playerHp);*/

	/*int num = 10;
	printf("num�� �� : %d\n", num);
	num++;
	printf("num++ �� : %d\n", num);
	++num;
	printf("++num �� : %d\n", num);
	num--;
	printf("num-- �� : %d\n", num);
	--num;
	printf("--num �� : %d\n", num);

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
	//11 ���� num1�� 12*/

	/*int compare1, compare2;
	int result1, result2, result3, result4;

	compare1 = 1;
	compare2 = 2;

	result1 = compare1 < compare2;
	printf("%d\n", result1);

	result2 = (compare1 < compare2);
	printf("%d\n", result2);*/

	/*int inputNum;
	printf("������ �Է��ϼ��� :\n");
	scanf_s("%d", &inputNum);
	printf("�Է��� ���� : %d\n", inputNum);*/

	/*
	int integer1;
	int integer2;
	int integer3;

	printf("������ 3�� �Է��Ͻÿ�.\n");
	scanf_s("%d %d %d", &integer1, &integer2, &integer3);
	printf("�Էµ� ������ %d, %d, %d �Դϴ�.\n\n",integer1, integer2, integer3);

	int scoreKorean;
	int scoreEnglish;
	int scoreMath;

	printf("���� ������ �Է��Ͻÿ�.\n");
	scanf_s("%d", &scoreKorean);
	printf("���� ������ �Է��Ͻÿ�.\n");
	scanf_s("%d", &scoreEnglish);
	printf("���� ������ �Է��Ͻÿ�.\n");
	scanf_s("%d", &scoreMath);

	printf("���� : %d \n���� : %d \n���� : %d \n���� ���� : %d\n", scoreKorean, scoreEnglish, scoreMath, scoreKorean + scoreEnglish + scoreMath);
	printf("��� : %d\n", (scoreKorean + scoreEnglish + scoreMath) / 3);
	*/


	int playerHp;
	int playerAtk;
	int playerDef;

	int monsterHp;
	int monsterAtk;
	int monsterDef;

	char atkKey;

	printf("�÷��̾��� ü��, ���ݷ�, ������ �Է��Ͻÿ�.\n");
	scanf_s("%d%d%d", &playerHp, &playerAtk, &playerDef);
	printf("����� ü��, ���ݷ�, ������ �Է��Ͻÿ�.\n");
	scanf_s("%d%d%d", &monsterHp, &monsterAtk, &monsterDef);

	printf("\n[�÷��̾�]\nü�� : %d\n���ݷ� : %d\n���� : %d\n", playerHp, playerAtk, playerDef);
	printf("[���]\nü�� : %d\n���ݷ� : %d\n���� : %d\n", monsterHp, monsterAtk, monsterDef);

	printf("\n����� �����Ϸ��� a�� �Է��Ͻÿ�.\n");
	scanf_s(" %c", &atkKey, 1);
	printf("�Էµ� Ű : %c\n", atkKey);

	if (atkKey == 'a')
	{
		printf("\n����� �÷��̾�� %d��ŭ�� ������ �޾Ҵ�!\n", playerAtk);
		monsterHp -= playerAtk;
		printf("����� ���� ü�� %d\n", monsterHp);
	}
	else
	{
		printf("���� ����!\n");
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
