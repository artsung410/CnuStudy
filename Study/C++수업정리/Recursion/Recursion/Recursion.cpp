#include <iostream>

using namespace std;

int fibo(int n)
{
    // 종료 조건
    if (n < 3)
    {
        return 1;
    }

    else
    {
        // 피보나치 수열은 앞의 두항의 합이 현재의 항의 값이 되는
        return fibo(n - 1) + fibo(n - 2);
    }
}
int main()
{
    cout << fibo(7);
}
