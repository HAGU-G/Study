#pragma once
#include "Shape.h"

class Circle : public Shape
{
protected:
	unsigned int radius;
public:
	Circle(Point* pos1, unsigned int r);
	Circle(const Circle& ref);
	Circle(Circle&& ref) noexcept;
	inline virtual ~Circle() {}

	float Area() const override;
	float Round() const override;
	unsigned int GetRadius() const;

	Circle& operator=(const Circle& ref);
	Circle& operator=(Circle&& ref) noexcept;

	void Print(std::ostream& cout) const override;
};


std::ostream& operator<<(std::ostream& cout, const Circle& rec);