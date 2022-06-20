#include <iostream>
#include <string>
#include <list>


int main()
{
    std::string inputStr; //연달아 있는 문자를 입력받기 위한 스트링 타입 변수 선언
    std::cin >> inputStr; // 스트링 입력받는다.

    // 이중 연결리스트를 선언한다. (선언하는 이유 : --연산자를 이용해 주소를 왼쪽으로 이동하기 위해서)
    // list 생성자에 스트링의 첫번째 주소와, 마지막 주소를 넣으면 자동으로 노드를 만들어 주는것 같다...
    std::list<char> list(inputStr.begin(), inputStr.end()); 

    std::list<char>::iterator cursor = list.end(); // 리스트 형태의 반복자를 초기화 해준다

    int actionNum; // 입력횟수 설정
    std::cin >> actionNum; // 입력횟수 입력 받기

    while (actionNum > 0)
    {
        char inputChar; 
        std::cin >> inputChar;// 대문자 입력 받기

        switch (inputChar)
        {
        case 'L':
            if (cursor != list.begin()) // cursor가 노드의 첫번째가 아닐 때
            {
                --cursor; // 커서 왼쪽으로 전환
            }
            break;

        case 'D':
            if (cursor != list.end()) // cursor가 노드의 마지막이 아닐 때
            {
                ++cursor; // 커서 오른쪽 으로 전환
            }

            break;

        case 'B':
            if (cursor != list.begin()) // cursor가 노드의 마지막이 아닐 때
            {
                --cursor; // 커서 왼쪽으로 전환
                cursor = list.erase(cursor); // □□■ ->  □■□  -> □■ cursor위치 삭제 후 현재 cursor주소 반환
            }
            break;

        case 'P':
            char pushChar; 
            std::cin >> pushChar;
            list.insert(cursor, pushChar); // 현재 커서주소 왼쪽에 문자 추가. 
            break;
        }

        --actionNum;
    }
    
    // 커서를 처음부터 마지막까지 탐색하면서 각 노드의 데이터를 반환.
    for (std::list<char>::iterator cursor = list.begin(); cursor != list.end(); ++cursor)
    {
        std::cout << *cursor;
    }

    return 0;
}
