#pragma once

class Stack
{
public:
    Stack(int size);
    ~Stack();

    // 스택에 value를 삽입합니다.
    // 다 찬 경우 아무것도 하지 않습니다.
    void Push(int value);

    // 스택에서 데이터를 꺼내고, 반환합니다.
    // 스택에 데이터가 없는 경우 -1를 반환합니다.
    int Pop();

    // 스택에 가장 위에 있는 데이터를 반환합니다.
    // 스택에 데이터가 없는 경우 -1를 반환합니다.
    int Top();

    // 스택이 비었다면 true, 아니면 false입니다.
    bool IsEmpty();

    // 현재 원소의 수를 반환한다.
    int Size();

private:
    int _top;
    int _arrSize;
    int* stack;
};