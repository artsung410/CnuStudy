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

    for (int i = 1; i < action + 1; i++)
    {
        q.push(i);
    }

    while (!(q.size() == 1))
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }

    cout << q.front();

    return 0;
}
