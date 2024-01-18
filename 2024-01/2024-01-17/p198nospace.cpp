#include <stdio.h>

void printfNoSpace(const char* txt) //상수가 아닌 변수는 상수로 암시적 형 변환이 일어난다. 반대의 경우엔 X
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


	//배열 자체를 수정
	for (int i = 0, j = 0; i < sizeof(txt); i++)
	{
		txt[j] = txt[i];
		if (txt[i] != ' ')
			j++;
	}

	printf("%s", txt);

	return 0;
}