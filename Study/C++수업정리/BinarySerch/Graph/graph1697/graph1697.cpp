// **********************  BFS  ****************************
#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

#define MAX_POS 100001

bool isVisited[MAX_POS];
int generation[MAX_POS];

using namespace std;

int N, K; // 동생의 위치.

// pair형식의 큐 선언
queue<int> d;

int msec;

// 미로 경로 탐색

void bfs(int n, int k) // n = 5, k = 17
{
    d.push(n);
    int v = 0;

    generation[v] = 0; // 1세대로 초기화

    while (!d.empty())
    {
        v = d.front();

        d.pop();

        if (v == k)
        {
            break;
        }

        if (v + 1 < MAX_POS)
        {
            if (!isVisited[v + 1])
            {
                d.push(v + 1);

                isVisited[v + 1] = true;
                generation[v + 1] = generation[v] + 1;

            }
        }

        if (v - 1 >= 0)
        {
            if (!isVisited[v - 1])
            {
                d.push(v - 1);

                isVisited[v - 1] = true;
                generation[v - 1] = generation[v] + 1;
            }
        }

        if (v * 2 < MAX_POS)
        {
            if (!isVisited[v * 2])
            {
                d.push(v * 2);

                isVisited[v * 2] = true;
                generation[v * 2] = generation[v] + 1;

            }
        }
    }

    cout << generation[v];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1. 입력
    cin >> N >> K;

    // 3. 처리 & 출력
    bfs(N, K);
}