#include "Set.h"
#include <iostream>
#include <queue>

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

Set::~Set()
{
	clear();

	delete _head;
	_head = nullptr;
}


// 트리의 높이
int Set::height() const // 큐 사용(BFS)
{
	std::queue<Node*> q;
	if (_head->Parent)
	{
		q.push(_head->Parent);
	}

	int height = 0;
	while (false == q.empty())
	{
		int size = q.size();
		for (int i = 0; i < size; i++)
		{
			Node* node = q.front();
			q.pop();

			if (node->Left)
			{
				q.push(node->Left);
			}
			if (node->Right)
			{
				q.push(node->Right);
			}
		}

		++height;
	}
	return height;
}
int Set::height2() const // 재귀 사용
{
	if (_head->Parent == nullptr)
	{
		return -1;
	}

	return heightHelper(_head->Parent);
}
int Set::heightHelper(Node* node) const 
{
	int height = 0;
	// 전체높이 = 서브트리의 레벨 + 1;
	if (node->Left)
	{
		height = 1 + heightHelper(node->Left);
	}

	if (node->Right)
	{
		height = std::max(height, 1 + heightHelper(node->Right));
	}

	return height;
}

// 트리 비었는지 확인
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

// 트리 크기 반환
size_t Set::size() const
{
	return _size;
}

// 트리 비우기
void Set::clear()
{
	// 루트노드를 비워줌
	while (false == empty())
	{
		erase(_head->Parent);
	}
	return;
}

// 트리에 값 삽입
// 들어가면 true 안됬다면 false
bool Set::insert(int value)
{
	// 새로운노드 생성
	Node* newNode = new Node(value);

	// 루트노드가 없다면? 생성해줘야한다.
	// 1. 루트노드 설정
	if (_head->Parent == nullptr)
	{
		// 서로 엮어줌
		_head->Parent = newNode;
		newNode->Parent = _head;

		++_size;

		return true;
	}

	// 삽입될 노드의 부모를 알아야 연결할수있다.
	// 2. 삽입될 위치의 부모 노드 찾음
	Node* parent = nullptr;
	Node* p = _head->Parent; // p를 이용해 움직임

	while (p)
	{
		parent = p;

		if (p->Data == value)
		{
			return false;
		}
		else if (value < p->Data)
		{
			p = p->Left;
		}
		else
		{
			p = p->Right;
		}
	}

	// 3. 새로운 노드 삽입
	if (value < parent->Data)
	{
		parent->Left = newNode;
	}
	else
	{
		parent->Right = newNode;
	}
	newNode->Parent = parent;

	++_size;

	return true;
}

// 트리에 값 삭제
void Set::erase(int value)
{
	// value가 위치한 노드찾음
	Node* removedNode = find(value);
	if (removedNode == nullptr)
	{
		return;
	}

	// erase(pos)
	erase(removedNode);
}

void Set::erase(Node* pos)
{
	// 5 자식이 둘다 있을때
	if (pos->Left && pos->Right)
	{
		// 후속 노드를 지정해야함
		Node* successor = nullptr;
		// 오른쪽으로한번가서
		successor = pos->Right;
		// 왼쪽으로 쭉!
		while (successor->Left)
		{
			successor = successor->Left;
		}
		// 후속 노드의 데이터를 덮어쓴다
		pos->Data = successor->Data;

		// 후속노드 삭제
		erase(successor);

		return;
	}

	// 1 자식이 한쪽만 있을때 || 둘다 없다면
		// 내 부모에다가 내 자식(있던지 || nullptr)을 연결해준다
		// 내가 과연 부모의 왼쪽에 있을까? 오른쪽에 있을까?
	Node** child = nullptr;
	// pos가 루트노드라면?
	if (pos == _head->Parent)
	{
		child = &_head->Parent;
	}
	// 지우고자하는 노드가 루트노드의 자식인경우 || 내가 오른쪽에 위치한경우
	else if (pos->Data < pos->Parent->Data)
	{
		child = &pos->Parent->Left;
	}
	// 내가 왼쪽에 위치한경우
	else
	{
		child = &pos->Parent->Right;
	}

	// 부모에 내 자식을 연결한다
	*child = nullptr;
	if (pos->Left)
	{
		*child = pos->Left;
		pos->Left->Parent = pos->Parent;
	}
	else if(pos->Right)
	{
		*child = pos->Right;
		pos->Right->Parent = pos->Parent;
	}
	
	delete pos;
	--_size;
}

// 트리에서 값 찾는다
Set::Node* Set::find(int value)	const
{
	Node* result = _head->Parent;

	while (result)
	{
		if (result->Data == value)
		{
			break;
		}
		else if(result->Data < value)
		{
			result = result->Right;
		}
		else
		{
			result = result->Left;
		}
	}

	return result;
}

// 전위순회 헬퍼
void Set::traverseByPreorderHelper(Node* node) const
{
	if (node == nullptr)
	{
		return;
	}
	std::cout << node->Data << "->";
	traverseByPreorderHelper(node->Left);
	traverseByPreorderHelper(node->Right);
}
// 나 자신먼저 방문: 전위순회
void Set::traverseByPreorder() const
{
	traverseByPreorderHelper(_head->Parent);
}

// 중위순회 헬퍼
void Set::traverseByInorderHelper(Node* node) const
{
	// 왼 -> 자기자신 -> 오

	if (node == nullptr)
	{
		return;
	}
	traverseByInorderHelper(node->Left);
	std::cout << node->Data << "->";
	traverseByInorderHelper(node->Right);
}
// 중위순회
void Set::traverseByInorder() const
{
	traverseByInorderHelper(_head->Parent);
}

// 후위순회 헬퍼
void Set::traverseByPostorderHelper(Node* node) const
{
	// 왼 -> 오 -> 자기자신

	if (node == nullptr)
	{
		return;
	}
	traverseByPostorderHelper(node->Left);
	traverseByPostorderHelper(node->Right);
	std::cout << node->Data << "->";
}
// 후위순회
void Set::traverseByPostorder() const
{
	traverseByPostorderHelper(_head->Parent);
}

// 레벨순회 (DFS)
void Set::traverseByLevelorder() const
{
	std::queue<Node*> que;
	if (_head->Parent)
	{
		que.push(_head->Parent);
	}

	while (que.empty() == false)
	{
		Node* node = que.front();
		que.pop();

		std::cout << node->Data << "->";

		if (node->Left)
		{
			que.push(node->Left);
		}

		if (node->Right)
		{
			que.push(node->Right);
		}
	}

}





