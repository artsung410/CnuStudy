#include <queue> // std::queue를 사용하기 위한 헤더
#include <iostream>

int main()
{
    std::queue<int> q;

    // 삽입
    for (int i = 1; i <= 5; ++i)
    {
        q.push(i);
    }
    // q { 1, 2, 3, 4, 5 }

    // 삭제
    q.pop();
    // q { 2, 3, 4, 5 }

    // 읽기
    std::cout << "q.front() : " << q.front() << "\n";
    std::cout << "q.back() : " << q.back() << "\n";

    // 크기
    if (q.empty())
    {
        std::cout << "q is empty\n";
    }
    std::cout << "q.size() : " << q.size() << "\n";
}
