#pragma once
#include "Shape.h"

class Circle : public Shape
{
protected:
	Point center;
	unsigned int radius;
public:
	Circle(Point* pos1, unsigned int r);
	Circle(const Circle& ref);
	Circle(Circle&& ref) noexcept;
	inline virtual ~Circle() {}

	Point GetCenter() const;
	unsigned int GetRadius() const;
	float Area() const override;
	float Round() const override;

	Circle& operator=(const Circle& ref);
	Circle& operator=(Circle&& ref) noexcept;

	void Print(std::ostream& cout) const override;
};


std::ostream& operator<<(std::ostream& cout, const Circle& rec);