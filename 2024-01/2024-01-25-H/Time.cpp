#include "Time.h"
#include <iostream>
Time::Time(int h, int m, int s) : hour(h), minute(m), second(s)
{
	if (h < 0 || m < 0 || s < 0 || h > 23 || m > 60 || s > 60)
	{
		std::cout << "(" << h << ":" << m << ":" << s << ")는 유효한 시간이 아닙니다." << std::endl;
		hour = 0;
		minute = 0;
		second = 0;
	}
}

void Time::setTime(int h, int m, int s)
{
	if (h < 0 || m < 0 || s < 0 || h > 23 || m > 60 || s > 60)
	{
		std::cout << "(" << h << ":" << m << ":" << s << ")는 유효한 시간이 아닙니다." << std::endl;
	}
	else
	{
		hour = h;
		minute = m;
		second = s;
	}
}

void Time::displayTime24() const
{
	std::cout << "Time: " << hour << ":" << minute << ":" << second << " (24 - hour format)" << std::endl;
}

void Time::displayTime12() const
{
	std::cout << "Time: " << GetHour12() << ":" << minute << ":" << second << " " + GetAMPM() + " (12 - hour format)" << std::endl;
}

int Time::GetHour12() const
{
	return (hour == 12) ? 12 : hour % 12;
}

std::string Time::GetAMPM() const
{
	return (hour < 12) ? "AM" : "PM";
}
