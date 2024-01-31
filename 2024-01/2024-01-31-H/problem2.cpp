#include <iostream>
using namespace std;

int add(int a, int b) {
	return a + b;
}
int sub(int a, int b) {
	return a - b;
}
int mul(int a, int b) {
	return a * b;
}
int divi(int a, int b) {
	return a / b;
}

//�Լ� ������ �迭
int (*OPS[]) (int, int) = {
	[](int a, int b) -> int { return a + b; },
	[](int a, int b) -> int { return a - b; },
	[](int a, int b) -> int { return a * b; },
	[](int a, int b) -> int { return a / b; }
};

int main()
{
	int op;
	int a, b;

	cout << "������ ���� �Է� (0: ����, 1: ����, 2: ����, 3: ������) : ";
	cin >> op;
	cout << "���� 2�� �Է� : ";
	cin >> a >> b;

	cout << OPS[op](a, b);
}