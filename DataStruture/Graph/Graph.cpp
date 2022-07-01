#include <iostream>
#include <list>
#include <vector>

#define 김재민 0
#define 김재성 1
#define 안중재 2
#define 성권문 3
#define 이승일 4


//true : 연결, false : 비연결
bool graph[5][5];
//std::list<int> graph2[5];
std::vector<int> graph2[5]; // 보통 리스트보단 벡터쓴다.

// 인접행렬버전 : 인접했니?
bool isAdjacent(int** graph, int v1, int v2)
{
    if (graph[v1][v2] || graph[v2][v1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

// 인접리스트버전 : 인접핸?
bool isAdjacent(std::vector<int>* graph, int v1, int v2)
{
    // find return : Iterator to the first element satisfying the condition or last if no such element is found.
    // 
    if (graph[v1].end() != std::find(graph[v1].begin(), graph[v1].end(), v2))
    {
        return true;
    }
    else if (graph[v2].end() != std::find(graph[v2].begin(), graph[v2].end(), v1))
    {
        return true;
    }
    
    return false;
}

// 인접행렬버전 : 진입차수를 구한다
int GetInDegree(int** graph, int vertex)
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (graph[i][vertex])
        {
            ++cnt;
        }
    }
    return cnt;
}

// 인접리스트버전 : 진입차수구하기
int GetInDegree(std::vector<int>* graph, int vertex)
{
    int cnt = 0;
    for (int i = 0; i < 5; i++)
    {
        if (graph[i].end() != std::find(graph[i].begin(), graph[i].end(), vertex))
        {
            ++cnt;
        }
    }
    return cnt;
}



int main()
{
    // 그래프 구성 (인접 행렬 방식)
    graph[김재민][이승일] = true;

    graph[김재성][안중재] = true;
    graph[김재성][성권문] = true;
    graph[김재성][이승일] = true;

    graph[안중재][김재민] = true;
    graph[안중재][김재성] = true;
    graph[안중재][성권문] = true;
    graph[안중재][이승일] = true;

    graph[성권문][김재성] = true;
    graph[성권문][안중재] = true;
    graph[성권문][이승일] = true;
    /* 
        0 0 0 0 1
        0 0 1 1 1
        1 1 0 1 1
        0 1 1 0 1
        0 0 0 0 0
    */

    // 그래프 구성 : 인접리스트
    graph2[김재민].push_back(이승일);

    graph2[김재성].push_back(안중재);
    graph2[김재성].push_back(성권문);
    graph2[김재성].push_back(이승일);

    graph2[안중재].push_back(김재민);
    graph2[안중재].push_back(김재성);
    graph2[안중재].push_back(성권문);
    graph2[안중재].push_back(이승일);

    graph2[성권문].push_back(김재성);
    graph2[성권문].push_back(안중재);
    graph2[성권문].push_back(이승일);
    /*
        [0] : { 4 }
        [1] : { 2, 3, 4 }
        [2] : { 0, 1, 3, 4 }
        [3] : { 1, 2, 4 }
        [4] : {}
    */
}