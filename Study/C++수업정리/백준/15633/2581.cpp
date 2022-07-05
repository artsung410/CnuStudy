#include <iostream>
#include <queue>
using namespace std;

int M, N;

int main()
{
	// 1. ют╥б

	cin >> M;
	cin >> N;

	int cnt = 0;
	int result = 0;

	queue<int> q;

	if (M != N)
	{
		for (int i = M + 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				if (i % j == 0)
				{
					++cnt;
				}
			}

			if (cnt == 1)
			{
				q.push(i);
				result += i;
			}
			cnt = 0;
		}
	}

	else
	{
		result += M;
		q.push(M);
	}


	if (!q.empty())
	{
		cout << result << "\n";
		cout << q.front();
	}
	else
	{
		cout << -1;
	}

	return 0;
}