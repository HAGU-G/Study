#include "Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

Circle::Circle(Point* pos1, double r)
	:center(), radius(0)
{
	if (pos1)
		center = *pos1;
	if (r > 0.0)
		radius = r;
}

Circle::Circle(const Circle& ref)
	:center(ref.center), radius(ref.radius)
{

}

Circle::Circle(Circle&& ref) noexcept
	: center(ref.center), radius(ref.radius)
{
	ref.center.x = 0;
	ref.center.y = 0;
	ref.radius = 0;
}

void Circle::SetCenter(const Point& pos)
{
	center = pos;
}

void Circle::SetRadius(double r)
{
	if (r > 0.0)
		radius = r;
}

double Circle::Area() const
{
	return M_PI * pow(radius, 2);
}

double Circle::Round() const
{
	return 2.0 * M_PI * radius;
}

Point Circle::GetCenter() const
{
	return center;
}

double Circle::GetRadius() const
{
	return radius;
}

Circle& Circle::operator=(const Circle& ref)
{
	center = ref.center;
	radius = ref.radius;
	return *this;
}

Circle& Circle::operator=(Circle&& ref) noexcept
{
	center = ref.center;
	radius = ref.radius;

	ref.center.x = 0.0;
	ref.center.y = 0.0;
	ref.radius = 0.0;

	return *this;
}

void Circle::Print(std::ostream& cout) const
{
	cout << *this;
}

std::ostream& operator<<(std::ostream& cout, const Circle& circle)
{
	cout << "type: Circle" << std::endl << "center: " << circle.center << std::endl <<"radius: "<<circle.radius;

	return cout;
}
