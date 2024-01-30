#pragma once
#include <iostream>

struct Point
{
	double x;
	double y;

	explicit Point(double x = 0.0, double y = 0.0);
	Point(const Point& ref);
	Point(Point&& ref) noexcept;

	bool operator==(const Point& point) const;
	Point& operator=(const Point& ref);
	Point& operator=(Point&& ref) noexcept;
};

std::ostream& operator<<(std::ostream& cout, const Point& point);