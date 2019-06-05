#include "student.h"

Student::Student(const std::string& name, const float& grade)
{
	this->name = name;
	this->averageGrade = grade;
}

Student::~Student()
{
}

