/*
덱구현
push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

첫줄 명령수

*/
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int action;
	cin >> action;

	vector<int> dq;
	while (action--)
	{
		string command;
		cin >> command;

		if (command == "push_front")
		{
			int X;
			cin >> X;
			dq.insert(dq.begin(), X);
		}
		else if (command == "push_back")
		{
			int X;
			cin >> X;
			dq.push_back(X);
		}
		else if (command == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << "\n";
				dq.erase(dq.begin());
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (command == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << "\n";
				dq.pop_back();
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (command == "size")
		{
			cout << dq.size() << "\n";
		}
		else if (command == "empty")
		{
			if (!dq.empty())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << 1 << "\n";
			}
		}
		else if(command == "front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (command == "back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
	}
}