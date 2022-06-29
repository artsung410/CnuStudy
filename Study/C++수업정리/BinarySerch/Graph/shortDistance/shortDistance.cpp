#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define INF 987654321

using namespace std;

int graph[7][7] = {
    {   0,   7, INF, INF,   3,  10, INF },
    {   7,   0,   4,  10,   2,   6, INF },
    { INF,   4,   0,   2, INF, INF, INF },
    { INF,  10,   2,   0,  11,   9,   4 },
    {   3,   2, INF,  11,   0, INF,   5 },
    {  10,   6, INF,   9, INF,   0, INF },
    { INF, INF, INF,   4,   5, INF,   0 }
};

// start : 시작 정점
std::vector<int> GetShortestPath(int start)
{
    // distance 배열 만들기
    std::vector<int> dist(7);
    for (int i = 0; i < 7; ++i)
        dist[i] = graph[start][i];

    // 방문한 정점 집합 만들기
    std::vector<bool> isVisited(7);
    isVisited[start] = true;

    // 모든 정점에 대한 최단 경로를 찾을 때까지
    for (int i = 0; i < 7 - 1; ++i)
    {
        // 방문하지 않은 정점 중 최솟값을 가지는 정점을 구함
        size_t next = 0;
        size_t minDist = INF;

        for (size_t node = 0; node < 7; ++node)
        {
            if (isVisited[node])
                continue;

            if (minDist > dist[node])
            {
                next = node;
                minDist = dist[node];
            }
        }

        // 방문 표시 => 방문한 정점은 최소 거리임을 보장함.
        isVisited[next] = true;

        // 경로 업데이트
        for (size_t node = 0; node < 7; ++node)
        {
            dist[node] = std::min(dist[node], dist[next] + graph[next][node]);
        }
    }

    return dist;
}

std::vector<int> GetShortestPath2(int start)
{
    // distance 배열 만들기
    // 발견되지 않은 정점은 모두 INF다.
    vector<int> dist(7, INF);
    // 시작 정점은 거리가 0이다.
    dist[start] = 0;

    // 우선순위 큐를 이용한다.
    priority_queue<pair<int, int>> pq;
    // 시작 정점을 넣어준다.
    pq.emplace(0, start);

    // dist의 모든 값을 찾을 때까지
    while (false == pq.empty())
    {
        // dist 중에서 가장 최소값을 가지는 정점을 뽑아낸다.
        int w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        // 과거에 발견한 최단 경로와 현재 최단 경로를 비교한다.
        // 과거에 발견한 최단 경로가 더 크다면 계산할 필요가 없다.
        if (dist[v] < w)
        {
            continue;
        }

        // 해당 정점을 이용했을 때, 최단 거리를 찾을 수 있는지 체크한다.
        for (int node = 0; node < 7; ++node)
        {
            if (dist[node] > w + graph[v][node])
            {
                dist[node] = w + graph[v][node];

                pq.emplace(-dist[node], node);
            }
        }
    }

    return dist;
}

std::vector<int> GetShortestPathWithPath(int start, vector<int>& outPath)
{
    vector<int> dist(7, INF);
    dist[start] = 0;

    // path[i]는 i 정점으로 가기 위해 거쳐야 하는 정점이다.
    vector<int> path(7, INF);
    path[start] = start;

    priority_queue<pair<int, int>> pq;
    pq.emplace(0, start);

    while (false == pq.empty())
    {
        int w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (dist[v] < w)
        {
            continue;
        }

        for (int node = 0; node < 7; ++node)
        {
            if (dist[node] > w + graph[v][node])
            {
                dist[node] = w + graph[v][node];

                // 해당 node로 가기 위해서는 v를 거쳐야 한다.
                path[node] = v;

                pq.emplace(-dist[node], node);
            }
        }
    }

    outPath = std::move(path);

    return dist;
}

void PrintPath(int start, int end)
{
    vector<int> path;
    GetShortestPathWithPath(start, path);

    int curr = end;
    while (curr != start)
    {
        printf("%d <- ", curr);
        curr = path[curr];
    }
    printf("%d", curr);

    // 혹은 스택에 넣어서 순서대로 출력할 수도 있다.
}

int main()
{
    auto vec1 = GetShortestPath(0);
    auto vec2 = GetShortestPath(2);

    std::cout << "0 : [";
    for (int i : vec1)
    {
        std::cout << i << ' ';
    }
    std::cout << "]\n";

    std::cout << "2 : [";
    for (int i : vec2)
    {
        std::cout << i << ' ';
    }
    std::cout << "]\n";

    auto vec3 = GetShortestPath2(0);
    std::cout << "0 : [";
    for (int i : vec3)
    {
        std::cout << i << ' ';
    }
    std::cout << "]\n";

    PrintPath(0, 2);
}
