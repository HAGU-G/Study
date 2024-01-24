#include <iostream>
#include "Color.h"

Color::Color() : r(0.0f), g(0.0f), b(0.0f), a(1.0f), id(idCounter++)
{

}
Color::Color(float r, float g, float b, float a) : r(r), g(g), b(b), a(a), id(idCounter++)
{

}
Color::~Color()
{

}

float Color::GetR() const
{
	return r;
}
float Color::GetG() const
{
	return g;
}
float Color::GetB()
{
	return b;
}

void Color::Print()
{
	std::cout << "(" << r << ", " << g << ", " << b << ", " << a << ")" << std::endl;
}

//정의부에서는 static을 사용하지 않는다.
Color Color::MixColors(const Color& a, const Color& b)
{
	Color mixed;
	mixed.r = (a.r + b.r) * 0.5f;
	mixed.g = (a.g + b.g) * 0.5f;
	mixed.b = (a.b + b.b) * 0.5f;

	return mixed;

}

unsigned int Color::GetColor32(const Color& color)
{
	return((unsigned int)(color.r * 255) << 24)
		| ((unsigned int)(color.g * 255) << 16)
		| ((unsigned int)(color.b * 255) << 8)
		| ((unsigned int)(color.a * 255));
}

Color Color::GetColor(unsigned int color32)
{
	return Color(((color32 >> 24) & 0x000000FF) / 255.0f, ((color32 >> 16) & 0x000000FF) / 255.0f, ((color32 >> 8) & 0x000000FF) / 255.0f, (color32 & 0x000000FF) / 255.0f);
}

int Color::idCounter = 0; //static 멤버 변수의 초기화는 cpp에서 한다.