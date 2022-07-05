/*
어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.
"재귀함수가 뭔가요?"
"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.
마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.
그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어."
____"재귀함수가 뭔가요?"
____"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.
____마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.
____그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어."
________"재귀함수가 뭔가요?"
________"재귀함수는 자기 자신을 호출하는 함수라네"
________라고 답변하였지.
____라고 답변하였지.
라고 답변하였지.
*/
#include <iostream>

using namespace std;

string s = "____";
int cnt = 0;

void ChatBot(int n)
{
	if (n == 0)
	{
		for (int i = 0; i < cnt; i++)
		{
			cout << s;
		}
		cout << "\"재귀함수가 뭔가요?\"\n";

		for (int i = 0; i < cnt; i++)
		{
			cout << s;
		}
		cout << "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";

		for (int i = 0; i < cnt; i++)
		{
			cout << s;
		}
		cout << "라고 답변하였지.\n";
		return;
	}

	for (int i = 0; i < cnt; i++)
	{
		cout << s;
	}
	cout << "\"재귀함수가 뭔가요?\"\n";
	
	for (int i = 0; i < cnt; i++)
	{
		cout << s;
	}
	cout << "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";

	for (int i = 0; i < cnt; i++)
	{
		cout << s;
	}
	cout << "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";

	for (int i = 0; i < cnt; i++)
	{
		cout << s;
	}
	cout << "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";

	cnt++;
	ChatBot(n - 1);

	cnt--;
	for (int i = 0; i < cnt; i++)
	{
		cout << s;
	}
	cout << "라고 답변하였지.\n";
}

int main()
{
	int N;
	cin >> N;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";

	ChatBot(N);
}