#include <iostream>
#include <string>
#include <list>


// 2. 각 문자를 적절하게 처리한다.
// 3. 알파벳 대소문자, 숫자, 백스페이스(-), 화살표(<>)
int main()
{
    int actionNum;
    std::cin >> actionNum;

    for (; actionNum > 0; --actionNum)
    {
        std::list<char> Line;
        std::list<char>::iterator cursor = Line.begin();

        // 1. 문자열을 입력 받는다.
        std::string pW;
        std::cin >> pW;

        for (int i = 0; i < pW.length(); i++)
        {
            if (pW[i] == '<')
            {
                if (cursor != Line.begin())
                {
                    cursor--;
                }
            }

            else if (pW[i] == '>')
            {
                if (cursor != Line.end())
                {
                    cursor++;
                }
            }

            else if (pW[i] == '-')
            {
                if (cursor != Line.begin())
                {
                    cursor--;
                    cursor = Line.erase(cursor);
                }
            }

            else
            {
                Line.insert(cursor, pW[i]);
            }
        }

        for (std::list<char>::iterator iter = Line.begin(); iter != Line.end(); iter++)
        {
            std::cout << *iter;
        }

        std::cout << "\n";
    }


    return 0;
}
