#include "String.h"
#include <iostream>

//---------private----------

void String::Release()
{
	if(strData)
		delete[] strData;
	strData = nullptr;
}

int String::Compare(const String& ref) const
{
	const char* lhs = strData ? strData : "";
	const char* rhs = ref.strData ? ref.strData : "";
	
	for (int i = 0; i < (strlen(lhs) > strlen(rhs) ? strlen(lhs) : strlen(rhs)); i++)
	{
		if (lhs[i] != rhs[i] || lhs[i] == '\0' || rhs[i] == '\0')
			return lhs[i] - rhs[i];
	}
	return 0;
}

/// <summary>
/// strData, len에 새로운 값 할당
/// </summary>
/// <param name="str">문자열</param>
/// <param name="newLen">문자열 길이(널문자 제외)</param>
void String::Alloc(const char* str, int newLen)
{
	char* temp = new char[newLen + 1];

	if (str)
	{
		for (int i = 0; i < newLen; i++)
		{
			temp[i] = str[i];
			if (str[i] == '\0')
				break;
		}
	}
	temp[newLen] = '\0';

	if (strData)
	{
		Release();
	}
	
	//strData는 nullptr인 상태
	len = newLen;
	strData = new char[len + 1];
	strcpy_s(strData, (size_t)len + 1, temp);
	
	delete[] temp;
	temp = nullptr;
}
void String::Alloc(const String& ref)
{
	Alloc(ref.strData, ref.len);
}
void String::Alloc(const char* str)
{
	if(str)
		Alloc(str, (int)strlen(str));
}

//----------public----------
static void test()
{
	this.
}

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
		Alloc(strData, len + rhs.len);
		strcat_s(strData, (size_t)len + 1, rhs.strData);
	}
	return *this;
}
String String::operator+(const String& rhs)
{
	String temp(strData);
	temp += rhs;
	return temp;
}


bool String::operator==(const String& rhs)
{
	int ret = Compare(rhs);
	return !ret;
}
bool String::operator!=(const String& rhs)
{
	int ret = Compare(rhs);
	return ret;
}
bool String::operator>(const String& rhs)
{
	int ret = Compare(rhs);
	return ret > 0;
}
bool String::operator>=(const String& rhs)
{
	int ret = Compare(rhs);
	return ret >= 0;
}
bool String::operator<(const String& rhs)
{
	int ret = Compare(rhs);
	return ret < 0;
}
bool String::operator<=(const String& rhs)
{
	int ret = Compare(rhs);
	return ret <= 0;
}

//----------전역---------

std::ostream& operator<<(std::ostream& print, const String& rhs)
{
	print << rhs.GetStrData();
	return print;
}

std::istream& operator>>(std::istream& scan, String& rhs)
{
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
