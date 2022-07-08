#include <iostream>

using namespace std;

int n;
int arr[1000] = { 0 };

int main()
{
	cin >> n;

	int a;
	int temp;
	int hanNumCount = 0;

	if (n != 1)
	{
		for (int i = 1; i <= n; i++)
		{
			a = i;
			temp = a;
			int cnt = 0;
			while (a != 0)
			{
				arr[cnt] = a % 10;
				a /= 10;
				++cnt;
			}

			if (i != 1000 && i >= 100 && (arr[1] - arr[0]) == (arr[2] - arr[1]) || i < 100)
			{
				++hanNumCount;
			}
		}
	}
	else
	{
		++hanNumCount;
	}

	cout << hanNumCount << endl;

	return 0;
}