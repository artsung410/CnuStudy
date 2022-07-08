#include <iostream>
#include <string>
#include <queue>

using namespace std;

int M, N, H;
int Box[101][101][101];
int Day[101][101][101];

enum { EMPTY = -1, TOMATO, LEAPED };


struct Coord
{
    int X;
    int Y;
    int Z;
};

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

    cin >> M >> N >> H;

    struct Coord
    {
        int x;
        int y;
        int z;
    };

    queue<Coord> q;

    int ableTomatoCnt = 0;
    int totalTomatoCnt = 0;

    for (int z = 0; z < H; z++)
    {
        for (int y = 0; y < N; y++)
        {
            for (int x = 0; x < M; x++)
            {
                cin >> Box[z][y][x];
            }
        }
    }

    bfs();

}

