#pragma once
#include "slist.h"
#include "Tests.h"
#include <iostream>

bool relation(Student a, Student b)
{
	return a.getAvearageGrade() >= b.getAvearageGrade();
}

void populate(SortedList& list)
{
	Student e1{ "Codrin",7.56 };
	Student e2{ "Alex",9.24 };
	Student e3{ "Mihai",8.23 };
	Student e4{ "Ciprian",8.75 };
	Student e5{ "Bogdan", 7.8 };
	Student e6{ "Stefan",10 };
	Student e7{ "Raul",8.4 };
	list.add(e1);
	list.add(e2);
	list.add(e3);
	list.add(e4);
	list.add(e5);
	list.add(e6);
	list.add(e7);
}

void printAll(SortedList list)
{
	Iterator it{ list };
	while (it.valid())
	{
		std::cout << it.getCurrent().toString() << std::endl;
		it.next();
	}
}

void addStudent(SortedList& list)
{
	std::string name;
	std::cout << "Give the name of the student:";
	getline(std::cin, name);
	float g;
	std::cout << "Give the grade of the student:";
	Student e{ name,g };
	list.add(e);
}

Student removeStudent(SortedList& list)
{
	int p;
	std::cout << "Give the position";
	std::cin >> p;
	return list.remove(p);
}

void searchStudent(SortedList list)
{
	std::string name;
	std::cout << "Give the name of the student:";
	getline(std::cin, name);
	float g;
	std::cout << "Give the grade of the student:";
	std::cin >> g;
	Student e{ name,g };
	if (list.search(e))
		std::cout << "The student is in the least";
	else
		std::cout << "The student is not in the least";
}

Student getStudent(SortedList list)
{
	int p;
	std::cout << "Give the position";
	std::cin >> p;
	return list.getElement(p);
}

int main()
{
	SortedList list{ relation };
	populate(list);
	Test t;
	t.testStudent();
	t.testSortedList();
	printAll(list);
	return 0;
}