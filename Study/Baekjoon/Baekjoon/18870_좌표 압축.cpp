#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;
stack<int> s;

int arr[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int Num;
		cin >> Num; 

		// 페어벡터에 첫번째에는 입력받은 값을, 두번째에는 해당 배열의 인덱스를 담는다.
		v.push_back(make_pair(Num, i));
	}

	sort(v.begin(), v.end()); // 페어벡터 정렬시키기,
	// -10 / 2
	// -9 / 4
	// 2 / 0
	// 4 / 1
	// 4 / 3

	// 999  / 1 
	// 999  / 3
	// 999  / 5
	// 1000  / 0
	// 1000  / 2
	// 1000  / 4

	int Rank = -1;
	for (int i = 0; i < N; i++)
	{
		// 스택이 비어있거나, 비어있지않고 최상단값이랑 들어온 값이랑 다를때 스택에 넣어준다.
		if (s.empty() || !s.empty() && s.top() != v[i].first) 
		{
			s.push(v[i].first);
			Rank += 1; // 비어있을때도 +1이 적용되므로, Rank초기갑을 -1로두고, 초기값이 들어오면 +1카운트해서 0으로 만든다.
			arr[v[i].second] = Rank; // 배열에 해당 인덱스에 접근해서 랭크롤 담는다.
		}
		else
		{
			arr[v[i].second] = Rank; // 최상단 값이랑 들어온 값이 다를때 push를 하지않고, 이전에 저장된 랭크를 담는다.
		}
	}

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}