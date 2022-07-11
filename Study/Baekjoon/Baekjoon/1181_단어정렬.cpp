#include <iostream>

#include <queue>
#include <stack>

using namespace std;

priority_queue<pair<int, string>> q;
stack<string> s;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string word;
		cin >> word;
		
		q.push(make_pair(word.size(), word));
	}

	while (!q.empty())
	{
		s.push(q.top().second);
		q.pop();
	}

	string tmp = " ";
	while(!s.empty())
	{
		if (tmp == s.top())
		{
			tmp = s.top();
			s.pop();
		}

		else
		{
			tmp = s.top();
			cout << s.top() << "\n";
			s.pop();
		} 
	}
	return 0;
}