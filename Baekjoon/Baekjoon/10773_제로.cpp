#include <iostream>
#include <stack>

using namespace std;

int main()
{
	// 입출력 속도 향상
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// 숫자를 담을 스택생성하기
	stack<int> st;

	int action;
	cin >> action;
	while (action--)
	{
		// 스택에 넣을 숫자 입력하기
		int num;
		cin >> num;

		if (num != 0)
		{
			// 스택에 숫자 하나씩 넣기
			st.push(num);
		}
		else
		{
			// 0일 경우 스택에서 숫자 하나 빼기
			st.pop();
		}
	}

	// 스택에 있는 숫자 더하여 출력하기
	int size = st.size();
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += st.top();
		st.pop();
	}
	cout << sum;
}