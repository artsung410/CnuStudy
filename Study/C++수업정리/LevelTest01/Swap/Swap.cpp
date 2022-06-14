#include <iostream>

using namespace std;

void Swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10, b = 20;

	cout << "바뀌기 이전 : " << a << ", " << b << "\n";
	Swap(&a, &b);
	cout << "바뀐 후 : " << a << ", " << b << "\n";
	Swap(a, b);
	cout << "바뀐 후 : " << a << ", " << b << "\n";

	return 0;
}
