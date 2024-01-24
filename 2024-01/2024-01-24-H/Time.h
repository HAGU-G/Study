//### �������� 4: �ð� Ŭ���� �����
//
//- Ŭ���� �̸� : Time
//- ��� ���� : hour(��, ����), minute(��, ����), second(��, ����)
//- ������ : ��, ��, �ʸ� �ʱ�ȭ�� �� �ִ� ������ �ۼ�
//- ��� �Լ� :
//-���� �ð��� �����ϴ� setTime(int h, int m, int s) �Լ�
//- ���� �ð��� 24�ð� �������� ����ϴ� displayTime24() �Լ�
//- ���� �ð��� 12�ð� �������� ����ϴ� displayTime12() �Լ�(���� / ���� ����)
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

