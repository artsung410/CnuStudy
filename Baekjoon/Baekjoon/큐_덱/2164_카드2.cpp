/*
1 ~ 500000 카드
위에서부터 1
맨위 pop하고 top을 맨 밑으로
다시 맨위 pop하고 top을 맨 밑으로
위 과정을 한장남을때 까지 반복

*/
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 카드 개수 입력
	int action;
	cin >> action;

	// 큐에 카드 1부터 순서대로 넣기
	queue<int> card;
	for (int i = 0; i < action; i++)
	{
		card.push(i + 1);
	}

	while (1)
	{
		if (card.size() == 1)
		{
			break;
		}
		// 뽑고
		card.pop();

		// swap
		int front = card.front();
		int back = card.back();

		card.push(front);
		card.pop();
	}

	cout << card.front();
}