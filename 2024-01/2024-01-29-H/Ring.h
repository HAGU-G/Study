#pragma once
#include "Shape.h"
#include "Circle.h"

class Ring : public Shape
{
private:
	Circle* insideCircle;
	Circle* outsideCircle;

	void Release();

public:
	Ring(Circle* c1, Circle* c2);
	Ring(const Ring& ref);
	Ring(Ring&& ref) noexcept;
	virtual ~Ring();

	float Area() const override;
	float Round() const override;
	
	Ring& operator=(const Ring& ref);
	Ring& operator=(Ring&& ref) noexcept;

	void Print(std::ostream& cout) const override;
	friend std::ostream& operator<<(std::ostream& cout, const Ring& ring);
};


std::ostream& operator<<(std::ostream& cout, const Ring& ring);