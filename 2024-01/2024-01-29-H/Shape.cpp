#include "Shape.h"

Shape::Shape() : position(0, 0)
{
}
Shape::Shape(Point* pos) : position(0, 0)
{
	if (pos)
	{
		position.x = pos->x;
		position.y = pos->y;
	}
}

Shape::Shape(Point pos) : position(pos.x, pos.y)
{
}

Point Shape::GetPosition() const
{
	return position;
}

void Shape::Print(std::ostream& cout) const
{
}

std::ostream& operator<<(std::ostream& cout, const Shape* shape)
{
	shape->Print(cout);
	return cout;
}
