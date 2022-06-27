#include <iostream>
#include <vector>
#define 김재민 0
#define 김재성 1
#define 안중재 2
#define 성권문 3
#define 이승일 4


//true : 연결, false : 비연결

bool graph[5][5];
std::vector<int> graph2[5];


// 진입차수를 구한다 => 인접 행렬 버전
int CountIndegree(int** graph, int vertex)
{    
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (graph[i][vertex])
		{
			++count;
		}
	}

	return count;
}

// 인접 리스트 버전
int CountIndegree(std::vector<int>* graph, int vertex)
{
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if(graph[i].end() != std::find(graph[i].begin(), graph[i]))
	}
}

