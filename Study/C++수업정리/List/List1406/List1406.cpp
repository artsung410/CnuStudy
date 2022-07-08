#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    // 0. 입출력 속도를 향상시킨다
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1. 문자열을 입력 받는다
    string inputStr; 
    cin >> inputStr; 

    list<char> list(inputStr.begin(), inputStr.end()); 
    std::list<char>::iterator cursor = list.end(); 

    // 2. 명령어의 개수를 입력받는다.
    int actionNum;
    cin >> actionNum; 


    // 3. 명령어를 처리한다.
    while (actionNum > 0)
    {

        // 3-1. 명령어을 입력받는다.
        char inputChar; 
        cin >> inputChar;


        // 3-2. 각 명령어에 맞게 실행한다.
        switch (inputChar)
        {
        case 'L':
            if (cursor != list.begin()) 
            {
                --cursor; 
            }
            break;

        case 'D':
            if (cursor != list.end())
            {
                ++cursor; 
            }
            break;

        case 'B':
            if (cursor != list.begin()) 
            {
                --cursor; 
                cursor = list.erase(cursor); // 반복자는 무효할 수 있기때문에, cursor에다가 담아주어야한다.
            }
            break;

        case 'P':
            char pushChar; 
            cin >> pushChar;
            list.insert(cursor, pushChar);
            break;
        }

        --actionNum;
    }
    

    for (std::list<char>::iterator cursor = list.begin(); cursor != list.end(); ++cursor)
    {
        cout << *cursor;
    }

    return 0;
}
