#include "List.h"
#include <algorithm>

List::Node::Node(int data, Node* prev, Node* next)
	:Data(data), Prev(prev), Next(next)
{

}

List::const_iterator::const_iterator(Node* p)
	: _p(p)
{

}

List::const_iterator::~const_iterator()
{
	_p = nullptr;
}

// 반복자의 연산자 정의
const int& List::const_iterator::operator*() const
{
	return _p->Data;
}
const int* List::const_iterator::operator->() const
{
	return &(_p->Data);
}

List::const_iterator& List::const_iterator::operator++()
{
	_p = _p->Next;

	return *this;
}
List::const_iterator List::const_iterator::operator++(int)
{
	// 후이연산
	// 주소 움직이고
	// 그 전값을 반환?

	const_iterator temp = *this;
	_p = _p->Next;

	return temp;
}

List::const_iterator& List::const_iterator::operator--()
{
	_p = _p->Prev;

	return *this;
}

List::const_iterator List::const_iterator::operator--(int)
{
	const_iterator temp = *this;
	_p = _p->Prev;

	return temp;
}

bool List::const_iterator::operator==(const const_iterator& rhs) const
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

bool List::const_iterator::operator!=(const const_iterator& rhs) const
{
	return !(*this == rhs);
}

bool List::const_iterator::operator==(nullptr_t p) const
{
	if (nullptr == _p)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool List::const_iterator::operator!=(nullptr_t p) const
{
	return !(*this == _p);
}

int& List::iterator::operator*() const
{
	return const_cast<int&>(const_iterator::operator*());
}

int* List::iterator::operator->() const
{
	return const_cast<int*>(const_iterator::operator->());
}

List::iterator& List::iterator::operator++()
{
	const_iterator::operator++();

	return *this;
}

List::iterator List::iterator::operator++(int)
{
	iterator temp = *this;
	const_iterator::operator++();

	return temp;
}

List::iterator& List::iterator::operator--()
{
	const_iterator::operator--();

	return *this;
}

List::iterator List::iterator::operator--(int)
{
	iterator temp = *this;
	const_iterator::operator--();

	return temp;
}

// 기본생성자
List::List()
{
	_end->Next = _end;
	_end->Prev = _end;
}

// count
List::List(size_t count)
	: List()
{
	for (size_t i = 0; i < count; i++)
	{
		push_front(0);
	}
}

// 복사생성자
List::List(const List& other)
	: List()
{
	for (iterator iter = begin(); iter != end(); ++iter)
	{
		push_back(*iter);
	}
}

// 복사 할당연산자
List& List::operator=(const List& rhs)
{
	if (&rhs != this)
	{
		List temp(rhs);
		std::swap(_end, temp._end);
		std::swap(_size, temp._size);
	}

	return *this;
}

// 소멸자
List::~List()
{
	clear();

	delete _end;
	_end = nullptr;
}

// 첫번째 요소 반환
int& List::front()
{
	return *begin();
}
const int& List::front() const
{
	return *begin();
}

// 마지막 요소 반환
int& List::back()
{
	return *(--end());
}
const int& List::back() const
{
	return *(--end());
}

// 시작요소반복자반환
// 리스트비었다면 end와같다
List::iterator List::begin()
{
	return iterator(_end->Next);
}
List::const_iterator List::begin() const
{
	return const_iterator(_end->Next);
}

// 끝 다음요소를 가리키는 반복자 반환
List::iterator List::end()
{
	return _end;
}
List::const_iterator List::end() const
{
	return _end;
}

// pos 이전에 value를 삽입한다
// 삽입된 요소를 가리키는 반복자를 반환
List::iterator List::insert(iterator pos, int value)
{
	Node* insertBefore = pos._p;
	Node* insertAfter = pos._p->Prev;
	Node* newNode = new Node(value, insertBefore, insertBefore);

	insertAfter->Next = newNode;
	insertBefore->Prev = newNode;

	++_size;

	return newNode;

	/*Node* newNode = new Node;
	Node* where = new Node;
	where = pos._p;

	++_size;
	
	where->Prev = newNode->Next;
	newNode->Prev = where->Prev;

	newNode->Next = pos._p;*/
}

// pos위치의 요소를 삭제한다
// 삭제된 요소의 다음 요소를 가리키는 반복자를 반환
// 아무요소도 없으면 end() 반환
List::iterator List::erase(iterator pos)
{
	Node* erasePos = pos._p;
	Node* posFront = erasePos->Next;
	Node* posBefore = erasePos->Prev;

	posFront->Prev = posBefore;
	posBefore->Next = posFront;
	
	delete erasePos;

	--_size;

	return posBefore;	
}

// 시작에 value를 삽입한다
void List::push_front(int value)
{
	insert(begin(), value);
}

// 끝에 value를 삽입한다
void List::push_back(int value)
{
	insert(end(), value);
}

// 시작요소 제거
void List::pop_front()
{
	erase(begin());
}

// 끝요소 제거
void List::pop_back()
{
	erase(_end->Prev);
}

// 컨테이너 비었는지 확인
bool List::empty() const
{
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// 리스트안에있는 요소개수 반환
size_t List::size() const
{
	return _size;
}

// 컨테이너 비우기
void List::clear()
{
	while (false != empty())
	{
		pop_front();
	}
}

// 해당 value있는지 체크
bool List::contains(int value) const
{
	// 처음부터 끝까지 반복자를 순회한다
	for (const_iterator iter = begin(); iter != end(); ++iter)
	{
		// 해당 value가 나타나면 true반환
		if (*iter == value)
		{
			return true;
		}
	}

	return false;
}