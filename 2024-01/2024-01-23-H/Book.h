//### �������� 1: å Ŭ���� �����
//
//- Ŭ���� �̸� : Book
//- ��� ���� : title(����, ���ڿ�), author(����, ���ڿ�), pages(������ ��, ����)
//- ������ : ��� ��� ������ �ʱ�ȭ�� �� �ִ� ������ �ۼ�
//- ��� �Լ� : å ������ ����ϴ� �Լ� displayInfo() ����
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

