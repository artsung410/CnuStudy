#include <iostream>

using namespace std;

int main()
{
	float myBodyHeat = 36.5;

	float* pH = &myBodyHeat;

	cout << *pH << endl;
}