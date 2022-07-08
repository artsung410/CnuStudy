#include "Stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int size) 
{
    _arrSize = size;
    stack = new int[_arrSize];
    _top = -1;
}

Stack::~Stack()
{
    delete[] stack;
}

bool Stack::IsEmpty()
{
    if (_top == -1)
    {
        return true;
    }

    else
    {
        return false;
    }
}

int Stack::Pop() 
{
    if (IsEmpty() == true)
    {
        return _arrSize;
    }
    else
    {
        return stack[_top--];
    }
}

void Stack::Push(int value) 
{
    if (Size() == _arrSize)
    {
        return;
    }
    else
    {
        ++_top;
        stack[_top] = value;
    }
}

int Stack::Top()
{
    if (IsEmpty() == true)
    {
        return -1;
    }
    else
    {
        return stack[_top];
    }

}

int Stack::Size()
{
    return _top + 1;
}