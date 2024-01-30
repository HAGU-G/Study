#pragma once
#include <iostream>

class String
{
private:
	char* strData;	//char[] ���� �Ҵ�
	int len;		//strData�� ���ڿ� ����, �ι��� ����

	void Release(); //strData�� nullptr�� �ƴҰ�� delete�Ѵ�.
	
	int Compare(const String& ref) const; //strcmp�� ������ �Լ�. �񱳿����� �����ε��� ����ߴ�.

	void Alloc(const char* str, int newLen); //��� Alloc�Լ��� �ڽ��� �Ű��������� �������� 10���� �Լ��� �����Ѵ�.
	void Alloc(const String& ref);			 //strData�� len�� ���ο� ���� �Ҵ����ֱ� ���� �Լ��̴�.
	void Alloc(const char* str);

public:
	String();
	String(const String& ref); //���� ������
	String(String&& ref) noexcept; //�̵� ������
	String(const char* str);
	~String();



	const char* GetStrData() const;
	int GetLen() const;

	String& operator=(const String& rhs); //���� ���� ������
	String& operator=(String&& rhs) noexcept;	  //�̵� ���� ������
	
	String& operator+=(const String& rhs);
	String operator+(const String& rhs); //+= �����ε��� ����ؼ� �����ϰ� �����ߴ�.

	bool operator==(const String& rhs); //�� �����ڵ��� Compare�Լ��� ����ؼ� �����ߴ�.
	bool operator!=(const String& rhs);
	bool operator>(const String& rhs);
	bool operator>=(const String& rhs);
	bool operator<(const String& rhs);
	bool operator<=(const String& rhs);
	
	friend std::istream& operator>>(std::istream& print, String& rhs);

};

	std::ostream& operator<<(std::ostream& print, const String& rhs);
	std::istream& operator>>(std::istream& scan, String& rhs); //std::string�� ������� �ʰ� �����ߴ�.