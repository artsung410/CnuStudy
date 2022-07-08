#include <iostream>
#include <algorithm>

using namespace std;
#define MAXNUM 500000

int nums[MAXNUM];
int key[MAXNUM];
int zeroCount[MAXNUM];

int temp;

int main()
{
    int N;

    std::cin >> N;

    // 상근이 카드 담기..
    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
        temp = std::max(nums[i], temp);
    }
 
    sort(nums, nums + N);


    int phase;
    cin >> phase;

    // 맞춰야할 숫자 담기.
    for (int i = 0; i < phase; ++i)
    {
        cin >> key[i];
    }

    int s = 1, e = temp;

    while (s < e)
    {
        // 중간 지점 구하고
        int m = (s + e) / 2;

        // 비교하고
        if (arr[m] == num)
        {
            isExist = true;
            break;
        }

        // 그거에 따라서 범위 조정
        else if (arr[m] < num)
        {
            s = m + 1;
        }

        else
        {
            e = m;
        }
    }

    for (int i = 0; i < phase; i++)
    {
        cout << zeroCount[i] << " ";
    }
}


// 첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수

// 둘째 줄에는 숫자카드에 적혀있는 정수

// 셋제쭐에는 값이 주어진다.

// 넷제 줄에는

