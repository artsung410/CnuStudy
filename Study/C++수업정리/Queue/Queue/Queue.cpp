#include "myQueue.h"
#include  <iostream>

int MyQueue::_front()
{
	return front->data;
}

int MyQueue::_back()
{
	return rear->data;
}

int MyQueue::size()
{
	return count;
}

bool MyQueue::isEmpty()
{
	if (count == 0) { return true; }
	else { return false; }
}


void MyQueue::enqueue(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = nullptr;

	if (isEmpty())
	{
		front = newNode;
	}
	else
	{
		rear->next = newNode;
	}

	rear = newNode;
	count++;
}

int MyQueue::dequeue()
{
	int data;
	Node* pick;

	if (isEmpty())
	{
		std::cout << "Error!" << " / result : ";
		return 0;
	}

	pick = front;
	data = pick->data;
	front = pick->next;
	delete pick;
	count--;

	return data;
}