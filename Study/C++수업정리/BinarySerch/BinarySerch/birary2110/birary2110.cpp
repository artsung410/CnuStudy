#include <iostream>
#include <algorithm>
#define MAXNUM 10000

using namespace std;


int pos[MAXNUM];

int main()
{
	// 집 개수, // 공유기 개수 입력받기.

	int N, C;
	cin >> N >> C;

	// 집 거리 담기.
	for (int i = 0; i < N; i++)
	{
		cin >> pos[i];
	}

	std::sort(pos, pos + N);

	// 4. 이진검색을 할 범위는 가장 인접한 공유기 사이의 거리 => [1, X[n - 1]]
	int s = 1, e = pos[N - 1] + 1;
	int answer = 0;


	while (s < e)
	{
		// 4-1. 중앙값을 해의 후보로 정한다.
		// s : 1, e : 10, m : 5
		int m = (s + e) / 2;

		// 4-2. 실제로 m 거리만큼 떨어뜨렸을 때, 몇개의 공유기가 필요한지 계산한다.
		int count = 0;

		if (count < C)
			e = m;

		else
		{
			if (answer < m)
				answer = m;

			// 4-4. 더 찾을 수 있는지 범위 조절
			s = m + 1;
		}
	}

	// 5. 최대 거리를 출력한다.
	cout << answer;
}
