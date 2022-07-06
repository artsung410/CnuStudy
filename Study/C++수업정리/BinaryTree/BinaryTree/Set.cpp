#include "Set.h"
#include <iostream>
#include <queue>

Set::Node::Node(int data, Node* parent, Node* left, Node* right)
    : Data(data), Parent(parent), Left(left), Right(right)
{
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

bool Set::insert(int value)
{

    // 1. 새 노드 생성
    Node* newNode = new Node(value);

    // 2. 루트 노드가 없을 경우 루트 노드 설정
    if (_head->Parent == nullptr)
    {
        _head->Parent = newNode;
        newNode->Parent = _head;
        ++_size;
        return true;
    }

    // 3. 삽입될 위치의 부모 노드 찾음.
    Node* parent = nullptr;
    Node* p = _head->Parent;

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

    // 4. 새로운 노드 삽입
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


Set::Node* Set::find(int value) const
{
    Node* result = _head->Parent;
    while (result)
    {
        if (result->Data == value)
        {
            break;
        }
        else if (result->Data < value)
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

void Set::traverseByPreorder() const
{
    traverseByPreorderHelper(_head->Parent);
}

void Set::traverseByInorder() const
{
    traverseByInorderHelper(_head->Parent);
}

void Set::traverseByPostorder() const
{
    traverseByPostorderHelper(_head->Parent);
}

void Set::traverseByLevelorder() const
{
    std::queue<Node*> q;
    if (_head->Parent)
    {
        q.push(_head->Parent);
    }
    while (false == q.empty())
    {
        Node* node = q.front();
        q.pop();
        std::cout << node->Data << "->";
        if (node->Left)
        {
            q.push(node->Left);
        }

        if (node->Right)
        {
            q.push(node->Right);
        }
    }
}

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

void Set::traverseByInorderHelper(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }
    traverseByInorderHelper(node->Left);
    std::cout << node->Data << "->";
    traverseByInorderHelper(node->Right);
}

void Set::traverseByPostorderHelper(Node* node) const
{
    if (node == nullptr)
    {
        return;
    }
    traverseByPostorderHelper(node->Left);
    traverseByPostorderHelper(node->Right);
    std::cout << node->Data << "->";
}