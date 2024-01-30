#pragma once
#include <iostream>

class String
{
private:
	char* strData;	//char[] 동적 할당
	int len;		//strData의 문자열 길이, 널문자 제외

	void Release(); //strData가 nullptr가 아닐경우 delete한다.
	
	int Compare(const String& ref) const; //strcmp을 구현한 함수. 비교연산자 오버로딩에 사용했다.

	void Alloc(const char* str, int newLen); //모든 Alloc함수는 자신의 매개변수들을 바탕으로 10행의 함수를 실행한다.
	void Alloc(const String& ref);			 //strData와 len에 새로운 값을 할당해주기 위한 함수이다.
	void Alloc(const char* str);

public:
	String();
	String(const String& ref); //복사 생성자
	String(String&& ref) noexcept; //이동 생성자
	String(const char* str);
	~String();



	const char* GetStrData() const;
	int GetLen() const;

	String& operator=(const String& rhs); //복사 대입 연산자
	String& operator=(String&& rhs) noexcept;	  //이동 대입 연산자
	
	String& operator+=(const String& rhs);
	String operator+(const String& rhs); //+= 오버로딩을 사용해서 간단하게 구현했다.

	bool operator==(const String& rhs); //비교 연산자들은 Compare함수를 사용해서 구현했다.
	bool operator!=(const String& rhs);
	bool operator>(const String& rhs);
	bool operator>=(const String& rhs);
	bool operator<(const String& rhs);
	bool operator<=(const String& rhs);
	
	friend std::istream& operator>>(std::istream& print, String& rhs);

};

	std::ostream& operator<<(std::ostream& print, const String& rhs);
	std::istream& operator>>(std::istream& scan, String& rhs); //std::string을 사용하지 않고 구현했다.