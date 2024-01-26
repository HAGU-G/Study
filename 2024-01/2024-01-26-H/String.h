#pragma once
class String
{
private:
	char* strData;
	int len;

	void Alloc(int len);
	void Release();

public:
	String();
	String(const String& ref); //복사 생성자
	String(String&& ref); //이동 생성자
	String(const char* str);
	~String();

	//A(const A& ref) = delete;
	//A& operator=(const A& rhs) = delete;
	//복사, 대입 관련한 생성자와 연산자를 컴파일러가 자동으로 생성하지 않도록 한다.

	const char* GetStrData() const;
	int GetLen() const;

	String& operator=(const String& rhs); //복사 대입 연산자
	String& operator=(String&& rhs); //이동 대입 연산자
};

