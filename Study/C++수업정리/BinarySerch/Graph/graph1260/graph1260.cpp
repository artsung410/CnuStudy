#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

vector<int> graph[1001];
int N, M, V;


void dfs()
{
    // 1. 방문 여부를 지정해야 한다.
    bool isVisited[1001] = { false };

    // 2. DFS에 사용할 스택을 만든다.
    stack<int> st; // 스택에는 앞으로 방문할 정점이 저장된다.
    st.push(V); // 첫번째로 방문할 정점
    isVisited[V] = true;

    // 3. 더이상 방문할 정점이 없을 때까지 방문한다.
    while (!st.empty()) // 스택이 비어있다면 모든 정점을 방문한 것이다.
    {
        // 3 - 1. 정점을 방문한다.
        int node = st.top();
        st.pop();
        isVisited[node] = true;
        cout << node << ' ';

        // 3 - 2. 다음으로 방문하 정점을 찾는다.
        for (int nextNode : graph[node])
        {
            if (false == isVisited[nextNode])
            {
                st.push(nextNode);
                
                break;
            }
        }

        for (int nextNode : graph[node])
        {
            if (false == isVisited[nextNode])
            {
                st.push(nextNode);
                break;
            }
        }
    }
}

void bfs()
{

}
int main()
{


    //1. 그래프 구성
    cin >> N >> M >> V;

    for (int i = 0; i < M; ++i)
    {
        int s, e;
        cin >> s >> e;

        graph[s].push_back(e);
        graph[e].push_back(s);

    }

    // 2. 작은 정점부터 방문 시키기 위해 정렬
    for (int i = 1; i <= N; ++i)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    

}
