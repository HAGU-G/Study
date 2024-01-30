#pragma once
#include "Shape.h"
#include "Circle.h"

class Ring : public Shape
{
protected:
	Point center;
	double smallRadius;
	double largeRadius;

public:
	Ring(Circle* c1, Circle* c2);
	Ring(const Ring& ref);
	Ring(Ring&& ref) noexcept;
	virtual ~Ring();
	
	void SetCenter(const Point& pos);
	void SetSmallRadius(double r);
	void SetLargeRadius(double R);

	Point GetCenter() const override;
	double GetSmallRadius() const;
	double GetLargeRadius() const;
	double Area() const override;
	double Round() const override;
	
	Ring& operator=(const Ring& ref);
	Ring& operator=(Ring&& ref) noexcept;

	void Print(std::ostream& cout) const override;
	friend std::ostream& operator<<(std::ostream& cout, const Ring& ring);
};


std::ostream& operator<<(std::ostream& cout, const Ring& ring);