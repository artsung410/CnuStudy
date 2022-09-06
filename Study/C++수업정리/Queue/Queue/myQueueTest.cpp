#include <iostream>

#include "myQueue.h"

using namespace std;
MyQueue q;

int main()
{
	q.enqueue(1);
	q.enqueue(3);
	q.enqueue(5);
	q.enqueue(7);
	q.enqueue(9);


	cout << "맨 앞 원소 : " << q._front() << endl;
	cout << "맨 뒤 원소 : " << q._back() << endl;
	cout << "사이즈 : " << q.size() << endl;

	while(!q.isEmpty())
	{
		cout << q.dequeue() << " ";
	}
	cout << "\n";
	cout << q.dequeue();

	return 0;
}

