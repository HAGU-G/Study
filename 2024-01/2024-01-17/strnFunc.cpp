//20:55 ~ 21:23
#include <stdio.h>
#include <stdlib.h>

const int inputSize = 1001;

int MyStrlen(char(*str)[inputSize]);
char* MyStrncpy(char(*dest)[inputSize], char(*source)[inputSize], int length);
char* MyStrncat(char(*dest)[inputSize], char(*source)[inputSize], int length);
int MyStrncmp(char(*source1)[inputSize], char(*source2)[inputSize], int length);

int main()
{
	char source1[inputSize] = { '\0' };
	char source2[inputSize] = { '\0' };
	char dest[inputSize] = { '\0' };
	int testLength = 0;

	//source1 �Է�
	printf("���ڿ�1�� �Է����ּ���. (1000 Byte) : ");
	while (!scanf_s("%s", source1, unsigned _countof(source1)))
	{
		printf("***ũ�� �ʰ�!***\n");
		printf("���ڿ�1�� �Է����ּ���. (1000 Byte) : ");
		rewind(stdin);
	}
	printf("������ ���� ���� �Է����ּ���. : ");
	scanf_s("%d", &testLength);

	printf("\n[strncpy]\n%p : dest address\n%p : return\n", dest, MyStrncpy(&dest, &source1, testLength));
	printf("dest : %s\n", dest);

	//source2 �Է�
	printf("\n--------\ndest�� �̾���� ���ڿ�2�� �Է����ּ���. (1000 Byte) : ");
	while (!scanf_s("%s", source2, unsigned _countof(source2)))
	{
		printf("***ũ�� �ʰ�!***\n");
		printf("dest�� �̾���� ���ڿ�2�� �Է����ּ���. (1000 Byte) : ");
		rewind(stdin);
	}
	printf("������ ���� ���� �Է����ּ���. : ");
	scanf_s("%d", &testLength);

	printf("\n[strncat]\n%p : dest address\n%p : return\n", dest, MyStrncat(&dest, &source2, testLength));
	printf("dest : %s\n", dest);

	printf("\n���ڿ�1�� ���ڿ�2�� ���մϴ�.\n���� ���� ���� �Է����ּ���. : ");
	scanf_s("%d", &testLength);

	printf("\n[strncmp]\nsource1 : \"%s\"\nsource2 : \"%s\"\nreturn : %d\n", source1, source2, MyStrncmp(&source1, &source2, testLength));

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
			printf("%p : �ι��ڰ� �����ϴ�.\n", str);
			return 0;
		}
		else
		{
			len++;
		}
	}
	return len;
}

char* MyStrncpy(char(*dest)[inputSize], char(*source)[inputSize], int length)
{
	for (int i = 0; i < length; i++)
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
		else if (i == sizeof(*dest) - 2)
		{
			(*dest)[sizeof(*dest) - 1] = '\0';
			return *dest;
		}
		(*dest)[i] = (*source)[i];
	}
	(*dest)[length] = '\0';
	return *dest;
}

char* MyStrncat(char(*dest)[inputSize], char(*source)[inputSize], int length)
{
	int destLen = MyStrlen(dest);
	int nullLoc = destLen + MyStrlen(source) + 1;

	for (int i = 0; i < length; i++)
	{
		if (destLen + i == sizeof(*dest) - 1)
		{
			(*dest)[destLen + i] = '\0';
			return (*dest);
		}
		(*dest)[destLen + i] = (*source)[i];
	}
	(*dest)[destLen + length + 1] = '\0';
	return *dest;
}

int MyStrncmp(char(*source1)[inputSize], char(*source2)[inputSize], int length)
{
	int compare = 0;

	for (int i = 0; i < length; i++)
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
		else if (i == sizeof(*source1) - 1)
		{
			break;
		}
	}
	return compare;
}