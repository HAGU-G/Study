//17:05 ~ 18:17 ~ 20:04
#include <stdio.h>
#include <stdlib.h>

int MyStrlen(char* str, int size);
char* MyStrcpy(char* dest, int sizeDest, char* source, int sizeSource);
char* MyStrcat(char* dest, int destSize, char* source, int sourceSize);
int MyStrcmp(char* source1, int source1Size, char* source2, int source2Size);

int main()
{
	char source1[1001] = { '\0' };
	char source2[1001] = { '\0' };
	char dest[1001] = { '\0' };
	//source1 �Է�
	printf("���ڿ�1�� �Է����ּ���. (1000 Byte) : ");
	while (!scanf_s("%s", source1, unsigned _countof(source1)))
	{
		printf("***ũ�� �ʰ�!***\n");
		printf("���ڿ�1�� �Է����ּ���. (1000 Byte) : ");
		rewind(stdin);
	}


	printf("\n[strlen]\nreturn : %d\n", MyStrlen(source1, sizeof(source1)));

	printf("\n[strcpy]\n%p : dest address\n%p : return\n", dest, MyStrcpy(dest, sizeof(dest), source1, sizeof(source1)));
	printf("dest : %s\n", dest);

	//source2 �Է�
	printf("\n--------\ndest�� �̾���� ���ڿ�2�� �Է����ּ���. (1000 Byte) : ");
	while (!scanf_s("%s", source2, unsigned _countof(source2)))
	{
		printf("***ũ�� �ʰ�!***\n");
		printf("dest�� �̾���� ���ڿ�2�� �Է����ּ���. (1000 Byte) : ");
		rewind(stdin);
	}

	printf("\n[strcat]\n%p : dest address\n%p : return\n", dest, MyStrcat(dest, sizeof(dest), source2, sizeof(source2)));
	printf("dest : %s\n", dest);

	printf("\n���ڿ�1�� ���ڿ�2�� ���մϴ�.");
	printf("\n[strcmp]\nsource1 : \"%s\"\nsource2 : \"%s\"\nreturn : %d\n",source1, source2, MyStrcmp(source1, sizeof(source1), source2, sizeof(source2)));

	return 0;
}

int MyStrlen(char* str, int size)
{
	int len = 0;
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '\0')
		{
			break;
		}
		else if (i == size - 1)
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

char* MyStrcpy(char* dest, int destSize, char* source, int sourceSize)
{
	for (int i = 0; i < destSize - 1; i++)
	{
		if (source[i] == '\0')
		{
			dest[i] = '\0';
			return dest;
		}
		else if (i == sourceSize - 1)
		{
			dest[i + 1] = '\0';
			return dest;
		}
		dest[i] = source[i];
	}
	dest[destSize - 1] = '\0';
	return dest;
}

char* MyStrcat(char* dest, int destSize, char* source, int sourceSize)
{
	int destLen = MyStrlen(dest, destSize);
	int nullLoc = destLen + MyStrlen(source, sourceSize) + 1;

	for (int i = 0; i < nullLoc; i++)
	{
		if (destLen + i == destSize - 1)
		{
			dest[destLen + i] = '\0';
			return dest;
		}
		dest[destLen + i] = source[i];
	}
	dest[nullLoc] = '\0';
	return dest;
}

int MyStrcmp(char* source1, int source1Size, char* source2, int source2Size)
{
	int compare = 0;

	for (int i = 0; i < ((source1Size >= source2Size) ? source1Size : source2Size); i++)
	{
		if (source1[i] != source2[i])
		{
			compare = source1[i] - source2[i];
			compare /= (compare < 0 ? -compare : compare);
			break;
		}
		else if (source1[i] == '\0' && source2[i] == '\0')
		{
			break;
		}
	}
	return compare;
}