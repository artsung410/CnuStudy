/*
push X	: 정수 X를 스택에 넣는 연산이다.
pop		: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size	: 스택에 들어있는 정수의 개수를 출력한다.
empty	: 스택이 비어있으면 1, 아니면 0을 출력한다.
top		: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

첫째 줄에 주어지는 명령의 수
둘째 줄부터 N개의 줄에는 명령이 하나씩 입력된다

14
push 1
	stack : 1
push 2
	stack : 1 2
top
	맨위 2
	stack : 1 2
size
	2개
	stack : 1 2
empty
	들어있으니까 0
	stack : 1 2
pop
	2
	stack : 1
pop
	1
	stack : 
pop
	-1
	stack :
size
	0
	stack :
empty
	1
	stack :
pop
	-1
	stack : 
push 3
	stack : 3
empty
	0
	stack : 3
top
	3
	stack : 3

2
2
0
2
1
-1
0
1
-1
0
3
*/

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	//// top은 맨끝
	//vector<int> st;
	//st.push_back(1);
	//st.pop_back();

	// 입출력 속도 향상
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int action;
	cin >> action;

	vector<int> stack;

	while (action--)
	{
		string command;
		cin >> command;
		
		if (command == "push")
		{
			int num;
			cin >> num;
			stack.push_back(num);
		}
		else if (command == "pop")
		{
			if (stack.empty() != true)
			{
				cout << stack.back() << "\n";
				stack.pop_back();
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (command == "size")
		{
			cout << stack.size() << "\n";
		}
		else if (command == "empty")
		{
			if (stack.empty() == true)
			{
				cout << 1 << "\n";
			}
			else
			{
				cout << 0 << "\n";
			}
		}
		else if (command == "top")
		{
			if (stack.empty() != true)
			{
				cout << stack.back() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
	}
}