/*
모든 왼쪽 소괄호("(")는 오른쪽 소괄호(")")와만 짝을 이뤄야 한다.
모든 왼쪽 대괄호("[")는 오른쪽 대괄호("]")와만 짝을 이뤄야 한다.
모든 오른쪽 괄호들은 자신과 짝을 이룰 수 있는 왼쪽 괄호가 존재한다.
모든 괄호들의 짝은 1:1 매칭만 가능하다. 즉, 괄호 하나가 둘 이상의 괄호와 짝지어지지 않는다.
짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다.

하나 또는 여러줄에 걸쳐서 문자열이 주어진다
알파벳, 공백, 소괄호("( )") 대괄호("[ ]")
줄은 마침표 . 로 끝난다

입력의 종료조건으로 맨 마지막에 . 가 들어온다

각 줄마다 균형시 yes, 아니면 no

괄호 없이 " ."인 경우도 yes


So when I die (the [first] I will see in (heaven) is a score list).		yes
[ first in ] ( first out ).												yes
Half Moon tonight (At least it is better than no Moon at all].			no
A rope may form )( a trail in a maze.									no
Help( I[m being held prisoner in a fortune cookie factory)].			no
([ (([( [ ] ) ( ) (( ))] )) ]).											yes
 .																		yes
. 
종료

*/

#include <iostream>
#include <string>
#include <stack>

#define BIGBRACKETLEFT '['
#define BIGBRACKETRIGHT ']'

#define SMALLBRACKETLEFT '('
#define SMALLBRACKETRIGHT ')'

#define PERIOD '.'

using namespace std;

int main()
{
	string str;
	while (true)
	{
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);

		getline(cin, str);
		if (str[0] == PERIOD)
		{
			break;
		}

		stack<char> stk;
		bool isCorrect = true;
		for (int i = 0; i < str.size(); i++)
		{
			char ch = str[i];
			if (ch == BIGBRACKETLEFT || ch == SMALLBRACKETLEFT)
			{
				stk.push(ch);
			}
			else if (ch == BIGBRACKETRIGHT)
			{
				if (!stk.empty() && stk.top() == BIGBRACKETLEFT)
				{
					stk.pop();
				}
				else
				{
					isCorrect = false;
					break;
				}
			}
			else if (ch == SMALLBRACKETRIGHT)
			{
				if (!stk.empty() && stk.top() == SMALLBRACKETLEFT)
				{
					stk.pop();
				}
				else
				{
					isCorrect = false;
					break;
				}
			}
		}

		if (stk.empty() && isCorrect)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}