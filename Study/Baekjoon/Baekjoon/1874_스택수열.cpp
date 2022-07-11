#include <iostream>
#include <stack>
#include <vector>

using namespace std;

stack<int> s0;
stack<int> s1;
stack<int> s2;
stack<char> s3;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	size_t tempSize = N;
	while (N--)
	{
		int n;
		cin >> n;
		s0.push(n);
	}

	while (s2.size() < tempSize)
	{
		if (s1.empty() || (!s1.empty() && !s0.empty() && s1.top() < s0.top()))
		{
			s1.push(s0.top());
			s0.pop();			
			s3.push('-');
		}

		else if (s2.empty() || (!s2.empty() && s2.top() - s1.top() == 1))
		{
			s2.push(s1.top());
			s1.pop();
			s3.push('+');
		}

		else
		{
			cout << "NO";
			return 0;
		}
	}

	while (!s3.empty())
	{
		cout << s3.top();

		if (s3.size() > 1)
		{
			cout << "\n";
		}

		s3.pop();
	}

	return 0;
}