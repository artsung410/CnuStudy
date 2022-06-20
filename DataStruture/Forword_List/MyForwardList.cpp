#include "ForwardList.h"
#include <algorithm>

ForwardList::ForwardList()
{
	// _head -> [something]
	// _end -> [something]

	// [something] -> [something]
	_head->Next = _end;
}

// 생성자
ForwardList::ForwardList(size_t count)
	: ForwardList() // 기본생성자
{
	for (size_t i = 0; i < count; i++)
	{
		push_front(0); // 각 노드에 0 을 추가한다?
	}
}

// 복사생성자
ForwardList::ForwardList(const ForwardList& other) // 매개변수를 자기자신을 받는다
	: ForwardList()
{
	iterator inserted = before_begin();
	for (const_iterator iter = other.begin(); iter != other.end(); ++iter)
	{
		inserted = insert_after(inserted, *iter);
	}
}

// 복사할당연산자
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

// 소멸자
ForwardList::~ForwardList()
{
	clear();

	delete _head;
	_head = nullptr;

	delete _end;
	_end = nullptr;
}

int& ForwardList::front()
{
	return *begin();
}

const int& ForwardList::front() const
{
	return *begin();
}

ForwardList::iterator ForwardList::before_begin()
{
	return _head; // 암시적변환이 일어나 반환값으로 head사용가능
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

ForwardList::const_iterator ForwardList::end() const
{
	return _end;
}

ForwardList::iterator ForwardList::insert_after(const_iterator pos, int value)
{
	// [] -> [] -> [] -> []
	//       pos
	//          value
	// [] -> []  [] -> []
	//        ↓   ↑ 
	//        value

	Node* newNode = new Node(value);
	Node* where = pos._p;

	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

ForwardList::iterator ForwardList::erase_after(const_iterator pos)
{
	//// pos의 다음 노드가 end() => 비었다면
	//removed == _end;
	//if (empty())
	//{
	//	return end();
	//}
	if (empty())
	{
		return end();
	}

	Node* where = pos._p;
	Node* removed = where->Next; // 여기서 removed는 삭제할 노드다.

	where->Next = removed->Next;
	removed->Next = nullptr;

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
	// begin == end
	if (_head->Next == _end)
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
	// 컨테이너 비우기
	while (false == empty())
	{
		pop_front();
	}
}

bool ForwardList::contains(int value) const
{
	// 처음부터 끝까지 순회하면서 찾는다
	for (const_iterator iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
		{
			return true;
		}
	}

	return false;
}

