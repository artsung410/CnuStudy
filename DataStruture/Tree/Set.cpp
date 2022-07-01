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

