#include <iostream>

using namespace std;

int main() 
{
    bool check[10001] = { 0 };
    int sum;
    int a;
    for (int i = 1; i < 10001; i++) 
    {
        sum = 0;
        a = i;
        while (a != 0)
        {
            sum += a % 10; 
            a /= 10;
        }
        if (i + sum < 10001) 
        {
           
            check[i + sum] = true;
        }
    }
    for (int i = 1; i < 10001; i++) 
    {
        if (!check[i]) 
        { 
            cout << i << '\n';
        }
    }
    return 0;
} 