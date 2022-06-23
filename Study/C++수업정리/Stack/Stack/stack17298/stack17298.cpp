#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    std::stack<int> s1; // 조건에 따라 담는 스택
    std::stack<int> s2; // 인덱스 담는 스택

    int length;

    // 1. 입력
    cin >> length;
    int* SeqArray = new int[length]; // 배열 초기화

    int stackNum = 0; // 받을 숫자 초기화
    for (int i = 0; i < length; i++)
    {
        SeqArray[i] = -1;

        cin >> stackNum; // 넘버를 입력받는다.

        if (i == 0)
        {
            s1.push(stackNum);
            s2.push(i);
        }

        // 현재 최상단에 있는 스택이 들어오는 값보다 컸을때

        if (s1.top() > stackNum)
        {
            s1.push(stackNum);
            s2.push(i);
        }

        else if (s1.top() <= stackNum)
        {
            while (!s1.empty() && s1.top() < stackNum)
            {
                SeqArray[s2.top()] = stackNum;
                s1.pop();
                s2.pop();
            }

            s1.push(stackNum);
            s2.push(i);
        }

    }

    // 3. 출력
    for (int i = 0; i < length; i++)
    {
        cout << SeqArray[i] << ' ';
    }


    // 4. 메모리 해제
    while (!s1.empty())
    {
        s1.pop();
        s2.pop();
    }

    delete[] SeqArray;

    return 0;
}