#include "Ring.h"

Ring::Ring(Circle* c1, Circle* c2)
	:insideCircle(nullptr), outsideCircle(nullptr)
{
	if (c1 && c2 && c1->GetPosition() == c2->GetPosition() && c1->GetRadius() != c2->GetRadius())
	{
		position = c1->GetPosition();
		if (c1->GetRadius() > c2->GetRadius())
		{
			outsideCircle = new Circle(*c1);
			insideCircle = new Circle(*c2);
		}
		else
		{
			outsideCircle = new Circle(*c2);
			insideCircle = new Circle(*c1);
		}
	}

}

Ring::Ring(const Ring& ref)
	:insideCircle(nullptr), outsideCircle(nullptr)
{
	if (ref.insideCircle && ref.outsideCircle)
	{
		position = ref.position;
		insideCircle = new Circle(*(ref.insideCircle));
		outsideCircle = new Circle(*(ref.outsideCircle));
	}

}

Ring::Ring(Ring&& ref) noexcept
	:Shape(ref.position), insideCircle(ref.insideCircle), outsideCircle(ref.outsideCircle)
{
	ref.Release();
	ref.position.x = 0;
	ref.position.y = 0;
}

Ring::~Ring()
{
	Release();
}

float Ring::Area() const
{
	return outsideCircle->Area() - insideCircle->Area();
}

float Ring::Round() const
{
	return outsideCircle->Round() + insideCircle->Round();
}

Ring& Ring::operator=(const Ring& ref)
{
	Release();

	if (ref.insideCircle && ref.outsideCircle)
	{
		position = ref.position;
		insideCircle = new Circle(*(ref.insideCircle));
		outsideCircle = new Circle(*(ref.outsideCircle));
	}
	else
	{
		position.x = 0;
		position.y = 0;
	}

	return *this;
}

Ring& Ring::operator=(Ring&& ref) noexcept
{
	Release();

	position = ref.position;
	insideCircle = ref.insideCircle;
	outsideCircle = ref.outsideCircle;

	ref.Release();
	ref.position.x = 0;
	ref.position.y = 0;

	return *this;
}

void Ring::Print(std::ostream& cout) const
{
	cout << *this;
}

std::ostream& operator<<(std::ostream& cout, const Ring& ring)
{
	cout << "type: Ring" << std::endl << "center: " << ring.center << std::endl << "radius (in, out): (" << ring.insideCircle->GetRadius() << ", " << ring.outsideCircle->GetRadius() << ")";
	return cout;
}
