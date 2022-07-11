#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, string>> v;

// 나이가 같지 않으면, 일단 나이순으로 오름차순

// 나이가 같으면, 먼저 들어온 순서대로.

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int X; string word;
		cin >> X >> word;
		v.push_back(make_pair(X, word));
	}

	stable_sort(v.begin(), v.end(), compare);
	
	for (int i = 0; i < N; i++)
	{
		cout << v[i].first << ' ' << v[i].second <<'\n';
	}

	return 0;
}

