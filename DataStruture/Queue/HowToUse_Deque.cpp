#include <deque> // std::deque를 사용하기 위한 헤더
#include <iostream>

int main()
{
    std::deque<int> dq;

    // 삽입
    dq.push_front(1); // dq{ 1 }
    dq.push_back(2); // dq{ 1, 2 }
    dq.insert(dq.begin() + 1, 3); // dq{ 1, 3, 2 }

    // 반복자
    std::deque<int>::iterator iter;
    iter = dq.begin();  // [*1][3][2][]
    iter = dq.end();    // [1][3][2][*]
    std::deque<int>::reverse_iterator riter;
    riter = dq.rbegin(); // [][1][3][*2]
    riter = dq.rend();   // [*][1][3][2]

    // 삭제
    dq.pop_front();         // dq{ 3, 2 }
    dq.pop_back();          // dq{ 3 }
    dq.erase(dq.begin());   // dq{ }

    // 아래처럼 초기화도 가능하다.
    std::deque<int> dq2 = { 1, 2, 3, 4, 5 };

    // 읽기
    std::cout << "dq2.front() : " << dq2.front() << "\n"; // 1
    std::cout << "dq2.back() : " << dq2.back() << "\n"; // 5
    std::cout << "dq2[2] : " << dq2[2] << "\n"; // 3

    // 크기
    std::cout << "dq2.size() : " << dq2.size() << "\n"; // 5

    // 비우기
    dq2.clear();
    if (dq2.empty())
    {
        std::cout << "dq2 is empty\n";
    }

    // C++17.부터는 원소의 타입 추론 가능
    std::deque dq3 = { 1, 2, 3 }; // deque<int>
}

