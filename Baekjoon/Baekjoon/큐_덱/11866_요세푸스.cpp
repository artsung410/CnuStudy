/*
k번째 사람을 제거
ex) 7 3
1 2 3 4 5 6 7
3제거

4 5 6 7 1 2
6제거

7 1 2 4 5
2제거

4 5 7 1
7제거

1 4 5
5제거

1 4
1제거

4
*/

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int menNum;
	int eraseNum;
	cin >> menNum;
	cin >> eraseNum;

	queue<int> josephus;
	for (int i = 0; i < menNum; i++)
	{
		josephus.push(i + 1);
	}

	cout << "<";
	while (!josephus.empty())
	{
		for (int i = 0; i < eraseNum - 1; i++)
		{
			int front = josephus.front();
			josephus.push(front);
			josephus.pop();
		}
		cout << josephus.front();
		josephus.pop();
		if (josephus.size() >= 1)
		{
			cout << ", ";
		}
	}
	cout << ">";
}