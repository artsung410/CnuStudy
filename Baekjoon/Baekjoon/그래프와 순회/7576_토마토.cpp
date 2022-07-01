#include <iostream>
#include <queue>

#define MAX_LEN 1001
using namespace std;

int M, N;
int box[MAX_LEN][MAX_LEN];
bool isVisited[MAX_LEN][MAX_LEN];
int date[MAX_LEN][MAX_LEN];
int y, x;
int dy, dx;
queue<pair<int, int>> que;

void bfs()
{
	// 시작위치 가져오기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 1)
			{
				que.push(pair<int, int>(i, j));
				date[i][j] = 0; // 시작지점
				isVisited[i][j] = true; // 방문마크
				x = j;
				y = i;
			}
		}
	}

	// 같은때에 일어난일 처리는
	// 큐사이즈받아와서
	// 사이즈 크기만큼 반복문을 돌린다.

	static const int pos[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	while (!que.empty())
	{
		y = que.front().first;
		x = que.front().second;

		que.pop();

		for (int i = 0; i < 4; i++)
		{
			dy = y + pos[i][0];
			dx = x + pos[i][1];

			if (dy < 0 || dy >= N || dx < 0 || dx >= M)
			{
				continue;
			}
			if (isVisited[dy][dx] || box[dy][dx] == -1 || box[dy][dx] == 1)
			{
				continue;
			}

			isVisited[dy][dx] = true;
			box[dy][dx] = 1;
			que.push(pair<int, int>(dy, dx));
			date[dy][dx] = date[y][x] + 1; // 조건만족시 1씩 증가
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin.tie(nullptr);

	cin >> M >> N;

	int cnt = 0;
	// 토마토 상자의 정보입력받기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> box[i][j];
			
			if (box[i][j] == 0)
			{
				++cnt;
			}
			// 입력받을때 큐에 푸쉬
		}
	}

	// 처음부터 다 익은경우
	// 순회했는데 0이없으면 끝내기
	if (/*배열안에 0이없다.*/cnt == 0)
	{
		// 배열안에 0이 없을때 여기를 실행하고싶다
		cout << 0 << "\n";
		return 0;
	}

	// 토마토 숙성과정
	bfs();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (box[i][j] == 0) // 박스에 0 있을때, 숙성되지않은 토마토 존재
			{
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	
	cout << date[dy][dx - 1] << "\n";
}