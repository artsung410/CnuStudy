#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[25][25];
int N;

int dfs(int y, int x)
{
	map[y][x] = '0'; // 첫 방문지점을 0으로 만들어서 방문기록.

	static int dx[4] = { 1, 0, -1, 0 }; // 서쪽, 북쪽, 동쪽, 남쪽 체크할 룩업테이블 생성
	static int dy[4] = { 0,-1, 0, 1 };

	int cnt = 1;
	for (int i = 0; i < 4; i++)
	{
		int newX = x + dx[i];
		int newY = y + dy[i];

		// 범위 벗어나는거 방지.
		if (newY < 0 || newY >= N || newX < 0 || newX >= N)
		{
			continue;
		}

		if (map[newY][newX] == '1')
		{
			cnt += dfs(newY, newX);
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N; 

	int size = 0;
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		size = s.size();

		for (int j = 0; j < size; j++)
		{
			map[i][j] = s[j];
		}
	}

	int dangiCount = 0;
	vector<int> houseCount;

	for (int r = 0; r < N; r++)
	{
		for (int c = 0; c < N; c++)
		{
			if (map[r][c] == '1')
			{
				int answer = 0;
				answer = dfs(r, c);
				houseCount.push_back(answer);

				++dangiCount;
			}
		}
	}

	sort(houseCount.begin(), houseCount.end());

	// 단지가 25개가 끝인걸 어떻게 알까?

	cout << dangiCount << "\n";
	for (int i = 0; i < dangiCount; i++)
	{
		cout << houseCount[i] << "\n";
	}
}
