#include <stdio.h>
#include <stdlib.h>

int main()
{
	char source1[1000];
	char source2[1000];
	char dest[1000];

	//source1 �Է�
	printf("���ڿ�1�� �Է����ּ���. (1000 Byte) : ");
	scanf_s("%s", source1, unsigned _countof(source1));

	//strlen ����
	int count1 = 0;
	while (source1[count1] != '\0')
	{
		count1++;
	}
	printf("\n[strlen]\n��� : %d\n", count1);

	//strcpy ����
	for (int i = 0; i < count1; i++)
	{
		dest[i] = source1[i];
	}
	dest[count1] = '\0';
	printf("\n[strcpy]\n��� : %s\n", dest);


	//strcat, strcmp�� ���� source2�Է�
	printf("\n1. ����� \"%s\"�� ���ڿ�2�� �̾���Դϴ�.\n2. \"%s\"�� ���ڿ�2�� ���մϴ�.\n���ڿ�2�� �Է����ּ���. (1000 Byte) : ", dest, source1);
	scanf_s("%s", source2, unsigned _countof(source2));
	int count2 = 0;
	while (source2[count2] != '\0')
	{
		count2++;
	}

	//strcat ����
	for (int i = 0; i < count2; i++)
	{
		dest[count1 + i] = source2[i];
	}
	dest[count1 + count2] = '\0';
	printf("\n[strcat]\n��� : %s\n", dest);

	//strcmp ����
	int compare = 0;
	for (int i = 0; i < ((count1 >= count2) ? count1 : count2); i++)
	{
		if (source1[i] != source2[i])
		{
			compare = 1;
			break;
		}
	}
	printf("\n[strcmp]\n��� : %d\n", compare);




	return 0;
}