#include <iostream>

using namespace std;

int main()
{
	srand(time(NULL));
	cout << "max : ";
	int maxN;
	cin >> maxN;

	cout << "min : ";
	int minN;
	cin >> minN;

	for (int i = 0; i < 2; i++)
	{
		int ranNum = minN + rand() % (maxN - minN + 1);
		cout << ranNum << " " << endl;
	}
}