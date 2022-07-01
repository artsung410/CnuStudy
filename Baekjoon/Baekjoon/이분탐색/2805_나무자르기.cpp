/*
N개의 나무를 밴다
나무 H미터 위 부분만 가져감
위 부분의 합이 입력값M과 같아야함
H의 최댓값은 얼마?
*/

#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll treeNum;
ll needLen;
ll treeHeight[1000000];
ll maxHeight;

ll s, e;

ll cutLen;

ll result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> treeNum >> needLen;

	for (int i = 0; i < treeNum; i++)
	{
		cin >> treeHeight[i];

		maxHeight = max(treeHeight[i], maxHeight);
	}

	// 1 ~ 나무의 최대 높이
	// start: 1  end: 20
	// H = start + end / 2  중간값으로 둔다
	// 나무를 H로 자른다
	// 나오는 나무길이 cutLen = 20 - H;
	// 모든 cutLen을 합했을때, needLen 보다 크면?
	// needLen < cutLen 이면, H가 낮다는 뜻
	// H를 늘릴려면 start를 중간값으로 둔다.
	s = 1;
	e = maxHeight + 1;

	result = 0;
	while (s < e)
	{
		ll H = (s + e) / 2;

		cutLen = 0;
		for (int i = 0; i < treeNum; i++)
		{
			if (treeHeight[i] >= H)
			{
				cutLen += (treeHeight[i] - H);
			}
		}

		if (cutLen < needLen)
		{
			// 부족한길이
			// 더 잘게 잘라야한다면
			e = H;
		}
		else
		{
			result = H;
			s = H + 1;
		}
	}
	cout << result;
}