//### 연습문제 4: 시간 클래스 만들기
//
//- 클래스 이름 : Time
//- 멤버 변수 : hour(시, 정수), minute(분, 정수), second(초, 정수)
//- 생성자 : 시, 분, 초를 초기화할 수 있는 생성자 작성
//- 멤버 함수 :
//-현재 시간을 설정하는 setTime(int h, int m, int s) 함수
//- 현재 시간을 24시간 형식으로 출력하는 displayTime24() 함수
//- 현재 시간을 12시간 형식으로 출력하는 displayTime12() 함수(오전 / 오후 포함)
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
	void displayTime24();
	void displayTime12();
	int GetHour12() const;
	std::string GetAMPM() const;

};

