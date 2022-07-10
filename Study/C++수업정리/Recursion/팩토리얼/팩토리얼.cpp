#include <iostream>

//팩토리얼
// 5! = 5 * 4 * 3 * 2 * 1 = 120

// n! = n * (n-1)!


// 재귀함수란 종료조건이 참이 될때까지 스스로를 계속 반복하는 함수

// 
using namespace std;

int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    cout << factorial(6) << "\n";
}
