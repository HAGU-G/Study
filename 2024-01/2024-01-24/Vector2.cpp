#include "Vector2.h"
#include <iostream>

Vector2 Vector2::Add(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

Vector2 Vector2::Add(const Vector2& rhs)
{
	return Vector2(x + rhs.x, y + rhs.y);
}

//Vector2 Vector2::operator+(const Vector2& rhs)
//{
//	return Vector2(x + rhs.x, y + rhs.y);
//}

void Vector2::Print()
{
	std::cout << x << ", " << y << std::endl;
}

//클래스의 정의부
Vector2::Vector2() : x(0), y(0)
{

}
Vector2::Vector2(float x, float y) : x(x), y(y)
{

}
Vector2::~Vector2()
{

}
float Vector2::GetX() const
{
	return x;
}
float Vector2::GetY() const
{
	return y;
}

Vector2 Add(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
}

Vector2 operator+(const Vector2& lhs, const Vector2& rhs)
{
	return Vector2(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
}
