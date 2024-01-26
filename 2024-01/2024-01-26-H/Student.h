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
	Student(const Student& ref);
	Student(Student&& ref) noexcept;
	~Student();
	void displayInfo() const;

	Student& operator=(const Student& ref);
	Student& operator=(Student&& ref) noexcept;
};

