#include "Ring.h"

Ring::Ring(Circle* c1, Circle* c2)
	:center(), insideCircle(nullptr, 0), outsideCircle(nullptr, 0)
{
	if (c1 && c2 && c1->GetCenter() == c2->GetCenter() && c1->GetRadius() != c2->GetRadius())
	{
		center = c1->GetCenter();
		if (c1->GetRadius() > c2->GetRadius())
		{
			outsideCircle = *c1;
			insideCircle = *c2;
		}
		else
		{
			outsideCircle = *c2;
			insideCircle = *c1;
		}
	}

}

Ring::Ring(const Ring& ref)
	:center(ref.center), insideCircle(ref.insideCircle), outsideCircle(ref.outsideCircle)
{
}

Ring::Ring(Ring&& ref) noexcept
	:center(ref.center), insideCircle(ref.insideCircle), outsideCircle(ref.outsideCircle)
{
	ref.center = Point();
	ref.insideCircle = Circle(nullptr, 0);
	ref.outsideCircle = Circle(nullptr, 0);
}

Ring::~Ring()
{
}

void Ring::SetCenter(const Point& pos)
{
	center = pos;
}

void Ring::SetInsideCircle(const Circle& circle)
{
	insideCircle = circle;
}

void Ring::SetOutsideCircle(const Circle& circle)
{
	outsideCircle = circle;
}

Point Ring::GetCenter() const
{
	return center;
}

Circle Ring::GetInsideCircle() const
{
	return insideCircle;
}

Circle Ring::GetOutsideCircle() const
{
	return outsideCircle;
}

float Ring::Area() const
{
	return outsideCircle.Area() - insideCircle.Area();
}

float Ring::Round() const
{
	return outsideCircle.Round() + insideCircle.Round();
}

Ring& Ring::operator=(const Ring& ref)
{
	center = ref.center;
	insideCircle = ref.insideCircle;
	outsideCircle = ref.outsideCircle;

	return *this;
}

Ring& Ring::operator=(Ring&& ref) noexcept
{
	center = ref.center;
	insideCircle = ref.insideCircle;
	outsideCircle = ref.outsideCircle;

	ref.center = Point();
	ref.insideCircle = Circle(nullptr, 0);
	ref.outsideCircle = Circle(nullptr, 0);

	return *this;
}

void Ring::Print(std::ostream& cout) const
{
	cout << *this;
}

std::ostream& operator<<(std::ostream& cout, const Ring& ring)
{
	cout << "type: Ring" << std::endl << "center: " << ring.center << std::endl << "radius (in, out): (" << ring.insideCircle.GetRadius() << ", " << ring.outsideCircle.GetRadius() << ")";
	return cout;
}
