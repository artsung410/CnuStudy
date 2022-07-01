#include <iostream>
#include <queue>

using namespace std;

#define MAX_POS 100001

// 전역변수
int start, finish;

queue<int> que;

bool isVisited[MAX_POS];

int quick[MAX_POS];

void bfs(int s, int e)
{
	que.push(s);

	quick[s] = 0;
	isVisited[s] = true;
	
	while (!que.empty())
	{

		int temp = que.front();
		//temp범위가 연산하고나서 범위를 벗어나면 안됨
	
		if (temp == e)
		{
			break;
		}

		que.pop();

		// 새로운 좌표로 움직인값 push하기
		// 같은값에 중복으로 들어가면 안된다.
		// x + 1
		if (temp + 1 < MAX_POS)
		{
			if (!isVisited[temp + 1]) // 더한 값이 최대범위를 넘어가면안된다.
			{
				que.push(temp + 1);
				isVisited[temp + 1] = true;
				quick[temp + 1] = quick[temp] + 1;

			}
		}

		// x - 1
		// 오답노트: temp - 1값이 0이 나올수있으므로 0도 포함시켜야했다
		if (temp - 1 >= 0)
		{
			if (!isVisited[temp - 1]) // 뺀값이 음수면 안된다.
			{
				que.push(temp - 1);
				isVisited[temp - 1] = true;
				quick[temp - 1] = quick[temp] + 1;

			}
		}

		// 2 * x
		// 오답노트: temp * 2값이 최대범위보다 작게 설정해야했다. 정적배열의 범위를 벗어나 값을 넣지 않도록
		if (temp * 2 < MAX_POS)
		{
			if (!isVisited[temp * 2]) // 곱한값이 범위를 넘어가면 안된다.
			{
				que.push(temp * 2);
				isVisited[temp * 2] = true;
				quick[temp * 2] = quick[temp] + 1;
			}

		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 시작위치, 도착위치
	cin >> start >> finish;

	// 큐에 3개의 생성된 정점을 담고
	// 새로 생성된 정점마다 연산을한다.
	// 5 -> ( 6       4       10 ) 
	//    (7 5 12) (5 3 8) (11 9 20)   이런식으로 큐에 쌓인다 
	// 이미 나온 숫자라면 담지 않는다
	// 큐에 들어있는 값중 도착위치가 나올때까지 카운트

	bfs(start, finish);

	cout << quick[finish];
}