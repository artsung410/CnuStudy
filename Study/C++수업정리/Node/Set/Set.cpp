#include "Set.h"

Set::Node::Node(int data, Node* parent, Node* left, Node* right) : Data(data), Parent(parent), Left(left), Right(right)
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
	if (Left == nullptr && Right == nullptr)
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

	// 이진 검색 트리 : 왼쪽 서브 트리는 자기보다 작은 값, 오른쪽 서브 트리는 자기보다 큰값.

	Node* currentNode = _root;
	Node* prevNode = nullptr;

	while (currentNode)
	{
		prevNode = currentNode;
		
		// 이진 검색 수행. 

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


	// currnetNode를 prevNode에 왼쪽 자식으로 삽입할 건지 오른쪽 자식으로 삽입할 건지?

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
	// 1. pos가 루트 노드라면?
	if (pos->Parent == nullptr)
	{
		//1 .자식이 없다면?
		if (pos->IsLeaf())
		{
			_root = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		//2 .왼쪽 자식만 있다면?
		if (pos->Right == nullptr)
		{
			_root = pos->Left;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		//3 .오른쪽 자식만 있다면?
		if (pos->Left == nullptr)
		{
			_root = pos->Right;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		// 4. 둘다 있다면?
		if (pos->Left == nullptr)
		{
			_root = pos->Right;
			_root->Parent = nullptr;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}
	}

	// 2. pos가 리프 노드라면?


	// 3. pos가 왼쪽 자식만 있다면?


	// 4. pos가 오른쪽 자식만 있다면?


	// 5. pos가 자식을 둘 다 가지고 있다면?



}





