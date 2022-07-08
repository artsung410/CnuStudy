#include <iostream>
#include <string>

using namespace std;

int main()

{
    string s = "Hello Wrold";


    s.erase(3, 1);

    string::iterator iter = s.begin();
    ++iter;
    s.erase(iter);

    cout << s;
}
