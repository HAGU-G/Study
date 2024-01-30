#include "Shape.h"

std::ostream& operator<<(std::ostream& cout, const Shape& shape)
{
	shape.Print(cout);
	return cout;
}

std::ostream& operator<<(std::ostream& cout, const Shape* shape)
{
	shape->Print(cout);
	return cout;
}
