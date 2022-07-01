/*
N개의 집
C개의 공유기
공유기는 한집당 최대설치수는 1개
가장인접한 두 공유기 사이의 최대거리
1 2 4 => 1
1 4 8 => 3
4 8 9 => 1
1 4 9 => 3
2 4 9 => 2
따라서...정답은 3
*/
#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

int homeCnt, wifiCnt;
int homePos[200000];

int main()
{
	// 집의개수와 공유기개수입력
	cin >> homeCnt >> wifiCnt;

	// 집의 좌표입력
	for (int i = 0; i < homeCnt; i++)
	{
		cin >> homePos[i];
	}

	// 집의 좌표정렬필요
	sort(homePos, homePos + homeCnt);

	// 이진검색범위는 가장 인접한 공유기사이의 거리 => [가장짧은거리 = 1, 가장먼거리 = 가장마지막집좌표] => [1, x[N - 1]]
	int s = 1, e = homePos[homeCnt - 1] + 1;
	int result = 0;
	while (s < e)
	{
		// 중앙값을 해의 후보로정함
		int mid = (s + e) / 2;

		int cnt = 1; // 처음은 무조건설치?

		// 실제로 mid거리만큼 떨가 공유기를 배치할수있는지 확인
		// cnt는 어느경우에 증가할까?!
		// homePos에서 mid만큼 떨어진 거리에 공유기 설치될 경우에 cnt가 증가한다.
		int pos = 0;
		for (int i = 0; i < homeCnt; i++)
		{
			//처음에 설치하고
			// home[pos]
			// 그 위치를 기준으로 mid만큼떨어진 자리에 설치
			// home[pos] + mid => home[newPos]
			// 새로 갱신된 위치 기준 mid만큼 떨어진 자리에 설치
			// home[newPos] => home[pos]
			int len = homePos[i] - homePos[pos];
			
			if (len >= mid)
			{
				pos = i;
				++cnt;
			}
		}

		if (cnt < wifiCnt)
		{
			// 앗! 공유기가 덜 설치됨
			// 더 자잘하게 거리재조정하기
			e = mid;
		}
		else
		{
			if (result < mid)
			{
				result = mid;
			}
			// 공유기가 많이 설치된경우
			// 설치거리를 조금더 늘린다
			s = mid + 1;
		}
		
	}
	// 최대거리 출력
	cout << result;

}