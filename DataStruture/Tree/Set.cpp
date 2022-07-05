#include "Set.h"

Set::Node::Node(int data, Node* parent, Node* left, Node* right)
	:Data(data), Parent(parent), Left(left), Right(right)
{

}

Set::Node::~Node()
{
	Parent = nullptr;
	Left = nullptr;
	Right = nullptr;
}

bool Set::Node::IsLeaf() const
{
	// 자식노드가 없다면 true
	if (Left == nullptr && Right == nullptr) // 오, 왼 둘다 없으면 자식노드가 없다
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Set::empty() const
{
	// 비었다면 true
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

size_t Set::size() const
{
	return _size;
}

std::pair<Set::Node*, bool> Set::insert(int value)
{
	if (empty())
	{
		_root = new Node(value);
		++_size;

		return std::make_pair(_root, true);
	}

	// 집합이란 무엇인가

	// 이진검색트리 - 왼쪽 서브트리는 본인보다 작은 값, 오른쪽 서브트리는 큰 값.
	// 비교해서 삽입 위치를 구분해야한다.
	// 이진검색트리를 이용해서 본인의 삽입될 위치를 찾아간다.
	Node* currentNode = _root;
	Node* prevNode = nullptr;

	while (currentNode)
	{
		prevNode = currentNode;

		// 이진검색 수행하기
		// 같은 값이라면 해당 값을 가리키는 노드와 false 반환

		if (currentNode->Data == value)
		{
			return std::make_pair(currentNode, false);
		}
		else if (currentNode->Data < value)
		{
			currentNode = currentNode->Right;
		}
		else
		{
			currentNode = currentNode->Left;
		}
		
	}

	currentNode = new Node(value, prevNode);

	// currentNode를 prevNode에 왼쪽자식으로 삽입할건지 오른쪽자식으로 삽입할건지
	if (prevNode->Data < value)
	{
		prevNode->Right = currentNode;
	}
	else
	{
		prevNode->Left = currentNode;
	}

	++_size;
}

void Set::erase(Node* pos)
{
	// 1. pos가 루트노드라면?
	// 루트노드? 부모가 없다. 즉, 부모가 널포인트
	if (pos->Parent == nullptr)
	{
		// 자식이 없다면
		if (pos->IsLeaf())
		{
			_root = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// 왼쪽 자식만 있다면
		if (pos->Right == nullptr)
		{
			// 왼쪽 자식을 루트로 만든다
			_root = pos->Left;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// 오른쪽 자식만 있다면
		if (pos->Left == nullptr)
		{
			_root = pos->Right;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// 둘다 있다면
		// 리프노드 중에서 가장 비슷한값이 새로운 부모노드가 된다.
		// 왼쪽 서브트리의 최대값, 오른쪽 서브트리의 최소값
		
	}

	// 2. pos가 리프 노드라면?

	// 3. pos가 왼쪽 자식만 있다면?

	// 4. pos가 오른쪽 자식만 있다면?

	// 5. pos가 자식을 둘 다 가지고 있다면?
}

size_t Set::erase(int value)
{

}