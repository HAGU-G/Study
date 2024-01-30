#pragma once
#include <iostream>

struct Point
{
	float x;
	float y;

	Point(float x = 0.f, float y = 0.f);
	Point(const Point& ref);
	Point(Point&& ref) noexcept;

	bool operator==(const Point& point) const;
	Point& operator=(const Point& ref);
	Point& operator=(Point&& ref) noexcept;
};

std::ostream& operator<<(std::ostream& cout, const Point& point);