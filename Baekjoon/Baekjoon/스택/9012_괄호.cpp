/*
괄호 모양이 바르게 구성된 문자열 -> VPS

VPS
	(())()
	((()))

문자열
	(()(
	(())()))

*/

#include <iostream>
#include <stack>

#define RIGHT ')'
#define LEFT '('

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// 입력
	int action;
	cin >> action;
	while (action--)
	{
		string vps;
		cin >> vps;

		int rightCnt = 0;
		int leftCnt = 0;

		// 스택에 문자열 넣기
		stack<char> st;
		for (int i = 0; i < vps.size(); i++)
		{
			if (vps[i] == RIGHT)
			{
				++rightCnt;
			}
			else
			{
				++leftCnt;
			}
			st.push(vps[i]);
		}

		// 카운트 다르면 NO
		if (rightCnt != leftCnt)
		{
			cout << "NO" << "\n";
		}
		else
		{
			if (st.top() == LEFT) // 처음 나오는 문자가 ( 일시 NO
			{
				cout << "NO" << "\n";
				while (st.size())
				{
					st.pop();
				}
			}
			else
			{
				// )가 나오면 
				// ++카운트한다
				// ( 나오면
				// -- 카운트한다
				// 카운트를 합했을때 0이면 한쌍이다
				// -로 시작하면
				// 쌍이 아니다
				int bracketCount = 0;
				// 하나씩 꺼내면서 확인하기

				while (!st.empty())
				{
					/*
					())(()
					) 1
					( -1
					0 보냄

					( -1 
					음수로 시작하면 NO

					*/
					if (st.top() == RIGHT)
					{
						++bracketCount;
					}
					else
					{
						--bracketCount;
					}

					if (bracketCount < 0)
					{
						cout << "NO" << "\n";
						break;
					}
					
					st.pop();
				}
				
				if (bracketCount == 0)
				{
					cout << "YES" << "\n";
				}
			}
		}
	}
}