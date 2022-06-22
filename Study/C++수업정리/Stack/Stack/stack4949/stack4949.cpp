#include <iostream>
#include <stack>
#include <string>

using namespace std;


int bracketCnt_S = 0;
int bracketCnt_L = 0;

bool isBracketClose = false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    std::stack<char> s;

    while (1)
    {
        // 1. 입력
        string Brackets;
        getline(cin, Brackets);

        // 2. 스택에 요소를 담는다.
        for (int i = 0; i < Brackets.size(); i++)
        {
            s.push(Brackets[i]);
        }

        int size = 0;

        // 2. 처리
        for (int i = 0; i < size; i++)
        {
            if (s.top() == '(')
            {
                if (bracketCnt_S)
                {
                    --bracketCnt_S;

                    if (bracketCnt_S < 0)
                    {
                        cout << "NO" << "\n";
                        isBracketClose = true;
                        break;
                    }

                }
            }

            else if (s.top() == ')')
            {
                ++bracketCnt_S;
            }

            else if (s.top() == '[')
            {
                if (bracketCnt_S)
                {
                    --bracketCnt_L;

                    if (bracketCnt_S < 0)
                    {
                        cout << "NO" << "\n";
                        isBracketClose = true;
                        break;
                    }
                }
            }

            else if (s.top() == ']')
            {
                ++bracketCnt_L;
            }
            s.pop();
        }
        // ####### 처리부 종료 ###########

        // 3. 출력

        if (!isBracketClose)
        {

        }

    }


    return 0;
}