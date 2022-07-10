#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

int digitCount[10001];
priority_queue<pair<int, int>> q;
stack<pair<int, int>> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int X, Y;
		cin >> X >> Y;
		q.push(make_pair(Y, X));
	}

	while (!q.empty())
	{
		s.push(make_pair(q.top().first, q.top().second));
		q.pop();
	}

	while (!s.empty())
	{
		cout << s.top().second << ' ' << s.top().first << '\n';
		s.pop();
	}
	return 0;
}

