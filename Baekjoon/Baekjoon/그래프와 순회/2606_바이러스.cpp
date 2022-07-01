#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_COM 100

// 벡터로 그래프
vector<int> graph[MAX_COM];
//int num[MAX_COM] = { 0 };
bool isVisit[MAX_COM] = { false };
int cnt = 0;

// 재귀로 dfs구현
void dfs(int vertex)
{
	isVisit[vertex] = true;

	++cnt;

	for (int next : graph[vertex])
	{
		if (isVisit[next])
		{
			continue;
		}
		dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 정점수 입력
	int com;
	cin >> com;

	// 간선수 입력
	int link;
	cin >> link;

	// 간선수 만큼 연결하기
	for (int i = 0; i < link; i++)
	{
		int s, e;
		cin >> s >> e;

		// 양뱡향 연결
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 정점 정렬하기
	for (int i = 0; i < com; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(1);

	cout << cnt - 1;
}