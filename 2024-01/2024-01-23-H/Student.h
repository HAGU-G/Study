//### �������� 3: �л� Ŭ���� �����
//
//- Ŭ���� �̸� : Student
//- ��� ���� : name(�̸�, ���ڿ�), studentID(�й�, ���ڿ�), major(����, ���ڿ�)
//- ������ : ��� ��� ������ �ʱ�ȭ�� �� �ִ� ������ �ۼ�
//- ��� �Լ� : �л� ������ ����ϴ� displayInfo() �Լ� ����
#pragma once
#include <string>
class Student
{
private:
	std::string name;
	std::string studentID;
	std::string major;
public:
	Student(std::string name, std::string studentID, std::string major);
	void displayInfo();
};

