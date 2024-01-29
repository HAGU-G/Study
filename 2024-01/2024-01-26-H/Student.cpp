#include "Student.h"
#include <iostream>

Student::Student(const char* name, const char* studentID, const char* major)
	: name(nullptr), studentID(nullptr), major(nullptr)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	
	this->studentID = new char[strlen(studentID) + 1];
	strcpy_s(this->studentID, strlen(studentID) + 1, studentID);

	this->major = new char[strlen(major) + 1];
	strcpy_s(this->major, strlen(major) + 1, major);
}

Student::Student(const Student& ref)
	: name(nullptr), studentID(nullptr), major(nullptr)
{
	//? 널포인터 만들어놓고 널체크하면 어떡함
	if (ref.name && ref.studentID && ref.major)
	{
		name = new char[strlen(ref.name) + 1];
		strcpy_s(name, strlen(ref.name) + 1, ref.name);

		studentID = new char[strlen(ref.studentID) + 1];
		strcpy_s(studentID, strlen(ref.studentID) + 1, ref.studentID);

		major = new char[strlen(ref.major) + 1];
		strcpy_s(major, strlen(ref.major) + 1, ref.major);
	}
}

Student::Student(Student&& ref) noexcept
	: name(ref.name), studentID(ref.studentID), major(ref.major)
{
	ref.name = ref.studentID = ref.major = nullptr;
}

Student::~Student()
{
	if (name)
		delete[] name;
	if (studentID)
		delete[] studentID;
	if (major)
		delete[] major;
	name = nullptr;
	studentID = nullptr;
	major = nullptr;
}

void Student::displayInfo() const
{
	std::cout << "Student: " << name << std::endl << "ID: " << studentID << std::endl << "Major: " << major << std::endl;
}

Student& Student::operator=(const Student& ref)
{
	name = new char[strlen(ref.name) + 1];
	strcpy_s(name, strlen(ref.name) + 1, ref.name);

	studentID = new char[strlen(ref.studentID) + 1];
	strcpy_s(studentID, strlen(ref.studentID) + 1, ref.studentID);

	major = new char[strlen(ref.major) + 1];
	strcpy_s(major, strlen(ref.major) + 1, ref.major);
	return *this;
}

Student& Student::operator=(Student&& ref) noexcept
{
	name = ref.name;
	studentID = ref.studentID;
	major = ref.major;

	ref.name = ref.studentID = ref.major = nullptr;
	return *this;
}
