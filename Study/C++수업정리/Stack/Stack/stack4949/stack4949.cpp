#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    while (1)
    {
        // 1. 입력
        std::string inputStr;
        getline(cin, inputStr);


        // 글자가 하나고 점일때 탈출..
        std::stack<char> s;
        bool result = true;

        if (inputStr == ".")
        {
            break;
        }

        // // 2. 처리 : 스택에 요소를 담는다.
        for (int i = 0; i < inputStr.length(); i++)
        {
            if (inputStr[i] == '(' || inputStr[i] == '[')
            {
                s.push(inputStr[i]);
            }

            if (inputStr[i] == ')')
            {
                if (s.empty() || s.top() == '[')
                {
                    result = false;
                }
                else
                {
                    s.pop();
                }

            }

            if (inputStr[i] == ']')
            {
                if (s.empty() || s.top() == '(')
                {
                    result = false;
                }
                else
                {
                    s.pop();
                }
            }
        }

        if (s.empty() && result)
        {
            cout << "yes" << '\n';
        }
        else
        {
            cout << "no" << '\n';
        }

    }
    return 0;
}