#include "Point.h"

explicit Point::Point(double x, double y)
	:x(x), y(y)
{
}

Point::Point(const Point& ref)
	:x(ref.x), y(ref.y)
{
}

Point::Point(Point&& ref) noexcept
	:x(ref.x), y(ref.y)
{
	ref.x = 0.0;
	ref.y = 0.0;
}

bool Point::operator==(const Point& point) const
{
	return x == point.x && y == point.y;
}

Point& Point::operator=(const Point& ref)
{
	x = ref.x;
	y = ref.y;
	return *this;
}

Point& Point::operator=(Point&& ref) noexcept
{
	x = ref.x;
	y = ref.y;

	ref.x = 0.0;
	ref.y = 0.0;
	return *this;
}

std::ostream& operator<<(std::ostream& cout, const Point& point)
{
	cout << "( " << point.x << ", " << point.y << ")";

	return cout;
}
