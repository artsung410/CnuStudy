#include <list> // std::list를 쓰기 위한 헤더
#include <iostream>

int main()
{
    std::list<int> list;

    // 삽입
    list.push_front(1); // push_front() : 맨 앞에 삽입한다.
    // list{ 1 }
    list.push_back(2); // push_back() : 맨 뒤에 삽입한다.
    // list{ 1, 2 }
    list.insert(list.begin(), 9); // insert(pos, value) : pos 전에 value를 삽입한다.
    // list{ 9, 1, 2 }
    list.push_back(5); // list{ 9, 1, 2, 5 }

    // 반복자
    std::list<int>::iterator iter;
    iter = list.begin();
    // [9]<->[1]<->[2]<->[5]<->[ ]
    //  ↑
    iter = list.end();
    // [9]<->[1]<->[2]<->[5]<->[ ]
    //                          ↑
    std::list<int>::reverse_iterator riter;
    riter = list.rbegin();
    // [ ]<->[9]<->[1]<->[2]<->[5]
    //                          ↑
    riter = list.rend();
    // [ ]<->[9]<->[1]<->[2]<->[5]
    //  ↑

    // 삭제
    list.pop_front(); // pop_front() : 첫 번째 원소를 삭제한다.
    // list{ 1, 2, 5 };
    list.pop_back(); // pop_back() : 마지막 원소 삭제한다.
    // list{ 1, 2 };
    list.erase(list.begin()); // erase(pos) : pos를 삭제한다.
    list.clear(); // clear() : 컨테이너를 전부 비운다.
    // list{ }

    // 크기
    if (list.empty()) // empty() : 비었는지 확인한다.
    {
        std::cout << "list는 비었음.\n";
    }
    std::cout << "list.size() : " << list.size() << "\n"; // list는 size존재

    // 아래처럼 초기화 가능
    std::list<int> list2 = { 1, 2, 3, 4, 5 };

    // 읽기
    std::cout << "list2.front() : " << list2.front() << "\n"; // front() : 첫 번째 원소를 반환한다.
    std::cout << "list2.back() : " << list2.back() << "\n"; // back() : 마지막 원소를 반환한다.

    // 비교 : 다른 컨테이너와 마찬가지로 == / != / > / >= / < / <= 지원
    list = list2;
    if (list == list2)
    {
        std::cout << "flist는 flist2와 같다.\n";
    }

    // C++17부터는 원소 타입을 적지 않아도 알아서 추론한다.
    std::list list3 = { 1, 2, 3, 4, 5 };

    return 0;
}
