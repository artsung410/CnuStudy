#include <stack> // std::stack을 위한 헤더
#include <iostream>
#include <vector>
#include <forward_list>
#include <list>

int main()
{
    std::stack<int> s;

    std::vector<int> st;
    //std.pp
    //// 삽입
    //for (int i = 1; i <= 5; ++i)
    //{
    //    s.push(i); // push() : 스택에 데이터를 삽입한다.
    //}
    // s { 5, 4, 3, 2, 1 }

    // 컨테이너 어댑터는 반복자가 존재하지 않는다.
    //  => 순회 용도로 사용하지 않기 때문이다.

    // 삭제
    s.pop(); // pop() : 스택의 위에서 값을 꺼낸다.
    // s { 4, 3, 2, 1 }

    // 읽기
    std::cout << "stack.top() : " << s.top() << "\n";
    // top() : 가장 마지막으로 삽입된 원소를 가져온다.

    // 크기
    if (s.empty())
    {
        std::cout << "stack is empty\n";
    }
    std::cout << "stack.size() : " s.size() << "\n";
    // size() : 현재 원소의 개수를 반환한다.
}

