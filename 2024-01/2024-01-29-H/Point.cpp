#include "Point.h"
#include <cmath>

Point::Point(int x, int y)
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
	ref.x = 0;
	ref.y = 0;
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

	ref.x = 0;
	ref.y = 0;
	return *this;
}

std::ostream& operator<<(std::ostream& cout, const Point& point)
{
	cout << "( " << point.x << ", " << point.y << ")";

	return cout;
}

float Distance(const Point& p1, const Point& p2)
{
	return sqrtf(powf(p1.x - p2.x, 2) + powf(p1.y - p2.y, 2));
}
