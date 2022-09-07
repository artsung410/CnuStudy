#include "Heap.h"
#include <iostream>

#include <queue>

int main()
{
	Heap heap;

	for (int num : {7, 4, 11, 1, 0, 27, 31, 12, 5, 6})
	{
		heap.push(num);
	}

	while (heap.size())
	{
		std::cout << heap.top() << " ";
		heap.pop();
	}
	return 0;
}