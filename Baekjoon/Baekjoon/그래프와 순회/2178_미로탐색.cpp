/*
	BFS사용하기
	
	양방향간선연결 예시
	graph[s][e] = graph[e][s] = 1; 가중치는 1로 통일시킴

	bfs구현 예시
	bool visited[] = false 로 방문확인
	queue<int> que; 좌표담을 큐
	visited[node] = true; 루트노드 표시
	que.push(node); 루트노드 큐에 넣음
	
	while(!que.empty())
		int current = que.front(); 맨앞숫자 변수에 담기
		que.pop(); 빼주고
		cout << current; 출력

		for(int next = 0; next < N; ++next) 여기서 N은 가로길이
			if(!visited[next] && graph[current][next]) 첫방문조건
				visited[next] = true
				que.push(next)

	bfs활용한 최단거리
	int row, col, dist
	int d[4][2] = 상하좌우 좌표값저장
	int map[][] 2차원배열
	int N 공간의 크기
	
	for int i; i < N
		for int j; j < N
			cin map[i][j] 이중반복으로 맵에 값 저장
	
	int bfs()
		bool [][] 방문확인
		queue<int> que
		visit[row][col] = true 루트노드 마킹
		que.push({row, col}


*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
//#include <utility>

using namespace std;

#define MAX_LEN 101
// 전역변수
int N, M;
int map[MAX_LEN][MAX_LEN];
bool isVisited[MAX_LEN][MAX_LEN];
int step[MAX_LEN][MAX_LEN]; // 

// 구조체로 타입을 선언하고 큐에 적용가능
//typedef struct Position
//{
//	int y;
//	int x;
//};

void bfs(int y, int x)
{
	step[y][x] = 1;
	isVisited[y][x] = true;
	queue<pair<int, int>> que; // 좌표로 받기위해 pair사용
	que.push(pair<int, int>(y, x));

	static const int pos[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 상하좌우

	while (!que.empty())
	{
		y = que.front().first; // pair사용시 앞뒤구분은 이렇게한다.
		x = que.front().second;	

		que.pop();

		for (int i = 0; i < 4; i++)
		{
			int nY = y + pos[i][0];
			int nX = x + pos[i][1];

			// 아닌조건들
			if (nX < 0 || nX >= M || nY < 0 || nY >= N || isVisited[nY][nX] || map[nY][nX] == 0)
			{
				continue;
			}
			else
			{
				isVisited[nY][nX] = true;
				que.push(pair<int, int>(nY, nX));
				step[nY][nX] = step[y][x] + 1;
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) // 세로
	{
		for (int j = 0; j < M; j++) // 가로
		{
			scanf("%1d", &map[i][j]); // 한글자씩 배열에 넣기
		}
	}

	bfs(0, 0);

	cout << step[N - 1][M - 1];
}