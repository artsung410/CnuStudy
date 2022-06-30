#include <iostream>
#include <string>
#include <queue>

using namespace std;

int M, N;

int Box[1001][1001];         
bool isVisited[1001][1001]; // 방문여부 확인 할 booltype 배열         
int Day[1001][1001];

// 다음에 방문할 정점을 큐에 담는다.
enum { EMPTY = -1, TOMATO, REAPED };

queue<pair<int, int> > q;

void bfs()
{
    static int dx[4] = { 1, 0, -1, 0 };
    static int dy[4] = { 0,-1, 0, 1 };

    int x = 0; int y = 0;

    int ableTomatoCnt = 0;
    int totalTomatoCnt = 0;

    for (int r = 0; r < N; r++)
    {
        for (int c = 0; c < M; c++)
        {
            if (Box[r][c] == 1)
            {
                y = r;
                x = c;
                q.push(make_pair(y, x));
            }
            
            if (Box[r][c] == TOMATO)
            {
                ++totalTomatoCnt;
            }
        }
    }

    isVisited[y][x] = true;
    Day[y][x] = 0;

    while (!q.empty())
    {
        y = q.front().first;
        x = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (0 > newX || newX >= M || 0 > newY || newY >= N || Box[newY][newX] == EMPTY)
            {
                continue; 
            }

            if (!isVisited[newY][newX] && Box[newY][newX] == 0)
            {
                ++ableTomatoCnt;
                isVisited[newY][newX] = true;      
                q.push(make_pair(newY, newX));
                Day[newY][newX] = Day[y][x] + 1;
                Box[newY][newX] = 1;
            }
        }
    }

    if (totalTomatoCnt - ableTomatoCnt > 0)
    {
        cout << EMPTY << endl;
    }

    else
    {
        cout << Day[y][x] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // 1. M, N을 입력 받는다.

    cin >> M >> N;

    // 2. 토마토 상자의 정보를 입력 받는다.

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> Box[y][x];
        }
    }

    // 3. 토마토를 숙성시켜야 함
    bfs();

    // 4. 속성일 수 출력

}

