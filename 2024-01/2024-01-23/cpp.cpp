#include <iostream>
#include <string>

using namespace std;

int main()
{
	std::cout << "Hello World" << std::endl;

	int a = 5;
	double b = 3.14;
	char c = 'd';

	std::cout << a << b << c << std::endl;
	//소숫점 출력..? 자동
	std::cin >> a >> b;

	std::cout << a + b << std::endl;

	std::string name; //선언하면 빈 문자열로 초기화된다. 원시문자열과 배열로 할당을 해줄 수 있다.
	std::cout << name << std::endl;
	name = "AASD";
	std::cout << name << std::endl;


	int arr[3][5][6] = {{6, 5, 4, 3, 2, 1},{1, 1, 4, 3, 2, 1},{1, 1, 4, 3, 2, 1} };
	//배열이나 컨테이너 함수를 받는 반복문
		for (auto& i : arr) //컨테이너에 들어가있는 요소들이 처음부터 끝까지 순서대로 할당된다.
		{
			for (auto& j : i)
			{
				for (auto k : j)
				{
					std::cout << k << std::endl;
				}
			}
		}

	return 0;
}