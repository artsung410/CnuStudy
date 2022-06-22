#pragma once

#include <stddef.h>

class ForwardList
{
public:
	// 연결리스트에서 데이터를 저장하기 위한 타입
	// 연결리스트는 데이터를 직접다루지않고 노드 라는 것으로 다룬다.
	struct Node
	{
		Node(int data = 0, Node* next = nullptr);
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node();

		int		data = 0;
		Node*	Next = nullptr;

	}; // 노드는 외부에 공개하지 않음

public:

	// 기본생성자
	ForwardList();

	// 명시적변환, count만큼 요소를 갖고있는 컨테이너를 만드는 생성자
	// 메인함수에서 잘못쓰였을때 빨간줄뜨게만듬
	explicit ForwardList(size_t count);

	// 복사생성자
	ForwardList(const ForwardList& other);

	// 할당연산자
	ForwardList& operator=(const ForwardList& rhs);

	// 소멸자
	~ForwardList();

	// 첫번째 요소 반환
	int& front();
	const int& front() const;

	// 시작전 요소를 가리키는 포인터를 반환
	Node* before_begin();
	const Node* before_begin() const;

	// 시작 요소를 가리키는 포인터 반환
	Node* begin();
	const Node* begin() const;

	// 끝 다음 요소를 가리키는 포인터 반환
	Node* end();
	const Node* end() const;

	// pos다음에 value를 삽입
	// 삽입된 요소를 가리키는 포인터 반환
	Node* insert_after(const Node* pos, int value);

	// pos다음요소 삭제
	// 삭제된 요소의 다음 요소를 가리키는 포인터반환
	// 아무 요소도 없으면 end반환
	Node* erase_after(const Node* pos);

	// 시작요소에 value삽입
	void push_front(int value);

	// 시작요소 제거
	void pop_front();

	// 컨테이너 비었는지 판단
	bool empty() const;

	// 컨테이너 비움
	void clear();

	// value가 있는지 검사
	bool contains(int value) const;

private:
	Node* _head = new Node();

	Node* _end = new Node();
};