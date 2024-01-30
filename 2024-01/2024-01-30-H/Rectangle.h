#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	Point position2;
public:
	Rectangle(Point* pos1, Point* pos2);
	Rectangle(const Rectangle& ref);
	Rectangle(Rectangle&& ref) noexcept;
	inline virtual ~Rectangle() {}

	float Area() const override;
	float Round() const override;

	Rectangle& operator=(const Rectangle& ref);
	Rectangle& operator=(Rectangle&& ref) noexcept;

	void Print(std::ostream& cout) const override;
	friend std::ostream& operator<<(std::ostream& cout, const Rectangle& rec);
};

std::ostream& operator<<(std::ostream& cout, const Rectangle& rec);