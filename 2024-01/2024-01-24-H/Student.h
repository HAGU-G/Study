//### 연습문제 3: 학생 클래스 만들기
//
//- 클래스 이름 : Student
//- 멤버 변수 : name(이름, 문자열), studentID(학번, 문자열), major(전공, 문자열)
//- 생성자 : 모든 멤버 변수를 초기화할 수 있는 생성자 작성
//- 멤버 함수 : 학생 정보를 출력하는 displayInfo() 함수 구현
#pragma once
#include <string>
class Student
{
private:
	std::string name;
	std::string studentID;
	std::string major;
public:
	Student(const std::string& name, const std::string& studentID, const std::string& major);
	void displayInfo();
};

