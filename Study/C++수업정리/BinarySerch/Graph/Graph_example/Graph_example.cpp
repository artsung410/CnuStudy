// Graph_example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <vector>
#include <iostream>

vector<int> graph[1001];
int N, M, V;

using namespace std;

void dfs(int vertex) // 재귀로 구현하는게 일반적이다.
{
	static bool isVisited[1001] = { false }; // 재귀 호출을 하기 때문에 static으로 선언

	isVisited[vertex] = true;

	cout << vertex << ' ';

	for (int next : graph[vertex])
	{
		if (isVisited[next] == false)
		{
			dfs(next);
		}
	}
}


int main()
{
    std::cout << "Hello World!\n";
}
