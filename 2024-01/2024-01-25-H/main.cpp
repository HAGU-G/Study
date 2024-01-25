#include <iostream>
#include "Vector2.h"

int main()
{
	Vector2 vt1(0.f, 0.f);
	Vector2 vt2(2.f, 3.f);

	vt1 += vt2;
	std::cout << "+= " << vt1 << std::endl;
	vt1 -= vt2;
	std::cout << "-= " << vt1 << std::endl;
	vt1 += vt2;
	vt1 *= 2;
	std::cout << "*= " << vt1 << std::endl;
	vt1 /= 2;
	std::cout << "/= " << vt1 << std::endl;


	return 0;
}