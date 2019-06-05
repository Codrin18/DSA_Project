#include "slist.h"



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
	if (p < 0)
		throw "Invalid position";
	return this->nodes[p].info;
}

void SortedList::add(Student& e)
{
	if (this->firstEmpty == -1)
		throw "Maaximum capacity reached";
	int newElem = this->allocate();
	this->nodes[newElem].info = e;
	this->size++;

	if (this->head == -1)
	{
		this->head = newElem;
		this->tail = newElem;
		//this->firstEmpty++;
		//this->nodes[newElem].next = this->firstEmpty;
	}
	else if (rel(e,this->nodes[this->head].info))
	{
		this->nodes[newElem].next = this->head;
		this->nodes[this->head].prev = newElem;
		this->head = newElem;
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
	this->nodes[p - 1].next = this->nodes[p].next;
	this->nodes[p + 1].prev = this->nodes[p].prev;
	this->size--;
	return this->nodes[p].info;
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