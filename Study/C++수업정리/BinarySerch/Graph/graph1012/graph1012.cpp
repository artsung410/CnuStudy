#include <iostream>
#include <vector>


using namespace std;

int v[52][52];

int dx[4] = { 1, 0, -1, 0 }; // 서쪽, 북쪽, 동쪽, 남쪽 체크할 룩업테이블 생성
int dy[4] = { 0,-1, 0, 1 };

void dfs(int y, int x) 
{
    v[y][x] = 0; // 첫 방문지점을 0으로 만들어서 방문기록.

    // 자신의 노드를 제외한 동서남북 +1 방향으로 1이 존재하는지 체크,
    for (int i = 0; i < 4; i++) 
    {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (v[nextY][nextX])
        {
            dfs(nextY, nextX);
        }
    }
}

int main() 
{
    // T  : 테스트 케이스
    // Y  : 가로길이
    // X : 세로길이
    // K  : 배추 위치 개수

    int T, X, Y, K, cnt;
    cin >> T;

    for (int test = 0; test < T; test++)
    {
        cnt = 0; // 지렁이가 필요한 회수를 체크
        cin >> X >> Y >> K;
        for (int n = 0; n < K; n++)
        {
            int posX, posY;
            cin >> posX >> posY;
            v[posY + 1][posX + 1] = 1; // 0, 0 -> 1, 1좌표
        }

        for (int r = 1; r <= Y; r++) 
        {
            for (int c = 1; c <= X; c++) 
            {
                if (v[r][c]) 
                {
                    dfs(r, c);
                    cnt++;
                }
            }
        }

        cout << cnt;
        cout << "\n";
    }
}
