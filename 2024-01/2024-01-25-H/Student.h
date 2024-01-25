#pragma once
#include <string>
class Student
{
private:
	char* name;
	char* studentID;
	char* major;
public:
	Student(const char* name, const char* studentID, const char* major);
	~Student();
	void displayInfo() const;
};

