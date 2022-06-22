#include <forward_list> // std::forward_list를 쓰기 위한 헤더
#include <iostream>
#include "ForwardList_iterator.h"

using namespace std;

int main()
{
    ForwardList list;
    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    for (ForwardList::iterator cursor = list.begin(); cursor != list.end(); ++cursor)
    {
        std::cout << *cursor;
    }

    return 0;
}
