#pragma once
#include "slist.h"
#include <iostream>

bool relation(Student a, Student b)
{
	return a.getAvearageGrade() >= b.getAvearageGrade();
}

int main()
{
	Student e1{ "Codrin",7.56 };
	Student e2{ "Alex",9.24 };
	Student e3{ "Mihai",8.23 };
	Student e4{ "Ciprian",8.75 };
	Student e5{"Bogdan", 7.8};
	Student e6{ "Stefan",10 };
	SortedList list{ relation };
	list.add(e1);
	list.add(e2);
	list.add(e3);
	list.add(e4);
	list.add(e5);
	list.add(e6);
	Iterator it{ list };
	int i = 0;
	while (i < list.getSize())
	{
		std::cout << it.getCurrent().toString() << std::endl;
		it.next();
		i++;
	}
	return 0;
}