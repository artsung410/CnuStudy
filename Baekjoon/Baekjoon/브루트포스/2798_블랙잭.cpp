#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int cardNum[101];
int sum;

// 3장의 카드합이 딜러숫자보다 작으면서(&&) 최대한 가까운수가 나올때 까지 반복해서 연산

int main()
{
	// 카드의 개수 N, 딜러숫자 M
	cin >> N >> M;

	// 카드의 개수만큼 카드숫자 입력
	for (int i = 0; i < N; i++)
	{
		cin >> cardNum[i];
	}

	int ans = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int k = i + 1; k < N; k++)
		{
			for (int j = k + 1; j < N; j++)
			{
				sum = cardNum[i] + cardNum[k] + cardNum[j];
				
				// M을 넘지 않으면서 최대한 가까운수 -> M보다 작거나 같은 수 중에 가장 큰수
				if (sum <= M && sum > ans)
				{
					ans = sum;
				}
				cnt++;
			}
		}
	}

	cout << ans;
}