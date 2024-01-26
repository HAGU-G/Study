#include "String.h"
#include <cstring>
#include <iostream>

void String::Alloc(int len)
{
	strData = new char[len + 1];
	std::cout << "strData �Ҵ�� " << (void*)strData << std::endl; //void* � Ÿ���� ���������� �˻����� �ʰ� �ּҸ� �޴´�.
}

void String::Release()
{
	if (strData)
	{
		delete[] strData;
		std::cout << "strData ������ " << (void*)strData << std::endl; //void* � Ÿ���� ���������� �˻����� �ʰ� �ּҸ� �޴´�.
		strData = nullptr;
	}
}

String::String()
	: strData(nullptr), len(0)
{
	std::cout << "String() : " << this << std::endl;
}

String::String(const String& ref)
	:strData(nullptr), len(ref.len)
{
	std::cout << "String(const String&) : " << this << std::endl;

	if (len > 0)
	{
		Alloc(len);
		strcpy_s(strData, len + 1, ref.strData);
	}

}

String::String(String&& ref)
	: len(ref.len), strData(ref.strData)
{
	std::cout << "String(String&& ref) : " << this << std::endl;

	ref.strData = nullptr; //�߿�! ���� ����
}

String::String(const char* str)
	:strData(nullptr), len(0)
{
	std::cout << "String(const char*) : " << this << std::endl;
	if (str)
		len = strlen(str);
	if (len > 0)
	{
		Alloc(len);
		strcpy_s(strData, len + 1, str);
	}

}

String::~String()
{
	std::cout << "~String() : " << this << std::endl;
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
	std::cout << "operator=(const String&) : " << this << std::endl;
	len = rhs.len;

	Release();

	if (len > 0)
	{
		Alloc(len);
		strcpy_s(strData, len + 1, rhs.strData);
	}

	return *this;
}

String& String::operator=(String&& rhs)
{
	std::cout << "operator=(String&& rhs) : " << this << std::endl;

	len = rhs.len;
	strData = rhs.strData;

	rhs.strData = nullptr;
	return *this;
}
