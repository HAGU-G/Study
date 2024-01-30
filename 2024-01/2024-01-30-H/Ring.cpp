#include "Ring.h"
#define _USE_MATH_DEFINES
#include <math.h>

Ring::Ring(Circle* c1, Circle* c2)
	:center(), smallRadius(0.0), largeRadius(0.0)
{
	if (c1 && c2 && c1->GetCenter() == c2->GetCenter() && c1->GetRadius() != c2->GetRadius())
	{
		center = c1->GetCenter();
		if (c1->GetRadius() > c2->GetRadius())
		{
			largeRadius = c1->GetRadius();
			smallRadius = c2->GetRadius();
		}
		else
		{
			largeRadius = c2->GetRadius();
			smallRadius = c1->GetRadius();
		}
	}

}

Ring::Ring(const Ring& ref)
	:center(ref.center), smallRadius(ref.smallRadius), largeRadius(ref.largeRadius)
{
}

Ring::Ring(Ring&& ref) noexcept
	:center(ref.center), smallRadius(ref.smallRadius), largeRadius(ref.largeRadius)
{
	ref.center = Point();
	ref.smallRadius = 0;
	ref.largeRadius = 0;
}

Ring::~Ring()
{
}

void Ring::SetCenter(const Point& pos)
{
	center = pos;
}

void Ring::SetSmallRadius(double r)
{
	if (r < largeRadius)
		smallRadius = r;
}

void Ring::SetLargeRadius(double R)
{
	if (R > smallRadius)
		largeRadius = R;
}

Point Ring::GetCenter() const
{
	return center;
}

double Ring::GetSmallRadius() const
{
	return smallRadius;
}

double Ring::GetLargeRadius() const
{
	return largeRadius;
}

double Ring::Area() const
{
	return pow(largeRadius, 2) * M_PI - pow(smallRadius, 2) * M_PI;
}

double Ring::Round() const
{
	return 2.0 * M_PI * largeRadius + 2.0 * M_PI * smallRadius;
}

Ring& Ring::operator=(const Ring& ref)
{
	center = ref.center;
	smallRadius = ref.smallRadius;
	largeRadius = ref.largeRadius;

	return *this;
}

Ring& Ring::operator=(Ring&& ref) noexcept
{
	center = ref.center;
	smallRadius = ref.smallRadius;
	largeRadius = ref.largeRadius;

	ref.center = Point();
	ref.smallRadius = 0.0;
	ref.largeRadius = 0.0;

	return *this;
}

void Ring::Print(std::ostream& cout) const
{
	cout << *this;
}

std::ostream& operator<<(std::ostream& cout, const Ring& ring)
{
	cout << "type: Ring" << std::endl << "center: " << ring.center << std::endl << "radius (samll, large): (" << ring.smallRadius << ", " << ring.largeRadius << ")";
	return cout;
}
