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
	//�Ҽ��� ���..? �ڵ�
	std::cin >> a >> b;

	std::cout << a + b << std::endl;

	std::string name; //�����ϸ� �� ���ڿ��� �ʱ�ȭ�ȴ�. ���ù��ڿ��� �迭�� �Ҵ��� ���� �� �ִ�.
	std::cout << name << std::endl;
	name = "AASD";
	std::cout << name << std::endl;


	int arr[3][5][6] = {{6, 5, 4, 3, 2, 1},{1, 1, 4, 3, 2, 1},{1, 1, 4, 3, 2, 1} };
	//�迭�̳� �����̳� �Լ��� �޴� �ݺ���
		for (auto& i : arr) //�����̳ʿ� ���ִ� ��ҵ��� ó������ ������ ������� �Ҵ�ȴ�.
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