#include <iostream>
#include <string>


//4. 아래 함수 정의에서 컴파일 오류가 나는 이유를 찾으시오.
//void drawRectangle(int l, int r, int t, int b) {}
//void drawRectangle(int x = 0, int y = 0, int w, int h) {}
//1) 첫 번째 함수는 int형 매개변수 4개를 사용한다.
//	 두 번째 함수도 int형 매개변수 4개를 사용한다. >> 오버로딩할 수 없기 때문에 컴파일 오류가 발생한다.
//2) 두 번째 함수의 먼저 온 매개변수 두 개는 기본값을 설정해뒀지만 그 뒤의 두 개는 기본값이 없다. >> 컴파일 오류
//	 함수 호출 시 인자를 생략하면 뒤에서부터 생략된다. 따라서 기본값을 만들어두려면 뒤에서부터 해야한다.

//5. 아래 함수 정의에서 컴파일 오류가 나는 이유를 찾으시오.
//void drawRectangle(int w, int h, int x = 0, int y = 0) {}
//void drawRectangle(int x, int y) {}
//첫 번째 함수는 int형 매개변수 4개를 사용한다.
//두 번째 함수는 int형 매개변수 2개를 사용한다.
//오버로딩할 수 있기 때문에 함수 선언만으로는 컴파일 오류가 발생하지 않는다.
//하지만 2개의 인자로 함수를 호출했을 경우 어느 함수를 호출했는지 알 수 없기 때문에 컴파일 오류가 발생한다.

int main()
{
	//1. 이름과 점수를 입력받고 cout과 cin을 사용해서
	//이름 입력: 이름
	//점수 입력: 80
	//이름 님의 점수는 80점입니다.
	//를 출력하시오.
	{
		std::string name;
		int score = 0;

		std::cout << "이름 입력: ";
		std::cin >> name;
		std::cout << "점수 입력: ";
		std::cin >> score;
		std::cout << name << " 님의 점수는 " << score << "점입니다." << std::endl;
	}

	//2. 다음 코드를 실행했을 때 출력 결과를 예측하시오.
	{
		char str[] = "hello, World!";
		std::cout << str << std::endl; //hello, World!
		std::cout << *str << std::endl;//h
	}

	//3. 범위 기반 for문을 사용해 이차원 배열의 내용물을 출력하시오.
	{
		int arr[2][3] = { {1,2,3},{4,5,6} };
		for (auto& i : arr)
		{
			for (auto j : i)
			{
				std::cout << std::to_string(j) + " ";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}