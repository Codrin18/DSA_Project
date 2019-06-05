#pragma once

#include <iostream>
#include <string>
#include "student.h"
typedef bool(*Relation)(Student, Student);

class Node
{
public:
	Student info;
	int next;
	int prev;
public:
	Node();
	~Node();
};

class SortedList
{
public:
	Node nodes[1000];
	int cap;
	int head;
	int tail;
	int firstEmpty;
	int size;
	//Relation rel;
	bool (*rel)(Student, Student);
public:
	SortedList(Relation r);
	SortedList() {};
	~SortedList();
	Student getElement(int& p) const;
	void add(Student& e);
	int position(Student& e);
	Student remove(int p);
	bool search(Student& e);
	bool isEmpty() const;
	int getSize() const;

	//Iterator iterator();

	SortedList& operator=(const SortedList& l);
private:
	int allocate();
	//void free();

};


class Iterator
{
public:
	SortedList sl;
	int currentElement;
public:

	Iterator(const SortedList& sl);
	Student getCurrent();
	void next();
	bool valid();

};

