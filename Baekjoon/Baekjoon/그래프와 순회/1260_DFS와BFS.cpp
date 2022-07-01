#include <iostream>
// 희소그래프?
#include <stack> // dfs
#include <queue> // bfs
#include <vector>
#include <algorithm>

using namespace std;

vector<int> graph[1001];
int N, M, V;

void dfsWithStack()
{
	// 방문여부저장
	bool isVisit[1001] = { false };

	// dfs 사용할 스택만들기
	stack<int> st; // 스택에는 앞으로 방문할 정점저장
	st.push(V); // 맨처음 방문할 정점
	isVisit[V] = true;
	
	// 모든정점방문 확인하기? => 스택이 비었는지 확인 비었으면 모두방문
	// 더이상 방문할 정점이 없을 때까지 방문
	while (st.empty() == false) // 비었다면 모든정점 방문
	{
		// 정점방문
		int node = st.top();
		//cout << node << " ";
		st.pop();
		isVisit[node] = true;
	
		// 다음으로 방문할 정점 찾기
		/*size_t degreeCnt = graph[node].size();
		for (size_t i = 0; i < degreeCnt; i++)
		{
			int nextNode = graph[node][i];
			if (false == isVisit[nextNode])
			{
				st.push(nextNode);
			}
		}*/
		int cnt = 1;
		for (int nextNode : graph[node])
		{
			if (false == isVisit[nextNode])
			{
				
				st.push(nextNode);
				
				isVisit[nextNode] = true;
				std::cout << nextNode << " ";
			}
			// for문을 다 끝냈는데도 다음걸 못찾았을때??
		}

	}

}

// 재귀함수
void dfs(int vertex)
{
	static bool isVisited[1001] = { false }; // 재귀호출애야하므로 정적데이터로 구성

	// 재방문시 return
	if (isVisited[vertex])
	{
		return;
	}
	
	isVisited[vertex] = true;

	cout << vertex << ' ';

	for (int next : graph[vertex])
	{
		// 첫방문일 경우에만
		/*if (isVisited[next] == false)
		{
			dfs(next);
		}*/

		dfs(next);
	}
}

void bfs()
{
	// 방문여부저장
	bool isVisit[1001] = { false };

	// dfs 사용할 스택만들기
	queue<int> que; // 스택에는 앞으로 방문할 정점저장
	que.push(V); // 맨처음 방문할 정점
	isVisit[V] = true;

	// 모든정점방문 확인하기? => 비었는지 확인 비었으면 모두방문
	// 더이상 방문할 정점이 없을 때까지 방문
	while (que.empty() == false) // 비었다면 모든정점 방문
	{
		// 정점방문
		int node = que.front();
		cout << node << " ";
		que.pop();
		isVisit[node] = true;

		for (int nextNode : graph[node])
		{
			if (false == isVisit[nextNode])
			{
				que.push(nextNode);
				isVisit[nextNode] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 그래프 구성
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int s, e;
		cin >> s >> e;

		graph[s].push_back(e);
		graph[e].push_back(s);
	}

	// 작은 정점부터 방문 시키기위해 정렬
	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}

	dfs(V);

	cout << "\n";
	
	dfsWithStack();

	cout << "\n";

	bfs();
}