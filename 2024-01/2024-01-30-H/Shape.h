#pragma once
#include "Point.h"

class Shape
{
public:
	inline virtual ~Shape() {}

	virtual Point GetCenter() const = 0;
	virtual double Area() const = 0;
	virtual double Round() const = 0;

	virtual void Print(std::ostream& cout) const = 0;

};

std::ostream& operator<<(std::ostream& cout, const Shape* shape);