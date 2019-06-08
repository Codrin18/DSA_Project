#include "slist.h"
#include <exception>


Iterator::Iterator(const SortedList& sl)
{
	this->sl = sl;
	this->currentElement = this->sl.head;
}

Student Iterator::getCurrent()
{
	if (this->currentElement == -1)
	{
		throw "Exception";
	}
	return this->sl.nodes[this->currentElement].info;
}

void Iterator::next()
{
	if (this->currentElement == -1)
	{
		throw "Exception";
	}
	this->currentElement = this->sl.nodes[this->currentElement].next;
}

bool Iterator::valid()
{
	if (this->currentElement == -1)
		return false;
	return true;
}

SortedList::SortedList(Relation r)
{
	this->cap = 100;
	this->head = -1;
	this->tail = -1;
	this->size = 0;
	this->firstEmpty = 0;
	this->rel = r;
	for (int i = 1; i < this->cap; i++)
	{
		this->nodes[i].prev = i - 1;
		this->nodes[i].next = i + 1;

	}
	this->nodes[0].prev = -1;
	this->nodes[0].next = 1;
}

SortedList::~SortedList()
{
}

Student SortedList::getElement(int& p) const
{
	// TODO: insert return statement here
	std::string s("The position is not good");
	if (p < 0 || p >= this->getSize())
		throw s;
	int prev = -1;
	Iterator it{ *this };
	int current = it.currentElement;
	int i = 0;
	while (it.valid() and i < p)
	{
		prev = current;
		it.next();
		current = it.currentElement;
		i++;
	}
	return this->nodes[current].info;
}

void SortedList::add(Student& e)
{
	if (this->firstEmpty == -1)
		throw "Maaximum capacity reached";
	int newElem = this->allocate();
	this->nodes[newElem].info = e;
	
		

	if (this->head == -1)
	{
		this->head = newElem;
		this->tail = newElem;
		this->nodes[this->head].info = e;
		this->nodes[this->tail].info = e;
		//this->firstEmpty++;
		//this->nodes[newElem].next = this->firstEmpty;
		this->size++;
	}
	else if (this->rel(e,this->nodes[this->head].info))
	{
		this->nodes[newElem].next = this->head;
		this->nodes[this->head].prev = newElem;
		this->head = newElem;
		this->size++;
	}
	else
	{
		int nodC = this->head;
		int nod = this->nodes[nodC].next;
		while (this->nodes[nodC].next != -1 and rel(e, this->nodes[nod].info) == false)
		{
			nodC = this->nodes[nodC].next;
			nod = this->nodes[nodC].next;
		}
		if (nodC != -1)
		{
			int nodNext = this->nodes[nodC].next;
			this->nodes[newElem].next = nodNext;
			this->nodes[newElem].prev = nodC;
			this->nodes[nodC].next = newElem;

			if (nodNext == -1)
			{
				this->tail = newElem;
			}
			else
			{
				this->nodes[nodNext].prev = newElem;
			}
			this->size++;
		}
	}
}

int SortedList::position(Student& e)
{
	int current = this->head;
	while (current != -1 and nodes[current].info != e)
	{
		current = this->nodes[current].next;
	}

	if (current == -1)
		return -1;
	return current;
}

Student SortedList::remove(int p)
{
	std::string s("The position is not good");
	if (p < 0 || p >= this->getSize())
		throw s;
	int i = 0;
	Iterator it{ *this };
	int current = it.currentElement;
	int prev = this->nodes[current].prev;
	while (it.valid() and i < p - 1)
	{
		prev = current;
		it.next();
		current = it.currentElement;
		i++;
	}
	if (prev == -1)
	{
		this->head = this->nodes[current].next;
		this->size--;
		return this->nodes[current].info;
	}
	else if (current == -1)
	{
		int nodC = this->nodes[current].prev;
		this->nodes[nodC].next = -1;
		this->size--;
		return this->nodes[current].info;
	}
	else
	{
		this->nodes[prev].next = this->nodes[current].next;
		int nod = this->nodes[current].next;
		this->size--;
		return this->nodes[current].info;
	}
}

bool SortedList::search(Student& e)
{
	int current = this->head;
	while (current != -1 and nodes[current].info != e)
	{
		current = this->nodes[current].next;
	}

	if (current != -1)
		return true;
	else
		return false;
}

bool SortedList::isEmpty() const
{
	if (this->size > 0)
		return false;
	else
		return true;
}

int SortedList::getSize() const
{
	return this->size;
}




SortedList& SortedList::operator=(const SortedList& l)
{
	// TODO: insert return statement here
	if (this == &l)
		return *this;
	this->size = l.size;
	this->cap = l.cap;
	this->head = l.head;
	this->tail = l.tail;
	this->firstEmpty = l.firstEmpty;
	for (int i = 0; i < l.cap; ++i)
	{
		this->nodes[i] = l.nodes[i];
	}
	this->rel = l.rel;
}

int SortedList::allocate()
{
	int newElem = this->firstEmpty;
	if (newElem != -1)
	{
		this->firstEmpty = this->nodes[this->firstEmpty].next;
		if (this->firstEmpty != -1)
		{
			this->nodes[this->firstEmpty].prev = -1;
		}
		this->nodes[newElem].next = -1;
		this->nodes[newElem].prev = -1;
	}
	return newElem;
}

Node::Node()
{
}

Node::~Node()
{
}