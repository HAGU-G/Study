#pragma once
#include <iostream>

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

	Vector2 operator+(const Vector2& rhs);
	Vector2 operator-(const Vector2& rhs);
	Vector2 operator*(float scalar);
	Vector2 operator/(float scalar);

	Vector2 operator+();
	Vector2 operator-();

	Vector2& operator+=(const Vector2& rhs);
	Vector2& operator-=(const Vector2& rhs);
	Vector2& operator*=(float scalar);
	Vector2& operator/=(float scalar);

	bool operator==(const Vector2& rhs) const;
	bool operator!=(const Vector2& rhs) const;

	friend std::istream& operator>>(std::istream& a, Vector2& rhs); //해당 함수가 private 멤버에 접근할 수 있도록 해준다.
};
	
Vector2 operator*(float scalar, const Vector2& rhs);

std::ostream& operator<<(std::ostream& a, const Vector2& rhs);
std::istream& operator>>(std::istream& a, Vector2& rhs);



//char* ACN;

//생성자 () : ACN(nullptr)
//{
//	int lenght = strlen(an);
// ACN = new char[lenght+1];
// strcpy(ACN , an);
//}

//소멸자()
//delete[] ACN;
//ACN = nullptr;