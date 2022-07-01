/*
N개의 정점, M개의 간선 무방향그래프
정점번호 1 부터 N번
가중치 1
R에서 시작
오름차순방문
i 번째 줄에는 정점 i의
방문 순서를 출력
시작정점에서 방문할수없는경우 0 출력

*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXSCOPE 100001

vector<int> graph[MAXSCOPE];
int isVisit[MAXSCOPE];
int cnt = 0;

void dfs(int vertex)
{
	// 방문확인용


	isVisit[vertex] = ++cnt;

	// 재방문시 리턴
	if (isVisit[vertex])
	{
		return;
	}

	for (int next : graph[vertex])
	{
		dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, R;
	cin >> N >> M >> R;
	
	// 그래프구성
	for (int i = 0; i < M; i++) // 범위는 간선의 갯수
	{
		int s, e;
		cin >> s >> e;

		// 양방향으로 연결
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 정렬하기. 정점의 개수만큼
	for (int i = 0; i < N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(R);

	for (int i = 0; i < N; i++)
	{
		cout << isVisit[i] << "\n";
	}
}