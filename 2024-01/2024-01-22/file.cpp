#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* in = nullptr; //in이라는 파일 포인터 변수 선언
	//in = fopen("input.txt","rt"); //in에 파일의 경로를 할당 rt은 readtxt
	fopen_s(&in, "input.txt", "rt"); //VS 실행파일 기본 경로는 프로젝트 폴더이다. 실제 응용프로그램은 해당 파일의 위치가 기본 경로이다.

	if (in == nullptr)//fopen으로 파일을 불러오는데 실패할 경우엔 널포인터가 할당된다. 그걸 이용한 에러검출이다.
	{
		printf("파일을 여는 데 실패했습니다.");
		//exit(1); //프로그램이 종료된다.
		return -1; //비정상적인 종료
	}

	//에러가 아닐경우 실행할 내용.


	//txt파일 안에는 123 456 789가 두줄 입력되어있다.
	int n = 0;
	fscanf(in, "%d", &n);
	printf("%d\n", n); //123

	fscanf(in, "%d", &n);
	printf("%d\n", n); //456

	fclose(in);

	FILE* out = nullptr;
	out = fopen("output.txt", "wt");
	fprintf(out, "%d", n); //이어서 써지는게 아니라 처음부터 덮어써진다.
	fprintf(out, "%d", n); //버퍼에 하나씩 쌓아두고 fclose 할때 저장된다.
	fclose(out); //이 순간에 출력된다. 456456

	//파일의 모든 내용 출력
	fopen_s(&in, "input.txt", "rt");
	char ch;
	while (fscanf(in, "%c", &ch) != EOF) //EndOfFile 파일의 끝에 도달하면 -1을 반환한다.
	{
		printf("%c", ch);
	}
	fclose(in);


	//파일 복사
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