#include "ForwardList_iterator.h"
#include <algorithm>

ForwardList::Node::Node(int data, Node* next)
	: Data(data), Next(next)
{

}

ForwardList::Node::~Node()
{
	// 댕글링포인터가 안되도록 관리
	Next = nullptr;
}

ForwardList::const_iterator::const_iterator(Node* p)
	: _p(p)
{

}

ForwardList::const_iterator::~const_iterator()
{
	_p = nullptr;
}

const int& ForwardList::const_iterator::operator*() const
{
	return _p->Data;
}

const int* ForwardList::const_iterator::operator->() const
{
	return &(_p->Data); // 주소값을 반환한다.

}

ForwardList::const_iterator& ForwardList::const_iterator::operator++()
{
	_p = _p->Next;

	return *this;
}

ForwardList::const_iterator ForwardList::const_iterator::operator++(int)
{
	// 1. p를 1증가시키고
	// 2. 이전 p를 반환한다.

	const_iterator temp = *this;
	_p = _p->Next;

	return temp;

	// iterator를 후위연산자로 쓸경우 연산과정이 증가하므로 엥간하면 전위로 쓰자
}

bool ForwardList::const_iterator::operator==(const const_iterator& rhs) const
{
	if (_p == rhs._p)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ForwardList::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

// 널포인터와 비교하는 연산자
bool ForwardList::const_iterator::operator==(nullptr_t p)const
{
	// 널포인터등장배경 : null의 모호함때문
	// null은 정수로서의 0도되고
	// 포인터로서의 null도 되기때문에 -> 오류발생증가

	if (_p == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ForwardList::const_iterator::operator!=(nullptr_t p)const
{
	return !(*this == nullptr);
}

ForwardList::iterator::iterator(Node* p)
	: const_iterator(p)
{

}

int& ForwardList::iterator::operator*() const
{
	return (int&)const_iterator::operator*();
}

int* ForwardList::iterator::operator->() const
{
	return (int*)const_iterator::operator->();
}

ForwardList::iterator& ForwardList::iterator::operator++()
{
	const_iterator::operator++();
	return *this;
}

ForwardList::iterator ForwardList::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();
	return temp;
}

ForwardList::ForwardList()
{
	// _head -> [something]
	// _end -> [something]

	// [something] -> [something]
	// _head->Next = nullptr;
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

	}

	return *this;
}

// 소멸자
ForwardList::~ForwardList()
{
	clear();

	delete _head;
	_head = nullptr;
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
	return nullptr;
}

ForwardList::const_iterator ForwardList::end() const
{
	return nullptr;
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
	Node* where = pos._p; // 매개변수로 받은 pos는 특정원소를 가리킴

	newNode->Next = where->Next;
	where->Next = newNode;

	return newNode;
}

ForwardList::iterator ForwardList::erase_after(const_iterator pos)
{
	// [] -> [] -> [] -> [*]
	//      where  removed 

	Node* where = pos._p;
	Node* removed = where->Next; // 여기서 removed는 삭제할 노드다.

	where->Next = removed->Next;
	// [] -> [] -> [*]
	//      where
	//          []
	//         removed
	delete removed;

	return where->Next;
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
	// if(begin() == end())
	if (_head->Next == nullptr)
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