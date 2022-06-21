#include <iostream>
#include <string>
#include <list>

int main()
{
    int actionNum;
    std::cin >> actionNum;

    for (;actionNum > 0; --actionNum)
    {
        std::list<char> Line;
        std::list<char>::iterator cursor = Line.begin();

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

