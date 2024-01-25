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

Student::~Student()
{
	delete[] name;
	delete[] studentID;
	delete[] major;
	name = nullptr;
	studentID = nullptr;
	major = nullptr;
}

void Student::displayInfo() const
{
	std::cout << "Student: " << name << std::endl << "ID: " << studentID << std::endl << "Major: " << major << std::endl;
}
