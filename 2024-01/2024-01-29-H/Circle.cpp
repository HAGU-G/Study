#include "Circle.h"
#define PI (3.14159265f)

Circle::Circle(Point* pos1, unsigned int r)
	:Shape(pos1), radius(r)
{
}

Circle::Circle(const Circle& ref)
	:Shape(ref.position), radius(ref.radius)
{

}

Circle::Circle(Circle&& ref) noexcept
	: Shape(ref.position), radius(ref.radius)
{
	ref.position.x = 0;
	ref.position.y = 0;
	ref.radius = 0;
}

float Circle::Area() const
{
	return PI * radius * radius;
}

float Circle::Round() const
{
	return 2 * PI * radius;
}

unsigned int Circle::GetRadius() const
{
	return radius;
}

Circle& Circle::operator=(const Circle& ref)
{
	position = ref.position;
	radius = ref.radius;
	return *this;
}

Circle& Circle::operator=(Circle&& ref) noexcept
{
	position = ref.position;
	radius = ref.radius;

	ref.position.x = 0;
	ref.position.y = 0;
	ref.radius = 0;

	return *this;
}

void Circle::Print(std::ostream& cout) const
{
	cout << *this;
}

std::ostream& operator<<(std::ostream& cout, const Circle& circle)
{
	cout << "type: Circle" << std::endl << "position: " << circle.GetPosition() << std::endl <<"radius: "<<circle.GetRadius();

	return cout;
}
