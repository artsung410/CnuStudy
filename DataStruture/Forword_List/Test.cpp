#include <iostream>

#include <forward_list>
#include "ForwardList.h"

int main()
{
	std::forward_list<int> flist;
	ForwardList mylist;

	flist.push_front(1);
	mylist.push_front(1);

	std::cout << flist.front() << " " << mylist.front() << "\n";

	flist.push_front
}