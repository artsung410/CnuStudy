#include <iostream>
#include <deque>
#include <stack>
#include <string>

using namespace std;
int main()
{
    deque<int> asdf;
    stack<int> s;

    int action;
    cin >> action;
    bool isError = false;

    while (action)
    {
        // 명령어 저장
        string orderAlphabet;
        cin >> orderAlphabet;
        char* orders = new char[orderAlphabet.size()]; // 명령어 담긴 배열
        
        for (int i = 0; i < orderAlphabet.size(); i++)
        {
            orders[i] = orderAlphabet[i];
        }

        // 숫자 담을 배열 만들기
        int numsSize;
        cin >> numsSize;

        // 문자열로 입력받은 배열처리
        int* arr = new int[numsSize]; // 숫자 담긴 배열

        for (int i = 0; i < numsSize; i++)
        {
            arr[i] = i + 1;
        }

        for (int i = 0; i < orderAlphabet.size(); i++)
        {
            switch (orderAlphabet[i])
            {
                // R -> 전체 배열 뒤집기
            case 'R':

                for (int i = 0; i < numsSize; i++)
                {
                    s.push(arr[i]);
                }

                break;

                // D -> 앞의 원소 삭제
            case 'D':
                s.pop();
                if (s.size() <= 1 )
                {
                    cout << "error" << endl;
                    isError = true;
                }
                break;
            }
        }

        // 출력
        if (isError == false)
        {
            while (!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
        }
        cout << "\n";


        // D ->
        isError = !isError;
        --action;
    }
}

//void R()
//{
//
//}

//void D()
//{
//
//}
