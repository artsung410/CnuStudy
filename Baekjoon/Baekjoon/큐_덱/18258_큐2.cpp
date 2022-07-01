/*
정수저장 큐 구현하기

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

첫째줄 명령어 수	

*/
#include <iostream>
#include <list>	

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int action;
	cin >> action;

	// 컨테이너생성
	list<int> que;

	while (action--)
	{
		string command;
		cin >> command;
		if (command == "push")
		{
			int num;
			cin >> num;
			que.push_back(num);
		}
		else if (command == "pop")
		{
			if (!que.empty())
			{
				int n = que.front();
				cout << n << endl;
				que.pop_front();
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (command == "size")
		{
			cout << que.size() << endl;
		}
		else if (command == "empty")
		{
			if (!que.empty())
			{
				cout << 0 << endl;
			}
			else
			{
				cout << 1 << endl;
			}
		}
		else if (command == "front")
		{
			if (!que.empty())
			{
				cout << que.front() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
		else if (command == "back")
		{
			if (!que.empty())
			{
				cout << que.back() << endl;
			}
			else
			{
				cout << -1 << endl;
			}
		}
	}
}