#pragma once
#include "Shape.h"

class Circle : public Shape
{
protected:
	Point center;
	double radius;
public:
	Circle(const Point* pos1, double r);
	Circle(const Point& pos1, double r);
	Circle(const Circle& ref);
	Circle(Circle&& ref) noexcept;
	inline virtual ~Circle() {}

	void SetCenter(const Point& pos);
	void SetRadius(double r);

	Point GetCenter() const override;
	double GetRadius() const;
	double Area() const override;
	double Round() const override;

	Circle& operator=(const Circle& ref);
	Circle& operator=(Circle&& ref) noexcept;

	void Print(std::ostream& cout) const override;
	friend std::ostream& operator<<(std::ostream& cout, const Circle& rec);
};


std::ostream& operator<<(std::ostream& cout, const Circle& rec);