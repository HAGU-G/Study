#include <stdio.h>

void printfNoSpace(const char* txt) //����� �ƴ� ������ ����� �Ͻ��� �� ��ȯ�� �Ͼ��. �ݴ��� ��쿣 X
{
	int count = 0;
	while (true)
	{
		if (txt[count] == '\0')
		{
			break;
		}
		else if (txt[count] != ' ')
		{
			printf("%c", txt[count]);
		}
		count++;
	}
}

int main()
{
	char txt[] = { "Go to hell.\n" };
	printfNoSpace("Hello, world!\n");
	printfNoSpace(txt);


	//�迭 ��ü�� ����
	for (int i = 0, j = 0; i < sizeof(txt); i++)
	{
		txt[j] = txt[i];
		if (txt[i] != ' ')
			j++;
	}

	printf("%s", txt);

	return 0;
}