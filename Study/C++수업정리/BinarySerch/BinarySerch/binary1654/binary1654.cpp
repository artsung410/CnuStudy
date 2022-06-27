#include <iostream>
#include <algorithm>

using namespace std;


using ll = long long; // 오버플로우 방지하기 위해 long long 타입 사용

ll K, N;
ll lan[10000];
ll temp;

int main()
{
    // 1. K와 N을 입력받는다.
    cin >> K >> N;

    // 2. 갖고 있는 랜선의 길이를 입력 받는다.
    for (ll i = 0; i < K; ++i)
    {
        cin >> lan[i];
        temp = std::max(lan[i], temp);
    }

    // 3. 이진검색
    // 범위 : 자를 수 있는 랜선의 길이
    // [l, M + 1]
    // [ 1, 458)
    ll s = 1, e = temp + 1;

    ll result = 0; // 실제 문제에 대한 해

    while (s < e)
    {
        // 해가 될 수 있는 후보
        ll m = (s + e) / 2;

        // s : l, e : 225, m : 229

        // m의 길이로 잘랐을 때 얻을 수 있는 랜선의 개수
        ll count = 0;

        for (int i = 0; i < K; i++)
        {
            count += lan[i] / m;
        }

        // 해
        // [115 ~ 229]
        if (count >= N)  // m이 더 커야지 count가 작아진다. 
        {
            if (result < m)
            {
                result = m;
            }

            s = m + 1;
        }
        else
        {
            e = m;
        }
    }

    cout << result;
}
