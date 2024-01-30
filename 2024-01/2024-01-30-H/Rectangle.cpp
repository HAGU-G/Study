#include "Rectangle.h"

Rectangle::Rectangle(const Point* pos1, const Point* pos2)
	:LT(), LB(), RT(), RB()
{
	if (pos1 && pos2)
	{
		SetPoints(*pos1, *pos2);
	}
}

Rectangle::Rectangle(const Point& pos1, const Point& pos2)
	:Rectangle(&pos1, &pos2)
{
}

Rectangle::Rectangle(const Rectangle& ref)
	:LT(ref.LT), LB(ref.LB), RT(ref.RT), RB(ref.RB)
{

}

Rectangle::Rectangle(Rectangle&& ref) noexcept
	:LT(ref.LT), LB(ref.LB), RT(ref.RT), RB(ref.RB)
{
	ref.LT = Point();
	ref.LB = Point();
	ref.RT = Point();
	ref.RB = Point();
}

void Rectangle::SetPoints(const Point& pos1, const Point& pos2)
{
	if (pos1.x != pos2.x && pos1.y != pos2.y)
	{
		//pos1이 어느 점인지 검사
		if (pos1.x > pos2.x)//R
		{
			if (pos1.y > pos2.y)//RT
			{
				RT = pos1;
				LB = pos2;

				RB = Point(pos1.x, pos2.y);
				LT = Point(pos2.x, pos1.y);
			}
			else//RB
			{
				RB = pos1;
				LT = pos2;

				RT = Point(pos1.x, pos2.y);
				LB = Point(pos2.x, pos1.y);
			}
		}
		else//L
		{
			if (pos1.y > pos2.y)//LT
			{
				LT = pos1;
				RB = pos2;

				LB = Point(pos1.x, pos2.y);
				RT = Point(pos2.x, pos1.y);
			}
			else//LB
			{
				LB = pos1;
				RT = pos2;

				LT = Point(pos1.x, pos2.y);
				RB = Point(pos2.x, pos1.y);
			}
		}
	}
}

void Rectangle::SetLT(const Point& pos)
{
	if (pos.x < RT.x && pos.y > LB.y)
	{
		LT = pos;
		RT.y = pos.y;
		LB.x = pos.x;
	}
}

void Rectangle::SetLB(const Point& pos)
{
	if (pos.x < RB.x && pos.y < LT.y)
	{
		LB = pos;
		RB.y = pos.y;
		LT.x = pos.x;
	}
}

void Rectangle::SetRT(const Point& pos)
{
	if (pos.x > LT.x && pos.y > RB.y)
	{
		RT = pos;
		LT.y = pos.y;
		RB.x = pos.x;
	}
}

void Rectangle::SetRB(const Point& pos)
{
	if (pos.x > LB.x && pos.y < RT.y)
	{
		RB = pos;
		LB.y = pos.y;
		RT.x = pos.x;
	}
}

void Rectangle::SetTopY(double topY)
{
	if (topY > LB.y)
		LT.y = RT.y = topY;
}

void Rectangle::SetBottomY(double bottomY)
{
	if (bottomY < LT.y)
		LB.y = RB.y = bottomY;
}

void Rectangle::SetLeftX(double leftX)
{
	if (leftX > RT.x)
		LT.x = RB.x = leftX;
}

void Rectangle::SetRightX(double rightX)
{
	if (rightX > LT.x)
		RT.x = RB.x = rightX;
}

Point Rectangle::GetLT() const
{
	return LT;
}

Point Rectangle::GetLB() const
{
	return LB;
}

Point Rectangle::GetRT() const
{
	return RT;
}

Point Rectangle::GetRB() const
{
	return RB;
}

Point Rectangle::GetCenter() const
{
	return Point((RT.x + LB.x) / 2.0, (RT.y + RB.y) / 2.0);
}

double Rectangle::Area() const
{
	return (RT.x - LB.x) * (RT.y - LB.y);
}

double Rectangle::Round() const
{
	return 2.0 * ((RT.x - LB.x) + (RT.y - LB.y));
}

Rectangle& Rectangle::operator=(const Rectangle& ref)
{
	LT = ref.LT;
	LB = ref.LB;
	RT = ref.RT;
	RB = ref.RB;
	return *this;
}

Rectangle& Rectangle::operator=(Rectangle&& ref) noexcept
{
	LT = ref.LT;
	LB = ref.LB;
	RT = ref.RT;
	RB = ref.RB;

	ref.LT = Point();
	ref.LB = Point();
	ref.RT = Point();
	ref.RB = Point();
	return *this;
}

void Rectangle::Print(std::ostream& cout) const
{
	cout << *this;
}

std::ostream& operator<<(std::ostream& cout, const Rectangle& rec)
{
	cout << "type: Rectangle" << std::endl << "LT, RT: " << rec.LT << ", " << rec.RT << std::endl << "LB, RB: " << rec.LB << ", " << rec.RB;

	return cout;
}