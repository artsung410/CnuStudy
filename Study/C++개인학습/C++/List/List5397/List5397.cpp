#include <iostream>
#include <string>
#include <list>

int main()
{
    int actionNum; // 입력횟수 설정
    std::cin >> actionNum; // 입력횟수 입력 받기

    std::string inputStr; //연달아 있는 문자를 입력받기 위한 스트링 타입 변수 선언
    std::cin >> inputStr; // 스트링 입력받는다.
    
    std::string result;
    std::cin >> result;

    // 이중 연결리스트를 선언한다. (선언하는 이유 : --연산자를 이용해 주소를 왼쪽으로 이동하기 위해서)
    std::list<char> list(inputStr.begin(), inputStr.end());

    std::list<char>::iterator cursor = list.end(); // 리스트 형태의 반복자를 초기화 해준다

    while (actionNum > 0)
    {


        --actionNum;
    }

    for (std::list<char>::iterator cursor = list.begin(); cursor != list.end(); ++cursor)
    {
        std::cout << *cursor;
    }

    std::cout << std::endl;
    std::cout << result;
    return 0;
}

