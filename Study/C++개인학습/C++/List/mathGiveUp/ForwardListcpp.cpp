#include "ForwardList.h"
#include <math.h>
#include <utility>

ForwardList::ForwardList()
{
	// _head-> []
	// _end-> []

	// [] -> []
	_head->Next = _end; 
}

ForwardList::ForwardList(size_t count) : ForwardList()
{
	for (size_t i = 0; i < count; ++i)
	{
		push_front(0);
	}
}

ForwardList::ForwardList(const ForwardList& other)
	: ForwardList()
{
	iterator inserted = before_begin();
	for (const_iterator iter = other.begin(); iter != other.end(); ++iter)
	{
		inserted = insert_after(inserted, *iter);
	}
}

ForwardList& ForwardList::operator=(const ForwardList& rhs)
{
	if (&rhs != this)
	{
		ForwardList temp(rhs);
		std::swap(_head, temp._head);
		std::swap(_end, temp._end);
	}
	
	return *this;
}

ForwardList::~ForwardList()
{
	clear();
	delete _head;
	_head = nullptr;
	delete _end;
	_end = nullptr;
}

const int& ForwardList::front() const
{
	return *begin();
}

ForwardList::iterator ForwardList::before_begin()
{
	return _head;
}

ForwardList::const_iterator ForwardList::before_begin() const
{
	return _head;
}

ForwardList::iterator ForwardList::begin()
{
	return _head->Next;
}

ForwardList::const_iterator ForwardList::begin() const
{
	return _head->Next;
}

ForwardList::iterator ForwardList::end()
{
	return _end;
}

ForwardList::const_iterator ForwardList::begin() const
{
	return _end;
}

ForwardList::iterator ForwardList::insert_after(const_iterator pos, int value)
{	
	Node* newNode = new Node(value);
	Node* where = pos._p;

	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

ForwardList::iterator ForwardList::erase_after(const_iterator pos)
{
	// []->[]->[]->[]
	//   where removed
 	if (empty())
	{
		return end();
	}

	Node* where = pos._p;
	Node* removed = where->Next;

	where->Next = removed->Next;
	removed->Next = nullptr; // 노드를 끊어준다.

	return removed;
}

void ForwardList::push_front(int value)
{
	insert_after(before_begin(), value);
}

void ForwardList::pop_front()
{
	erase_after(before_begin());
}

bool ForwardList::empty() const
{
	if (_head->Next = _end) // if(begin() == end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ForwardList::clear()
{
	while (false == empty())
	{
		pop_front();
	}
}

bool ForwardList::contains(int value) const
{
	for (const_iterator iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
		{
			return true;
		}
	}
	return false;
}