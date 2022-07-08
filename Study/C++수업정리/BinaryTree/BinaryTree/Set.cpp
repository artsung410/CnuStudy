#include "Set.h"
#include <iostream>
#include <queue>

Set::Node::Node(int data, Node* parent, Node* left, Node* right)
    : Data(data), Parent(parent), Left(left), Right(right)
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

int Set::height() const
{
    std::queue<Node*> q;
    if (_head->Parent)
    {
        q.push(_head->Parent);
    }

    int height = -1;
    while (false == q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; ++i)
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

            ++height;
        }
    }

}

int Set::height2() const
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

void Set::clear()
{
    while (false == empty())
    {
        erase(_head->Parent);
    }
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


void Set::erase(int value)
{
    // 1. value가 위치한 노드를 찾음
    
    Node* removeNode = find(value);

    if (removeNode == nullptr)
    {
        return;
    }

    // 2. erase(pos);
    erase(removeNode);
}


void Set::erase(Node* pos)
{
    // 1. 자식이 둘다 있을 때 (왕위 계승)
    if (pos->Left && pos->Right)
    {
        // 1-1. 후속 노드를 지정해야 함.
        Node* successor = pos->Right;

        // 왼쪽값이 0(nullptr)을 반환할때까지 반복.
        while (successor->Left)
        {
            successor = successor->Left;
        }

        // 1-2. 후속 노드의 데이터와 덮어쓴다.
        pos->Data = successor->Data;

        // 1-3. 후속 노드를 지운다.
        erase(successor);

        return;
    }


    // 2. 자식이 한 쪽만 있을 때
    // 2-1. 내 부모에 왼쪽에 위치하는지, 오른쪽에 위치하는지 파악한다.
    Node** child = nullptr;

    if (pos == _head->Parent)
    {
        child = &_head->Parent;
    }

    // 2-1-2. 내가 왼쪽인 경우
    else if (pos->Data < pos->Parent->Data)
    {
        child = &pos->Parent->Left;
    }

    // 2-1-3. 내가 왼쪽에 위치한 경우
    else
    {
        child = &pos->Parent->Right;
    }

    // 2-2. 부모에 내 자식을 연결한다.
    *child = nullptr;

    if (pos->Left)
    {
        *child = pos->Left;
        pos->Left->Parent = pos->Parent;
    }

    else if (pos->Right)
    {
        *child = pos->Right;
        pos->Right->Parent = pos->Parent;
    }

    delete pos;
    pos = nullptr;

    --_size;


    // 3. 둘 다 없을 때

    // 4. pos가 루트 노드일 때
    //      4 - 1. 왼쪽 자식만 있을 때
    //      4 - 2. 오른쪽 자식만 있을 때
    //      4 - 3. 둘다 있을 때
    // 
    // 5. 자식이 둘다 있을 때
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


