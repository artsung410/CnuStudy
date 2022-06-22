#include "No_Iterator_Forward_List.h"
#include <algorithm>
// 반복자를 사용하면 세부구현에 관계없이 데이터 모음의 원소에 접근하려할때 일관된 인터페이스를 제공한다.

// 기본생성자
ForwardList::ForwardList()
{
	_head->Next = _end;
}

// 명시적변환
ForwardList::ForwardList(size_t count)
	: ForwardList()
{
	for (size_t i = 0; i < count; i++)
	{
		push_front(0);
	}
}

// 복사생성자
ForwardList::ForwardList(const ForwardList& other)
	: ForwardList()
{
	Node* inserted = before_begin();
	for (const Node* i = other.begin(); i != other.end(); i = i->Next)
		// 반복자 사용하면 세부구현 생각없이 포인터 처럼 연산자를 쓸수 있지만 그렇지 않을 경우 신경써야할게 많다.
	{
		inserted = insert_after(inserted, i->data);
	}
}

// 할당연산자
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

// 첫번째 요소 반환
int& ForwardList::front()
{
	return begin()->data;
}
const int& ForwardList::front() const
{
	return begin()->data;
}

// 시작전 요소를 가리키는 노드포인터 반환
ForwardList::Node* ForwardList::before_begin()
{
	return _head;
}
const ForwardList::Node* ForwardList::before_begin() const
{
	return _head;
}

// 시작요소를 가리키는 포인터 반환
ForwardList::Node* ForwardList::begin()
{
	return _head->Next;
}
const ForwardList::Node* ForwardList::begin() const
{
	return _head->Next;
}

// 끝 다음요소를 가리키는 포인터 반환
ForwardList::Node* ForwardList::end()
{
	return _end;
}
const ForwardList::Node* ForwardList::end() const
{
	return _end;
}

// pos다음에 value를 삽입한다.
// 삽입된 요소를 가리키는 포인터 반환
ForwardList::Node* ForwardList::insert_after(const Node* pos, int value)
{
	Node* newNode = new Node(value);
	Node* where = (Node*)pos;

	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

// pos다음요소 삭제
// 삭제된 요소의 다음요소를 가리키는 포인터반환
// 아무요소도없으면 end반환
ForwardList::Node* ForwardList::erase_after(const Node* pos)
{
	if (empty())
	{
		return end();
	}
	
	Node* where = (Node*)pos;
	Node* removed = where->Next;

	where->Next = removed->Next;
	removed->Next = nullptr;

	return removed;
}

// 시작요소에 value삽입
void ForwardList::push_front(int value)
{
	insert_after(before_begin(), value);
}

// 시작요소 제거
void ForwardList::pop_front()
{
	erase_after(before_begin());
}

// 컨테이너 비었는지 판단
bool ForwardList::empty() const
{
	if (_head->Next == _end)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 컨테이너 비움
void ForwardList::clear()
{
	// 비었는지 판단하고
	// 비어있지 않으면
	while (empty() == false)
	{
		// 시작요소 제거
		// 빌때까지 반복
		pop_front();
	}
}

// value가 있는지 검사
bool ForwardList::contains(int value) const
{
	// 처음부터 끝까지 순회하며 찾기
	// 있으면 true 반환 , 없으면 false반환
	for (const Node* i = begin(); i != end(); i = i->Next)
	{
		if (i->data == value)
		{
			return true;
		}
	}

	return false;
}