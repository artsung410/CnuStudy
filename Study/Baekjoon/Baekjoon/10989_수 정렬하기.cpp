#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int digitCount[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int inputNum;
		cin >> inputNum;
		digitCount[inputNum] += 1;
	}

	for (int i = 0; i < 10001; i++)
	{
		if (digitCount[i] > 0)
		{
			int cycle = digitCount[i];
			for (int j = 0; j < cycle; j++)
			{
				cout << i << '\n';
			}
		}
	}


	return 0;
}