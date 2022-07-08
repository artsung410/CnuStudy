#include <iostream>
#include <stack>

using namespace std;

int totalNum = 0;

int main()
{
    std::stack<int> s;

    int action;
    cin >> action;

    while (action > 0)
    {
        int JaminNum;
        cin >> JaminNum;

        if (JaminNum == 0 && action != 0)
        {
            s.pop();
        }

        if (JaminNum != 0)
        {
            s.push(JaminNum);
        }

        --action;
    }

    int newSize = s.size();

    for (int i = 0; i < newSize; i++)
    {
        totalNum += s.top();
        s.pop();
    }

    cout << totalNum << "\n";

}
