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
	String(const String& ref); //���� ������
	String(String&& ref); //�̵� ������
	String(const char* str);
	~String();

	//A(const A& ref) = delete;
	//A& operator=(const A& rhs) = delete;
	//����, ���� ������ �����ڿ� �����ڸ� �����Ϸ��� �ڵ����� �������� �ʵ��� �Ѵ�.

	const char* GetStrData() const;
	int GetLen() const;

	String& operator=(const String& rhs); //���� ���� ������
	String& operator=(String&& rhs); //�̵� ���� ������
};

