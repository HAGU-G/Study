#include "String.h"
#include <iostream>

//---------private----------

void String::Release()
{
	if (strData)
		delete[] strData;
	strData = nullptr;
}

int String::Compare(const String& ref) const
{
	const char* lhs = strData ? strData : "";
	const char* rhs = ref.strData ? ref.strData : "";

	return strcmp(lhs, rhs);
}

//strData, len 할당
void String::Alloc(const char* str, int newLen)
{
	//널체크는 일관성 있게
	if (strData != str && str)
	{
		if (strData)
		{
			Release();
		}

		//strData는 nullptr인 상태
		len = newLen;
		strData = new char[len + 1];
		strcpy_s(strData, (size_t)len + 1, str);
	}
}
void String::Alloc(const String& ref)
{
	Alloc(ref.strData, ref.len);
}
void String::Alloc(const char* str)
{
	if (str)
		Alloc(str, (int)strlen(str));
}

//----------public----------

String::String()
	: strData(nullptr), len(0)
{
}
String::String(const char* str)
	: strData(nullptr), len(0)
{
	Alloc(str);
}
String::String(const String& ref)
	: strData(nullptr), len(0)
{
	Alloc(ref);
}
String::String(String&& ref) noexcept
	: strData(ref.strData), len(ref.len)
{
	ref.strData = nullptr; //중요!
}
String::~String()
{
	Release();
}


const char* String::GetStrData() const
{
	if (strData)
		return strData;
	return "";
}
int String::GetLen() const
{
	return len;
}


String& String::operator=(const String& rhs)
{
	Alloc(rhs);
	return *this;
}
String& String::operator=(String&& rhs) noexcept
{
	Release();
	strData = rhs.strData;
	len = rhs.len;

	rhs.strData = nullptr;
	rhs.len = 0;

	return *this;
}

String& String::operator+=(const String& rhs)
{

	if (rhs.strData)
	{
		if (strData == rhs.strData)
		{
			char* temp = new char[2 * len + 1];
			strcpy_s(temp, (size_t)(2 * len + 1), strData);
			strcat_s(temp, (size_t)(2 * len + 1), strData);
			Alloc(temp);
		}
		else
		{
			Alloc(strData, len + rhs.len);
			//len 변경됨.
			strcat_s(strData, (size_t)len + 1, rhs.strData);
		}
	}
	return *this;
}
String String::operator+(const String& rhs)
{
	String temp(strData);
	return temp += rhs;
}


bool String::operator==(const String& rhs)
{
	return Compare(rhs) == 0;
}
bool String::operator!=(const String& rhs)
{
	return Compare(rhs) != 0;
}
bool String::operator>(const String& rhs)
{
	return Compare(rhs) > 0;
}
bool String::operator>=(const String& rhs)
{
	return Compare(rhs) >= 0;
}
bool String::operator<(const String& rhs)
{
	return Compare(rhs) < 0;
}
bool String::operator<=(const String& rhs)
{
	return Compare(rhs) <= 0;
}

//----------전역---------

std::ostream& operator<<(std::ostream& print, const String& rhs)
{
	print << rhs.GetStrData();
	return print;
}

std::istream& operator>>(std::istream& scan, String& rhs)
{
	//char 배열을 최대 크기로 만든 다음에 입력을 하면 더 간단하다.
	char first = scan.rdbuf()->sgetc();
	unsigned long long bufLen = scan.rdbuf()->in_avail();
	char* reader = new char[bufLen];
	reader[0] = first;

	for (int i = 1; i < bufLen - 1; i++)
	{
		reader[i] = scan.rdbuf()->snextc();
	}

	reader[bufLen - 1] = '\0';
	rhs.Alloc(reader);

	delete[] reader;
	reader = nullptr;
	return scan;
}