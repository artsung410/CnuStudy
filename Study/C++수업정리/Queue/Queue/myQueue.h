#pragma once

struct Node
{
	int data;
	Node* next;
};

class MyQueue
{
public:

	// 기본 생성자
	MyQueue() = default;

	// 소멸자
	~MyQueue() {};

	// 가장 먼저 노드를 저으이하고, Queue 구조체를 정의한다. 큐를 초기화 하는 initQueue()함수를 이용해 front와 rear를 null로 초기화

	int _front();

	int _back();

	int size();

	bool isEmpty();

	void enqueue(int data);

	int dequeue();

private:
	Node* front = nullptr;
	Node* rear = nullptr;
	int count = 0;

	size_t	_size = 0;
};