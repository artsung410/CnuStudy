#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

#define MAX_SIZE 2000000

stack<int> st; // 수를 비교하기위한 스택
int N;
int seq[MAX_SIZE]; // 입력받을 배열, 비교역할
int NEG[MAX_SIZE]; // 오큰수를 담을 배열

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		// 수열 담은 배열
		cin >> seq[i];
	}
	
	// 배열의 인덱스
	int seqIdx = N - 1;
	int NEGIdx = N - 1;

	// NEGIdx가 음수일때까지 반복
	// 0으로 설정할시 0인덱스를 지나친다
	while (!(NEGIdx < 0))
	{
		// 스택이 비었다면 -1 할당
		if (st.empty())
		{
			// NEG는 뒤에서부터 할당시켜준다.
			NEG[NEGIdx] = -1;
			// 할당하고 앞으로 이동
			--NEGIdx;
		}
		else
		{
			// NEG인덱스와 균형맞추는게 까다로웠다
			--seqIdx;
			while (!st.empty())
			{
				// 비교하려는 배열값보다 스택top이 크다면 오큰수다
				if (st.top() > seq[seqIdx])
				{
					NEG[NEGIdx] = st.top();
					--NEGIdx;
					break;
				}
				else
				{
					st.pop();
					// 안쪽에 하나 더 넣은이유
					// 스택이 비어있다면 -1을 할당해줘야하는데
					// 밖에 하나만 있다면 푸시하는 경우가 무조건 발생하기에 밖에있는 조건문이 돌아가지 않는다
					if (st.empty())
					{
						// NEG는 뒤에서부터 할당시켜준다.
						NEG[NEGIdx] = -1;
						// 할당하고 앞으로 이동
						--NEGIdx;
					}
				}
			}
		}
		// 0인덱스는 푸시하지 않는다
		if (seqIdx > 0)
		{
			st.push(seq[seqIdx]);
		}
	}


	for (int i = 0; i < N; i++)
	{
		cout << NEG[i] << " ";
	}
}

/*

수열의 각 원소 Ai에 대한 오큰수 NGE(i)
오큰수는 오른쪽에 있으면서, Ai보다 큰 수 중에서 가장 왼쪽에 있는 수

3 5 2 7

3의 오큰수: 3보다 오른쪽에 있으면서 3보다 큰수(5, 7) 중 가장 왼쪽에 있는 수(5)
5의 오큰수: 5보다 오른쪽에 있으면서 5보다 큰수(7)중 가장 왼쪽에 있는 수(7)
7의 오큰수: 7보다 오른쪽에 있으면서 7보다 큰수(없다)중 가장 왼쪽에 있는수(없다) => 없으면 -1

9 5 4 8
9의 오큰수: 9보다 큰수는 없음
5의 오큰수: 5보다 오른쪽에있으면서 큰수(8)중 가장왼쪽의 수(8)



2 1 3 5

2의 오큰수: 2보다 오른쪽에 으면서 큰수(3 5) 중 가장 왼쪽 3
1의 오큰수: 3
3의 오큰수: 5
5의 오큰수: -1
3 3 5 -1


int pos = n - 2

st.push(v[v.size() - 1])
ans[n - 1] = -1;

*/