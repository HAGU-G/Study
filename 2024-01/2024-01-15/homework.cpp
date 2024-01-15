#include <stdio.h>
#include <stdlib.h>

int main()
{
	char source1[1000];
	char source2[1000];
	char dest[1000];

	//source1 입력
	printf("문자열1을 입력해주세요. (1000 Byte) : ");
	scanf_s("%s", source1, unsigned _countof(source1));

	//strlen 구현
	int count1 = 0;
	while (source1[count1] != '\0')
	{
		count1++;
	}
	printf("\n[strlen]\n결과 : %d\n", count1);

	//strcpy 구현
	for (int i = 0; i < count1; i++)
	{
		dest[i] = source1[i];
	}
	dest[count1] = '\0';
	printf("\n[strcpy]\n결과 : %s\n", dest);


	//strcat, strcmp를 위한 source2입력
	printf("\n1. 복사된 \"%s\"에 문자열2를 이어붙입니다.\n2. \"%s\"와 문자열2를 비교합니다.\n문자열2를 입력해주세요. (1000 Byte) : ", dest, source1);
	scanf_s("%s", source2, unsigned _countof(source2));
	int count2 = 0;
	while (source2[count2] != '\0')
	{
		count2++;
	}

	//strcat 구현
	for (int i = 0; i < count2; i++)
	{
		dest[count1 + i] = source2[i];
	}
	dest[count1 + count2] = '\0';
	printf("\n[strcat]\n결과 : %s\n", dest);

	//strcmp 구현
	int compare = 0;
	for (int i = 0; i < ((count1 >= count2) ? count1 : count2); i++)
	{
		if (source1[i] != source2[i])
		{
			compare = 1;
			break;
		}
	}
	printf("\n[strcmp]\n결과 : %d\n", compare);




	return 0;
}