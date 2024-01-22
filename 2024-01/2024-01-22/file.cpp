#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* in = nullptr; //in�̶�� ���� ������ ���� ����
	//in = fopen("input.txt","rt"); //in�� ������ ��θ� �Ҵ� rt�� readtxt
	fopen_s(&in, "input.txt", "rt"); //VS �������� �⺻ ��δ� ������Ʈ �����̴�. ���� �������α׷��� �ش� ������ ��ġ�� �⺻ ����̴�.

	if (in == nullptr)//fopen���� ������ �ҷ����µ� ������ ��쿣 �������Ͱ� �Ҵ�ȴ�. �װ� �̿��� ���������̴�.
	{
		printf("������ ���� �� �����߽��ϴ�.");
		//exit(1); //���α׷��� ����ȴ�.
		return -1; //���������� ����
	}

	//������ �ƴҰ�� ������ ����.


	//txt���� �ȿ��� 123 456 789�� ���� �ԷµǾ��ִ�.
	int n = 0;
	fscanf(in, "%d", &n);
	printf("%d\n", n); //123

	fscanf(in, "%d", &n);
	printf("%d\n", n); //456

	fclose(in);

	FILE* out = nullptr;
	out = fopen("output.txt", "wt");
	fprintf(out, "%d", n); //�̾ �����°� �ƴ϶� ó������ ���������.
	fprintf(out, "%d", n); //���ۿ� �ϳ��� �׾Ƶΰ� fclose �Ҷ� ����ȴ�.
	fclose(out); //�� ������ ��µȴ�. 456456

	//������ ��� ���� ���
	fopen_s(&in, "input.txt", "rt");
	char ch;
	while (fscanf(in, "%c", &ch) != EOF) //EndOfFile ������ ���� �����ϸ� -1�� ��ȯ�Ѵ�.
	{
		printf("%c", ch);
	}
	fclose(in);


	//���� ����
	in = fopen("input.txt", "rt");
	out = fopen("output.txt", "wt");
	char ch2;
	while (fscanf(in, "%c", &ch2) != EOF)
	{
		fprintf(out, "%c", ch2);
	}
	fclose(in);
	fclose(out);

	return 0;
}