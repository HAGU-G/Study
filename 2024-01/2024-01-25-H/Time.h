#pragma once
#include <string>
class Time
{
private:
	int hour;
	int minute;
	int second;

public:
	Time(int h = 0, int m = 0, int s = 0);
	void setTime(int h, int m, int s);
	void displayTime24() const;
	void displayTime12() const;
	int GetHour12() const;
	std::string GetAMPM() const;

};

