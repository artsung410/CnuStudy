#include <iostream>
#include <vector>
#include <stack>

using namespace std;

#pragma region 벡터사용
//벡터를 이용한 DFS
int nodeNum = 7; // 노드개수
bool c[7] = {false}; // 방문처리를 위한 배열
vector<int> a[8]; // 노드가 각각 인접한 노드를 가질수있게 간선의 개수입력

void dfs(int vertex)
{
	if (c[vertex]) // 방문시 종료
	{
		return;
	}
	c[vertex] = true; // 방문처리
	cout << vertex << ' '; // 방문노드 출력

	// 해당노드와 인접한노드를 하나씩방문
	for (int  i = 0; i < a[vertex].size(); i++)
	{
		// 인접노드 대상으로 재귀함수 사용
		int y = a[vertex][i];
		dfs(y);
	}
}
#pragma endregion
