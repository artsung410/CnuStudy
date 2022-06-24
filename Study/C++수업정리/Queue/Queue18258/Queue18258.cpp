#include <queue> // std::queue를 사용하기 위한 헤더
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    std::queue<int> q;

    int action;
    cin >> action;

    for (int i = 0; i < action; i++)
    {
        string myStr;
        cin >> myStr;

        if (myStr == "push")
        {
            int pushNum;
            cin >> pushNum;
            q.push(pushNum);

        }

        else if (myStr == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << "\n";
                q.pop();
            }
            else
            {
                cout << -1 << "\n";
            }
        }

        else if (myStr == "size")
        {
            cout << q.size() << "\n";
        }


        else if (myStr == "empty")
        {
            if (!q.empty())
            {
                cout << 0 << "\n";
            }
            else
            {
                cout << 1 << "\n";
            }
        }

        else if (myStr == "front")
        {
            if (!q.empty())
            {
                cout << q.front() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }
        
        else if (myStr == "back")
        {
            if (!q.empty())
            {
                cout << q.back() << "\n";
            }
            else
            {
                cout << -1 << "\n";
            }
        }

    }

    return 0;

}