#include <iostream>
#include <algorithm>

using namespace std;

#define CARDMAX 500000
int N;
int M;
int cardArr[CARDMAX];
int sangCard[CARDMAX];
int ans[CARDMAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 기준카드
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cardArr[i];
	}
	// 이분탐색 정렬필요
	sort(cardArr, cardArr + N); // -10 2 3 6 10 
											//  0 1 2 3 4
											// 
	// 상근이의 카드
	cin >> M;


	for (int i = 0; i < M; i++)
	{
		cin >> sangCard[i];

		//int isEnd = 0;

		int sIdx = 0;
		int eIdx = N - 1;
		int midIdx = 0;
		while (sIdx <= eIdx)
		{
			midIdx = (sIdx + eIdx) / 2;

			if (sangCard[i] == cardArr[midIdx])
			{
				ans[i] = 1;
				break;
			}
			else if (sangCard[i] > cardArr[midIdx])
			{
				sIdx = midIdx + 1;
				//++isEnd;
			}
			else
			{
				eIdx = midIdx;
				//++isEnd;
			}

			// 무한으로 루프돌고있을때
			if (sangCard[i] != cardArr[midIdx] && midIdx == eIdx && midIdx == sIdx)
			{
				//ans[i] = 0;
				break;
			}
		}

		cout << ans[i] << " ";

	}

}