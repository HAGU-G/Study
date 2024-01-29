#include "Rectangle.h"

Rectangle::Rectangle(Point* pos1, Point* pos2)
	:Shape(pos1), position2(0,0)
{
	if (pos2)
	{
		position2.x = pos2->x;
		position2.y = pos2->y;
	}
}

Rectangle::Rectangle(const Rectangle& ref)
	:Shape(ref.position), position2(ref.position2)
{

}

Rectangle::Rectangle(Rectangle&& ref) noexcept
	:Shape(ref.position), position2(ref.position2)
{
	ref.position.x = 0;
	ref.position.y = 0;
	ref.position2.x = 0;
	ref.position2.y = 0;
}

float Rectangle::Area() const
{
	return abs((position.x - position2.x) * (position.y - position2.y));
}

float Rectangle::Round() const
{
	return 2 * abs(position.x - position2.x) + 2 * abs(position.y - position2.y);
}

Rectangle& Rectangle::operator=(const Rectangle& ref)
{
	position = ref.position;
	position2 = ref.position2;

	return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& ref) noexcept
{
	position = ref.position;
	position2 = ref.position2;

	ref.position.x = 0;
	ref.position.y = 0;
	ref.position2.x = 0;
	ref.position2.y = 0;
	return *this;
}

void Rectangle::Print(std::ostream& cout) const
{
	cout << *this;
}

std::ostream& operator<<(std::ostream& cout, const Rectangle& rec)
{
	cout << "type: Rectangle" << std::endl << "position: " << rec.position << std::endl << "position2: " << rec.position2;

	return cout;
}