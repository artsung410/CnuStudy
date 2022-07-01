#include <iostream>
#include <queue>

using namespace std;

int Generation[301][301];

queue<pair<int, int> > q;

int L, ix, iy, fx, fy;

void bfs()
{
    int dx[8] = { -1, 1, 2, 2, 1, -1, -2, -2 };
    int dy[8] = { 2, 2, 1, -1, -2, -2, -1, 1 };

    Generation[iy][ix] = 1;                  
    q.push(make_pair(iy, ix));
    while (!q.empty())
    {
        int y = q.front().first;
        int x = q.front().second;

        q.pop(); 

        for (int i = 0; i < 8; i++)
        {
            int nX = x + dx[i];
            int nY = y + dy[i];

            if (nY >= 0 && nX >= 0 && nY < L && nX < L && Generation[nY][nX] == 0)
            {
                q.push(make_pair(nY, nX));
                Generation[nY][nX] = Generation[y][x] + 1;
            }
        }
    }
    cout << Generation[fy][fx] - 1 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;

    cin >> T;
    for (int test = 0; test < T; test++)
    {
        for (int i = 0; i < L; i++)
        {
            for (int j = 0; j < L; j++)
            {
                Generation[i][j] = 0;
            }
        }

        cin >> L;
        cin >> ix >> iy;
        cin >> fx >> fy;
        
        bfs();

    }

    return 0;
}


