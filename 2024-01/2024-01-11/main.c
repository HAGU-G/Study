//���������� ���������� ���̸� �߰�

#include<stdio.h>

int inta; //��������

int main()
{
	//�ڽ��� �̸��� ���
	printf("%d ������\n", inta); //�ʱ�ȭ�� �����ʾƵ� ������ �߻����� ����.
	int intb; //��������
	//printf("%d ������\n", b); //�ʱ�ȭ�� �����ʾƼ� �����߻�.
	
	
	
	intb = 10;
	double d;
	double dd;

	//����ȯ
	d = intb / 3;
	dd = (double)intb / 3;

	int int1 = 1;
	printf("%f\n%f\n", d, dd);




	printf("-------------------\n");
	printf("------- char �ڷ���\n");
	printf("%c %d\n", '2', '2');
	printf("%c + %c = %c\n",'1','1','1'+'1');

	char en = 'A';
	char ko = '��';
	char ko2[3] = "��";
	printf("%c, %c,, %c%c, %s\n", en, ko, ko2[0], ko2[1], ko2);




	printf("-------------------\n");
	printf("------- ��ġ/��ġ ���� ����\n");
	int plusplus = 1;
	printf("%d\n", plusplus += 1);
	printf("%d\n", plusplus++);
	printf("%d\n\n", ++plusplus);

	int pa = 5;
	int pb;

	pb = ++pa;
	printf("��ġ ���� ����\n%d\n", pa);
	printf("%d\n", pb);
	pb = pa++;
	printf("��ġ ���� ����\n%d\n", pa);
	printf("%d\n\n", pb);

	int a = 5;
	int b;
	printf("�̰� ����?A %d\n", ++a + a++ + --a);

	a = 5;
	b = ++a + a++ + --a;
	printf("�̰� ����?A %d\n", b);

	a = 5;
	printf("�̰� ����?B %d\n", (a += 1) + a++ + (a -= 1));

	a = 5;
	b = (a += 1) + a++ + (a -= 1);
	printf("�̰� ����?B %d\n", b);
	//���� ��Ģ�� �ٸ���.

	//c������ bool�� ��ó���⸦ �̿��ؾ��Ѵ�.
	//bool p = false;
	return 0;
}