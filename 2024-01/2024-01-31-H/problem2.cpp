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

//ÇÔ¼ö Æ÷ÀÎÅÍ ¹è¿­
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

	cout << "¿¬»êÀÇ Á¾·ù ÀÔ·Â (0: µ¡¼À, 1: »¬¼À, 2: °ö¼À, 3: ³ª´°¼À) : ";
	cin >> op;
	cout << "Á¤¼ö 2°³ ÀÔ·Â : ";
	cin >> a >> b;

	cout << OPS[op](a, b);
}