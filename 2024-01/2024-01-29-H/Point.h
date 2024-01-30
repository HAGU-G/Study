#pragma once
#include <iostream>
class Point
{
public:
	int x;
	int y;

	Point(int x = 0, int y = 0);
	Point(const Point& ref);
	Point(Point&& ref) noexcept;

	bool operator==(const Point& point) const;
	Point& operator=(const Point& ref);
	Point& operator=(Point&& ref) noexcept;
};

std::ostream& operator<<(std::ostream& cout, const Point& point);

float Distance(const Point& p1, const Point& p2);