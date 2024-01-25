#pragma once
#include <iostream>
//클래스의 선언부

class Vector2
{
private:
	float x;
	float y;

public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();


	float GetX() const;
	float GetY() const;

	static Vector2 Add(const Vector2& lhs, const Vector2& rhs);
	Vector2 Add(const Vector2& rhs);

	//Vector2 operator+(const Vector2& rhs);
	Vector2 operator-(const Vector2& rhs);
	Vector2 operator*(float scalar);
	Vector2 operator/(float scalar);

	Vector2 operator-();
	Vector2 operator+();

	Vector2& operator-=(const Vector2& rhs);
	Vector2& operator-=(float scalar);

	bool operator==(const Vector2& rhs) const;
	bool operator!=(const Vector2& rhs) const;

	Vector2& operator++(); //전위
	Vector2& operator++(int); //후위

	void Print();

	friend std::istream& operator>>(std::istream& a, Vector2& rhs); //해당 함수가 private 멤버에 접근할 수 있도록 해준다.
};

Vector2 Add(const Vector2& lhs, const Vector2& rhs);
Vector2 operator+(const Vector2& lhs, const Vector2& rhs);

Vector2 Minus(const Vector2& lhs, const Vector2& rhs);
Vector2 operator-(const Vector2& lhs, const Vector2& rhs);
	
Vector2 operator*(float scalar, const Vector2& rhs);

std::ostream& operator<<(std::ostream& a, const Vector2& rhs);
std::istream& operator>>(std::istream& a, Vector2& rhs);

