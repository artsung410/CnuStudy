#include <iostream>
#include <stack>
#include <string>

using namespace std;

int BracketCnt = 0;
bool isBracketClose = false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int action;
    cin >> action;
    std::stack<char> s;

    int size = 0;
    while (action > 0)
    {
        // 1. 입력
        string Brackets;
        cin >> Brackets;


        // 2. 처리
        for (int i = 0; i < Brackets.size(); i++)
        {
            s.push(Brackets[i]);
        }

        size = s.size();

        // 3. 출력
        for (int i = 0; i < size; i++)
        {
            if (s.top() == '(')
            {
                if (i == 0 || BracketCnt == 0)
                {
                    // 첫번째 부터 (가 나오면 NO를 반납
                    cout << "NO" << "\n";
                    isBracketClose = true;
                    break;
                }

                // )모양 카운트가 1이상이면 ( 카운트를 1없애준다.
                else if (BracketCnt > 0)
                {
                    --BracketCnt;

                    if (BracketCnt < 0)
                    {
                        cout << "NO" << "\n";
                        isBracketClose = true;
                        break;
                    }
                }
            }

            if (s.top() == ')')
            {
                ++BracketCnt; // )
            }
            s.pop();
        }

        if (!isBracketClose)
        {
            if (BracketCnt > 0)
            {
                cout << "NO" << endl;
            }

            if (BracketCnt == 0)
            {
                cout << "YES" << endl;
            }
        }

        BracketCnt = 0;
        isBracketClose = false;

        while (!s.empty())
        {
            s.pop();
        }
        --action;
    }

}
