//20:05 ~ 20:50
#include <stdio.h>
#include <stdlib.h>

const int inputSize = 1001;

int MyStrlen(char(*str)[inputSize]);
char* MyStrcpy(char(*dest)[inputSize], char(*source)[inputSize]);
char* MyStrcat(char(*dest)[inputSize], char(*source)[inputSize]);
int MyStrcmp(char(*source1)[inputSize], char(*source2)[inputSize]);

int main()
{
	char source1[inputSize] = { '\0' };
	char source2[inputSize] = { '\0' };
	char dest[inputSize] = { '\0' };

	//source1 입력
	printf("문자열1을 입력해주세요. (1000 Byte) : ");
	while (!scanf_s("%s", source1, unsigned _countof(source1)))
	{
		printf("***크기 초과!***\n");
		printf("문자열1을 입력해주세요. (1000 Byte) : ");
		rewind(stdin);
	}


	printf("\n[strlen]\nreturn : %d\n", MyStrlen(&source1));

	printf("\n[strcpy]\n%p : dest address\n%p : return\n", dest, MyStrcpy(&dest, &source1));
	printf("dest : %s\n", dest);

	//source2 입력
	printf("\n--------\ndest에 이어붙일 문자열2를 입력해주세요. (1000 Byte) : ");
	while (!scanf_s("%s", source2, unsigned _countof(source2)))
	{
		printf("***크기 초과!***\n");
		printf("dest에 이어붙일 문자열2를 입력해주세요. (1000 Byte) : ");
		rewind(stdin);
	}

	printf("\n[strcat]\n%p : dest address\n%p : return\n", dest, MyStrcat(&dest, &source2));
	printf("dest : %s\n", dest);

	printf("\n문자열1과 문자열2를 비교합니다.");
	printf("\n[strcmp]\nsource1 : \"%s\"\nsource2 : \"%s\"\nreturn : %d\n", source1, source2, MyStrcmp(&source1, &source2));

	return 0;
}

int MyStrlen(char(*str)[inputSize])
{
	int len = 0;
	for (int i = 0; i < sizeof(*str); i++)
	{
		if ((*str)[i] == '\0')
		{
			break;
		}
		else if (i == sizeof(*str) - 1)
		{
			printf("%p : 널문자가 없습니다.\n", str);
			return 0;
		}
		else
		{
			len++;
		}
	}
	return len;
}

char* MyStrcpy(char(*dest)[inputSize], char(*source)[inputSize])
{
	for (int i = 0; i < sizeof(*dest) - 1; i++)
	{
		if ((*source)[i] == '\0')
		{
			(*dest)[i] = '\0';
			return *dest;
		}
		else if (i == sizeof(*source) - 1)
		{
			(*dest)[i + 1] = '\0';
			return *dest;
		}
		(*dest)[i] = (*source)[i];
	}
	(*dest)[sizeof(*dest) - 1] = '\0';
	return *dest;
}

char* MyStrcat(char(*dest)[inputSize], char(*source)[inputSize])
{
	int destLen = MyStrlen(dest);
	int nullLoc = destLen + MyStrlen(source) + 1;

	for (int i = 0; i < nullLoc; i++)
	{
		if (destLen + i == sizeof(*dest) - 1)
		{
			(*dest)[destLen + i] = '\0';
			return (*dest);
		}
		(*dest)[destLen + i] = (*source)[i];
	}
	(*dest)[nullLoc] = '\0';
	return *dest;
}

int MyStrcmp(char(*source1)[inputSize], char(*source2)[inputSize])
{
	int compare = 0;

	for (int i = 0; i < ((sizeof(*source1) >= sizeof(*source2)) ? sizeof(*source1) : sizeof(*source2)); i++)
	{
		if ((*source1)[i] != (*source2)[i])
		{
			compare = (*source1)[i] - (*source2)[i];
			compare /= (compare < 0 ? -compare : compare);
			break;
		}
		else if ((*source1)[i] == '\0' && (*source2)[i] == '\0')
		{
			break;
		}
	}
	return compare;
}