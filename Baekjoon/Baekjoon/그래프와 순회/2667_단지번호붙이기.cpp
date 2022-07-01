/*
집있는곳 1 없는곳 0

	0 1 1 0 1 0 0
	0 1 1 0 1 0 1
	1 1 1 0 1 0 1
	0 0 0 0 1 1 1
	0 1 0 0 0 0 0
	0 1 1 1 1 1 0
	0 1 1 1 0 0 0

	연결된집: 단지
	단지내 집의수를 오름차순으로 출력
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define MAXSIZE 25

bool isVisit[MAXSIZE][MAXSIZE] = { false };

void dfs(int x, int y)
{
	isVisit[y][x] = true;

	int nx;
	int ny;

	nx = x + 1 || x - 1;
	int pos[4] = {
		{},
		{},
		{},
		{}
	}

	if (!isVisit[ny][nx])
	{
		dfs(nx, ny);
	}
}

int main()
{
	// 지도의 크기
	int N;
	cin >> N;

	// 문자열로 입력받기
	string str;
	int home[MAXSIZE][MAXSIZE];
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		// 문자열을 단어하나씩 배열에 저장하기
		for (int j = 0; j < N; j++)
		{
			home[i][j] = str[j] - '0';
		}
	}

	// 1이면서 첫방문이면 순회하기
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (home[i][j] == 1 && isVisit[i][j] == false)
			{
				dfs(j, i);
			}
		}
	}

}
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <utility> // pair
#include <vector>

using namespace std;

//전역변수들
int N;
int map[30][30];
bool isVisited[30][30] = {false};

// 반환값의 의미, 단지내 집의 개수
int dfs(int y, int x)
{
	isVisited[y][x] = true;

	// 상하, 좌우 정보를 담을곳
	static const int yPos[] = { -1, 1, 0, 0 }; // 상하
	static const int xPos[] = { 0, 0, -1, 1 }; // 좌우

	int houseCnt = 1;

	// 기존좌표에 상하, 좌우 이동한 새로운 좌표
	for (int i = 0; i < 4; i++)
	{
		// 새로운 좌표생ㅇ성
		int nx = x + xPos[i];
		int ny = y + yPos[i];
		
		// 예외처리
		// 범위넘어간부분
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
		{
			continue;
		}
		// 재방문했을경우거나 집이아닌곳
		if (isVisited[ny][nx] || map[ny][nx] == 0)
		{
			continue;
		}
		houseCnt += dfs(ny, nx);
	}
	return houseCnt;
}

int main()
{
	// N을 입력
	scanf("%d", &N);

	// 단지입력 scanf
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			scanf("%1d", &map[y][x]); // 문자를 하나씩 입력해라
		}
	}

	int complexCount = 0;
	vector<int> houseCnt;
	// 단지수와 단지내 집의개수 구하기
	// 단지를 알아내는데 DFS사용한다.
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			//// 1. 방문여부를 저장한다. => isVisited
			//// 2. 다음에 방문할곳을 스택에 저장한다.
			//// 2-1 스택에는 좌표를 저장한다. 좌표는 pair로 저장한다. => stack<pair<int, int>> st;
			//stack<pair<int, int>> st;
			//st.push(pair<int, int>(0, 0));
			//// 3. 전부 방문할때까지 순회한다.
			//while (st.empty() == false)
			//{
			//	// 현재 집 위치가져오고
			//	// 방문
			//	// 주변탐색
			//}
			
			// 집찾았고, 방문 ㄴ?
			if (isVisited[y][x] == false && map[y][x] == 1)
			{
				// 한번실행할때마다 단지를 하나 찾는다
				int housecount = dfs(y, x);
				houseCnt.push_back(housecount);
				++complexCount;
			}
		}
	}
	sort(houseCnt.begin(), houseCnt.end());

	printf("%d\n", complexCount);
	for (int i = 0; i < houseCnt.size(); i++)
	{
		printf("%d\n", houseCnt[i]);
	}
}