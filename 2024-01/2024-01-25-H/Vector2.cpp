#include "Vector2.h"


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

Vector2 Vector2::operator+(const Vector2& rhs) const
{
	return Vector2(x + rhs.x, y + rhs.y);
}
Vector2 Vector2::operator-(const Vector2& rhs) const
{
	return Vector2(x - rhs.x, y - rhs.y);
}
Vector2 Vector2::operator*(float scalar) const
{
	return Vector2(x * scalar, y * scalar);
}
Vector2 Vector2::operator/(float scalar) const
{
	return Vector2(x / scalar, y / scalar);
}

Vector2 Vector2::operator-()
{
	return Vector2(0.0f - x, 0.0f - y);
	//return *this * -1;
}
Vector2 Vector2::operator+()
{
	return Vector2(0.0f + x, 0.0f + y);
	//return *this;
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}
Vector2& Vector2::operator*=(float scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}
Vector2& Vector2::operator/=(float scalar)
{
	x /= scalar;
	y /= scalar;
	return *this;
}

bool Vector2::operator==(const Vector2& rhs) const
{
	return x == rhs.x && y == rhs.y;
}

bool Vector2::operator!=(const Vector2& rhs) const
{
	return !(*this == rhs);
}

bool Vector2::operator>(const Vector2& rhs) const
{
	return x * x + y * y > rhs.x * rhs.x + rhs.y * rhs.y;
}

bool Vector2::operator>=(const Vector2& rhs) const
{
	return x * x + y * y >= rhs.x * rhs.x + rhs.y * rhs.y;
}

bool Vector2::operator<(const Vector2& rhs) const
{
	return x * x + y * y < rhs.x * rhs.x + rhs.y * rhs.y;

}

bool Vector2::operator<=(const Vector2& rhs) const
{
	return x * x + y * y <= rhs.x * rhs.x + rhs.y * rhs.y;
}

//---------전역---------

Vector2 operator*(float scalar, const Vector2& rhs)
{
	return Vector2(scalar * rhs.GetX(), scalar * rhs.GetY());
}

std::ostream& operator<<(std::ostream& lhs, const Vector2& rhs)
{
	lhs << "(" << rhs.GetX() << ", " << rhs.GetY() << ")";
	return lhs;
}

std::istream& operator>>(std::istream& lhs, Vector2& rhs)
{
	lhs >> rhs.x >> rhs.y;
	return lhs;
}
