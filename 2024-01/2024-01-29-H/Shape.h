#pragma once
#include "Point.h"
class Shape
{
private:

protected:
	Point position;
public:
	Shape();
	Shape(Point* pos);
	Shape(Point pos);
	inline virtual ~Shape() {}

	virtual float Area() const = 0;
	virtual float Round() const = 0;
	Point GetPosition() const;

	virtual void Print(std::ostream& cout) const = 0;

};

std::ostream& operator<<(std::ostream& cout, const Shape& shape);