#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define CARDMAX 500000

int N, M;

int cmpCard[CARDMAX];
int ans[CARDMAX];
vector<int> sangCard;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	

	// 상근이가 가지고있는 카드들 벡터로
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		sangCard.push_back(num);
	}
	sort(sangCard.begin(), sangCard.end());
	// 비교할 카드들
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> cmpCard[i];

		// 카드비교
		int cnt = 0;
		int startIdx = 0;
		int endIdx = N - 1;
		while (true)
		{
			int midIdx = (startIdx + endIdx) / 2;
			if (cmpCard[i] == sangCard[midIdx])
			{
				cnt++;
				sangCard.erase(sangCard.begin() + midIdx);
				
			}
			else if (cmpCard[i] < sangCard[midIdx])
			{
				endIdx = midIdx;
			}
			else
			{
				startIdx = midIdx + 1;
			}
		}


		// M개의 갖고있는 카드들
		cout << ans[i];
	}

}