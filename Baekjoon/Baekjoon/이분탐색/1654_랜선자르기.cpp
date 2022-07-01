// 이게왜 이진?
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long; // 오버플로방지한 long long 타입 사용

ll K, N;
ll lan[10000];
ll maxLan;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 입력받기
	cin >> K >> N;

	// 갖고있는 랜선의 길이 입력받음
	// 이진검색으로 처리
	// 범위잡기?! => 자를 수 있는 랜선의 길이
	// 자를수있는 최소길이 : 1cm
	//    ""      최대길이 : 가지고 있는 랜선중 가장 긴 랜선
	// [1, maxLan] 범위임
	for (size_t i = 0; i < K; i++)
	{
		cin >> lan[i];

		maxLan = max(lan[i], maxLan); // 가지고있는 랜선중 가장 긴 랜선찾음
	}
	
	// 이진검색
	// [1, maxLan + 1)
	ll s = 1, e = maxLan + 1;
	ll result = 0;
	while (s < e)
	{
		// 해가 될수있는 후보?!
			ll m = (s + e) / 2;
		// s : 1, e : 803, m : 401

		// m의 길이로 잘랐을때 얻을수 있는 랜선의 개수
		ll cnt = 0;
		for (int i = 0; i < K; i++)
		{
			cnt += lan[i] / m;
		}

		// 해
		if (cnt >= N)
		{
			if (result < m)
			{
				result = m;
			}

			s = m + 1;
		}
		else
		{
			// 줄인다
			e = m;
		}
	}

	cout << result;
}