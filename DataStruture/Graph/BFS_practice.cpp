#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> edge =
{
	{0, 1, 1, 0, 0, 0, 0},
	{1, 0, 0, 1, 1, 0, 0},
	{1, 0, 0, 0, 0, 0, 1},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 1, 0},
	{0, 0, 0, 1, 1, 0, 1},
	{0, 0, 1, 0, 0, 1, 0},
};

vector<bool> visited;

void bfs(int vertex)
{
	visited.at(vertex) = true;

	queue<int> que;
	que.push(vertex);
	cout << vertex + 1 << " ";

	while (!que.empty())
	{
		int n = que.front();
		que.pop();

		for (int i = 0; i < edge.size(); i++)
		{
			if (edge.at(i).at(n) == 1 && visited.at(i) == false)
			{
				cout << i + 1 << " ";
				que.push(i);

				visited.at(i) = true;
			}
		}
	}
}

int main()
{
	visited.assign(edge.size(), false);

	for (int i = 0; i < edge.size(); i++)
	{
		if (visited.at(i) == false)
		{
			bfs(i);
		}
	}
}