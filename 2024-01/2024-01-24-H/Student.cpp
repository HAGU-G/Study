#include "Student.h"
#include <iostream>

Student::Student(std::string name, std::string studentID, std::string major) : name(name), studentID(studentID), major(major)
{
}

void Student::displayInfo()
{
	std::cout << "Student: " << name << std::endl << "ID: " << studentID << std::endl << "Major: " << major << std::endl;
}
