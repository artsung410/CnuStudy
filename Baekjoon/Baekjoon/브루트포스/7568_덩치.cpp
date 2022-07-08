#include <iostream>
#include <algorithm>

#define MAX_MEN 50

using namespace std;

int bulk[MAX_MEN][2];
int N, weight, height;
int rankArr[MAX_MEN];

int main()
{
	cin >> N;
	// 몸무게 키 입력
	for (int i = 0; i < N; i++)
	{
		cin >> weight >> height;

		bulk[i][0] = weight;
		bulk[i][1] = height;
	}
	
	for (int i = 0; i < N; i++)
	{
		int cnt = 1;
		for (int j = 0; j < N; j++)
		{
			if (bulk[i][0] < bulk[j][0] && bulk[i][1] < bulk[j][1]) // 비교값이 최소값일수록 많이 실행된다. 즉, 순위카운트가 올라감
			{
				cnt++;
			}
		}
		rankArr[i] = cnt; // 순위를 저장한 배열, 순서는 덩치배열과 동일하다.
	}

	for (int i = 0; i < N; i++)
	{
		cout << rankArr[i] << " ";
	}
}
