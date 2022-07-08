#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];
int N, M, V;


void dfs(int vertex) // 재귀로 구현하는게 일반적이다.
{
	static bool isVisited[1001] = { false }; // 재귀 호출을 하기 때문에 static으로 선언

	isVisited[vertex] = true;

	cout << vertex << ' ';

	// graph[1] = (2, 3, 4)
	// 범위 기반 for문
	for (int next : graph[vertex])
	{
		if (isVisited[next] == false)
		{
			dfs(next);
		}
	}
}

void dfs()
{
	bool isVisited2[1001] = { false }; // 이 배열이 없으면 계속 뺑뺑 돈다.

	stack<int> st;
	st.push(V);
	isVisited2[V] = true;
	cout << V << " ";

	while (!st.empty())
	{
		int vertex = st.top();
		st.pop();

		for (int next : graph[vertex]) // graph[1] = {2, 3, 4}  // graph[2] = {1, 4} // graph[4] = {3, 4}
		{
			if (isVisited2[next] == false)
			{
				st.push(next);
				cout << next << " ";
				isVisited2[next] = true;
				break;
			}
		}
	}
}

void bfs()
{
	// 1. 방문 여부를 저장해야 한다.
	bool isVisited[1001] = { false };

	// 2. BFS에 사용할 큐를 만든다.
	queue<int> que; // 큐에는 앞으로 방문할 정점이 저장된다.
	que.push(V); // 첫 번째로 방문할 정점
	isVisited[V] = true;

	// 3. 더이상 방문할 정점이 없을 때까지 방문한다.
	while (false == que.empty())	// 큐가 비어있다면 모든 정점을 방문한 것이다.
	{
		// 3 - 1. 정점을 방문한다.
		int node = que.front();
		que.pop();
		cout << node << ' ';

		// 3-2. 다음으로 방문할 정점을 찾는다.
		for (int nextNode : graph[node])
		{
			if (false == isVisited[nextNode])
			{
				que.push(nextNode);
				isVisited[nextNode] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 1. 그래프 구성
	// N = 정점의 개수
	// M = 간선의 개수
	// V = 탐색을 시작할 정점의 번호

	cin >> N >> M >> V;

	// 정점끼리 간선의 개수만큼 이어주기 (간선의 개수만큼 입력을 받는다.)
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 2. 작은 정점부터 정렬시키기 위해 정렬 (정점의 개수만큼 반복문 돌린다)
	for (int i = 0; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs();
	cout << "\n";
	bfs();
}