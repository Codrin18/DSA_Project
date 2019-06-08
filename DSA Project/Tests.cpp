#include "Tests.h"

bool decreasing(Student a, Student b)
{
	return a.getAvearageGrade() >= b.getAvearageGrade();
}

Test::~Test()
{
}

void Test::testStudent()
{
	Student e{};
	assert(e.getName() == "");
	assert(e.getAvearageGrade() == 0);

	Student e1{ "Mihai",9 };
	assert(e1.getName() == "Mihai");
	assert(e1.getAvearageGrade() == 9);

	string n = "Codrin";
	e1.setName(n);
	float g = 10;
	e1.setAverageGrade(g);

	assert(e1.getName() == "Codrin");
	assert(e1.getAvearageGrade() == 10);
}

void Test::testSortedList()
{
	SortedList l{ decreasing };
	assert(l.getSize() == 0);
	Student e1{ "Codrin",7.56 };
	Student e2{ "Alex",9.24 };
	Student e3{ "Mihai",8.23 };
	Student e4{ "Ciprian",8.75 };
	Student e5{ "Bogdan", 7.8 };
	Student e6{ "Stefan",10 };
	Student e7{ "Raul",8.4 };
	l.add(e1);
	l.add(e2);
	l.add(e3);
	l.add(e4);
	l.add(e5);
	l.add(e6);
	l.add(e7);
	assert(l.getSize() == 7);

	Student e{ "Codrin",7.56 };
	assert(l.search(e) == true);
	Student s{ "Mark",7.56 };
	assert(l.search(s) == false);

	int i = 0;
	Student s1 = l.getElement(i);
	assert(s1.getName() == "Stefan");
	try
	{
		int i = 11;
		Student s1 = l.getElement(i);
	}
	catch(string e)
	{
		assert(true);
	}

	int j = 0;

	Student s2 = l.remove(j);
	assert(s2.getName() == "Stefan");
	assert(l.getSize() == 6);

	try
	{
		int i = 11;
		Student s1 = l.remove(i);
	}
	catch (string e)
	{
		assert(true);
	}
	assert(l.isEmpty() == false);
}
