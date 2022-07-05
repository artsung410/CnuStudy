/*
ÆÑÅä¸®¾ó

1! = 1
2! = 2 1
3! = 3 2!;
4! = 4 3!
5! = 5 4!
*/

#include <iostream>

using namespace std;

int Factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}

	return n * Factorial(n - 1);
}

int main()
{
	int N;
	cin >> N;

	cout << Factorial(N);
}