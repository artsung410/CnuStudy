#include <iostream>
#include <vector>


// 정답이 들어있는 vec 선언, _size <= 10000

// 1번 수포자 12345/12345/12345
// 2번 수포자 21232425 /21232425 /21232425
// 3번 수포자 3311224455 /3311224455 /3311224455

// 1.  정답을 입력 받는다.

// 2. 

using namespace std;

vector<int> mathGiveUp1 = { 1, 2, 3, 4, 5 };
vector<int> mathGiveUp2 = { 2, 1, 2, 3, 2, 4, 2, 5 };
vector<int> mathGiveUp3 = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
vector<int> answer = { 3, 3, 3, 4, 5, 1, 2, 3, 4, 5, 3, 4, 2, 1 };

vector<int> soulution(answer)
{
    vector<int>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << *iter << endl;
    }

    vector<int> answer;
    return answer;

    std::cout << "Hello World!\n";
}

int main()
{

}
