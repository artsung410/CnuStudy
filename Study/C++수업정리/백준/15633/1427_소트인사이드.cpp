#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ll = long long;
vector<int> v;

void recursion(ll N)
{
	if (N == 0)
	{
		return;
	}

	v.push_back(N % 10);
	recursion(N / 10);
}

int main()
{
	ll N;
	cin >> N;

	recursion(N);

	sort(v.rbegin(), v.rend());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}

	return 0;
}