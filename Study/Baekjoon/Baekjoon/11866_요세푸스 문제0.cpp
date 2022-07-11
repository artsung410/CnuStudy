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
    std::queue<int> q2;

    int action;
    cin >> action;

    int cycle;
    cin >> cycle;

    for (int i = 1; i < action + 1; i++)
    {
        q.push(i);
    }

    int cnt = 0;

    while (!(q.size() == (cycle - 1)))
    {
        if (cnt % cycle == 0)
        {
            q2.push(q.front());
        }
        else
        {
            q.push(q.front());

        }
        q.pop();
        ++cnt;
    }

    for (int i = 1; i < action; i++)
    {
        cout << q2.front() << "\n";
        q2.pop();
    }
}

