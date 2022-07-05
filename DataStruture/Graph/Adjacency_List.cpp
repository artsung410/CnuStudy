#include <iostream>
#include <vector>

struct Edge
{
	int Vertex;
	int Weight;

	// »ı¼ºÀÚ
	Edge(int v, int w)
		: Vertex(v), Weight(w)
	{

	}

};

using namespace std;

vector<Edge> graph[7];

int main()
{
	//[0]: { (1, 1) }
	Edge edge(1, 1);
	graph[0].push_back(edge);

	//[1] : { (0, 1), (2, 2), (3, 2) }
	Edge edge(0, 1);
	graph[1].push_back(edge);
	Edge edge(2, 2);
	graph[1].push_back(edge);
	Edge edge(3, 2);
	graph[1].push_back(edge);

	//[2]: { (1, 2), (5, 6), (6, 3) };
	Edge edge(1, 2);
	graph[2].push_back(edge);
	Edge edge(5, 6);
	graph[2].push_back(edge);
	Edge edge(6, 3);
	graph[2].push_back(edge);

	//[3]: { (1, 2), (4, 1), (5, 4) };
	Edge edge(1, 2);
	graph[3].push_back(edge);
	Edge edge(4, 1);
	graph[3].push_back(edge);
	Edge edge(5, 4);
	graph[3].push_back(edge);

	//[4]: { (3, 1) };
	Edge edge(3, 1);
	graph[4].push_back(edge);

	//[5] : { (2, 6), (3, 4) };
	Edge edge(2, 6);
	graph[5].push_back(edge);
	Edge edge(3, 4);
	graph[5].push_back(edge);

	//[6]: { (2, 3) };
	Edge edge(2, 3);
	graph[6].push_back(edge);

}

