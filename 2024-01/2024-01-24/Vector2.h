#pragma once

class Vector2
{
private:
	float x;
	float y;

public:
	//클래스의 선언부
	Vector2();
	Vector2(float x, float y);
	~Vector2();
	float GetX() const;
	float GetY() const;

	static Vector2 Add(const Vector2& lhs, const Vector2& rhs);
	Vector2 Add(const Vector2& rhs);

	//Vector2 operator+(const Vector2& rhs);

	void Print();
};

Vector2 Add(const Vector2& lhs, const Vector2& rhs);
Vector2 operator+(const Vector2& lhs, const Vector2& rhs);