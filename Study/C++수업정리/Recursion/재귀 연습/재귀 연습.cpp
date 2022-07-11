#include <iostream>

using namespace std;


void rec(int n)
{
    if (n > 5) return;

    cout << "n = " << n << "\n";
    rec(n + 1);
}

int main()
{
    rec(1);
}
