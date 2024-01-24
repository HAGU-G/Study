//### 연습문제 1: 책 클래스 만들기
//
//- 클래스 이름 : Book
//- 멤버 변수 : title(제목, 문자열), author(저자, 문자열), pages(페이지 수, 정수)
//- 생성자 : 모든 멤버 변수를 초기화할 수 있는 생성자 작성
//- 멤버 함수 : 책 정보를 출력하는 함수 displayInfo() 구현
#pragma once
#include <string>

class Book
{
private:
	std::string title;
	std::string author;
	int pages;
public:

	Book(std::string title = "", std::string author = "", int pages = 0);
	void displayInfo();
};

