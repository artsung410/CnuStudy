#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];
int N, M, V;

int dfs(int vertex) // 재귀로 구현하는게 일반적이다.
{
	static bool isVisited[1001] = { false }; // 재귀 호출을 하기 때문에 static으로 선언
	static int virusNum = -1;
	isVisited[vertex] = true;

	++virusNum;

	for (int next : graph[vertex])
	{
		if (isVisited[next] == false)
		{
			dfs(next);
		}
	}

	return virusNum;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> M;

	// 1. [입력]
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 2. [처리] 작은 정점부터 정렬시키기 위해 정렬 (정점의 개수만큼 반복문 돌린다)
	for (int i = 0; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	// 3. [출력]
	int result = dfs(1);
	cout << result;
}

