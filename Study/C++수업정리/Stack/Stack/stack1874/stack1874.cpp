#include <iostream>
#include <stack>


using namespace std;

int main()
{
    stack<int> s;
    int n;
    cin >> n;

    while (n > 0)
    {
        int inputNum;
        cin >> inputNum;

        s.push(inputNum);
        --n;
    }


    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }

}
