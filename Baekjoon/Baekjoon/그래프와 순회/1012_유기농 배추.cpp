#include <iostream>
//#include <algorithm> 2차원배열에 그래프를 그렸으므로 정렬이 필요없다?

using namespace std;

#define MAX_LENGTH 51

int T, M, N, cabbageCnt, X, Y;
int map[MAX_LENGTH][MAX_LENGTH] = { 0 };
bool isVisited[MAX_LENGTH][MAX_LENGTH] = { false };

void dfs(int y, int x)
{
	// 방문한 위치 표시
	isVisited[y][x] = true;

	// 위치값 재조정
	static const int dx[4] = { -1, 1, 0, 0 }; // 좌우
	static const int dy[4] = { 0, 0, -1, 1 }; // 상하
	
	// 상하좌우 확인하고 조건이 맞으면 재귀
	for (int i = 0; i < 4; i++)
	{
		int newY = y + dy[i];
		int newX = x + dx[i];

		if ((map[newY][newX] == 0 || isVisited[newY][newX]) || newX < 0 || newY < 0 || newX >= M || newY >= N)
		{
			continue;
		}
		dfs(newY, newX);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 테스트케이스
	cin >> T;

	while (T--)
	{
		// 가로, 세로, 심어진 배추개수
		cin >> M >> N >> cabbageCnt;
		
		int wormCnt = 0;

		// 맵 초기화
		for (int i = 0; i < MAX_LENGTH; i++)
		{
			for (int j = 0; j < MAX_LENGTH; j++)
			{
				map[i][j] = 0;
				isVisited[i][j] = false;
			}
		}

		// 좌표값 입력하고 해당 좌표에 1표시 
		while (cabbageCnt--)
		{
			cin >> X >> Y;
			map[Y][X] = 1;
		}

		// 인접한 배추당 한마리
		for (int i = 0; i < N; i++) // 세로
		{
			for (int j = 0; j < M; j++) // 가로
			{
				// dfs호출조건: 첫방문이고 0이 아닌경우
				if (isVisited[i][j] == false && map[i][j] == 1)
				{
					dfs(i, j);
					++wormCnt;
				}
			}
		}
		// 벌레 출력
		cout << wormCnt << "\n";
	}

}