#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
private:
	Point LT;
	Point LB;
	Point RT;
	Point RB;

public:
	Rectangle(Point* pos1, Point* pos2);
	Rectangle(const Rectangle& ref);
	Rectangle(Rectangle&& ref) noexcept;
	inline virtual ~Rectangle() {}

	void SetPoints(const Point& pos1,const Point& pos2);
	void SetLT(const Point& pos);
	void SetLB(const Point& pos);
	void SetRT(const Point& pos);
	void SetRB(const Point& pos);
	void SetTopY(double topY);
	void SetBottomY(double bottomY);
	void SetLeftX(double leftX);
	void SetRightX(double rightX);

	Point GetLT() const;
	Point GetLB() const;
	Point GetRT() const;
	Point GetRB() const;
	Point GetCenter() const override;
	double Area() const override;
	double Round() const override;

	Rectangle& operator=(const Rectangle& ref);
	Rectangle& operator=(Rectangle&& ref) noexcept;

	void Print(std::ostream& cout) const override;
	friend std::ostream& operator<<(std::ostream& cout, const Rectangle& rec);
};

std::ostream& operator<<(std::ostream& cout, const Rectangle& rec);