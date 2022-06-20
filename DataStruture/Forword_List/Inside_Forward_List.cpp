#include <forward_list> // std::forward_list를 쓰기 위한 헤더
#include <iostream>

int main()
{
    std::forward_list<int> flist;

    // 삽입
    flist.push_front(1); // push_front() : 맨 앞에 삽입한다.
    // flist{ 1 }
    flist.insert_after(flist.begin(), 2); // insert_after(pos, value) : pos 뒤에 value를 삽입한다.
    // flist{ 1, 2 }
    flist.push_front(3); // flist { 3, 1, 2 }

    // 반복자
    std::forward_list<int>::iterator iter;
    iter = flist.before_begin(); // begin의 이전? 임시로 하나 dummy node를 둠 왜? 구현의 편함을 위해
    // [ ]->[3]->[1]->[2]->[ ]
    //  ↑
    iter = flist.begin();
    // [ ]->[3]->[1]->[2]->[ ]
    //       ↑
    iter = flist.end();
    // [ ]->[3]->[1]->[2]->[ ]
    //                      ↑

    // 삭제
    flist.pop_front(); // pop_front() : 첫 번째 원소를 삭제한다.
    // flist{ 1, 2 };
    flist.erase_after(flist.begin()); // erase_after(pos) : pos 다음 원소를 삭제한다.
    // flist{ 1 }
    flist.clear(); // clear() : 컨테이너를 전부 비운다.
    // flist{ }

    // 크기
    if (flist.empty()) // empty() : 비었는지 확인한다.
    {
        std::cout << "flist는 비었음.\n";
    }
    // 주의! 다른 컨테이너와 다르게 size()는 없음

    // 아래처럼 초기화 가능
    std::forward_list<int> flist2 = { 1, 2, 3, 4, 5 };

    // 읽기
    std::cout << "flist2.front() : " << flist2.front() << "\n"; // front() : 첫 번째 원소를 반환한다.

    // 비교 : 다른 컨테이너와 마찬가지로 == / != / > / >= / < / <= 지원
    flist = flist2;
    if (flist == flist2)
    {
        std::cout << "flist는 flist2와 같다.\n";
    }

    // C++17부터는 원소 타입을 적지 않아도 알아서 추론한다.
    std::forward_list flist3 = { 1, 2, 3, 4, 5 };

    return 0;
}
