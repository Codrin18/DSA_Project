#pragma once

#include <string>

class Student
{
private:
	std::string name;
	float averageGrade;
public:
	Student() :name(""), averageGrade(0) {}
	Student(const std::string& name, const float& grade);
	~Student();
	std::string getName() const { return this->name; }
	float getAvearageGrade() const { return this->averageGrade; }
	void setName(std::string& n) { name = n; }
	void setAverageGrade(float& grade) { averageGrade = grade; }
	bool operator!=(const Student& e) { return this->name != e.getName(); }
	std::string toString() { return this->name + " " + std::to_string(this->averageGrade); }
};