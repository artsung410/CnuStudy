#include <iostream>
#include <queue>
using namespace std;

int M, N;

int main()
{
	// 1. 입력

	cin >> M;
	cin >> N;

	int cnt = 0;
	int result = 0;

	queue<int> q;

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

	cout << result << "\n";
	cout << q.front();
	// 범위안에 소수의 합을 구한다.

	// 범위안에 소수의 최소값을 구한다.
	return 0;
}