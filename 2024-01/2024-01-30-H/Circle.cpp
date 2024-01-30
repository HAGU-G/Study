#include "Circle.h"
#define PI (3.14159265f)

Circle::Circle(Point* pos1, unsigned int r)
	:center(), radius(r)
{
	if (pos1)
		center = *pos1;
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

void Circle::SetRadius(unsigned int r)
{
	radius = r;
}

float Circle::Area() const
{
	return PI * radius * radius;
}

float Circle::Round() const
{
	return 2 * PI * radius;
}

Point Circle::GetCenter() const
{
	return center;
}

unsigned int Circle::GetRadius() const
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

	ref.center.x = 0;
	ref.center.y = 0;
	ref.radius = 0;

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
