#pragma once
#include "Point.h"
class Shape
{
public:
	inline virtual ~Shape() {}

	virtual float Area() const = 0;
	virtual float Round() const = 0;

	virtual void Print(std::ostream& cout) const = 0;

};

std::ostream& operator<<(std::ostream& cout, const Shape& shape);
std::ostream& operator<<(std::ostream& cout, const Shape* shape);