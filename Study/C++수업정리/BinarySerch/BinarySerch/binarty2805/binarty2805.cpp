#include <iostream>
#include <algorithm>

using namespace std;


using ll = long long; // 오버플로우 방지하기 위해 long long 타입 사용

ll N, M;
ll namu[1000000];
ll temp;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 1. K와 N을 입력받는다.
    cin >> N >> M;

    // 2. 갖고 있는 나무의 길이를 입력받는다.
    for (ll i = 0; i < N; ++i)
    {
        cin >> namu[i];
        temp = std::max(namu[i], temp);
    }

    ll s = 1, e = temp + 1;

    ll H = 0; 

    while (s < e)
    {
        ll m = (s + e) / 2;

        ll count = 0;

        for (int i = 0; i < N; i++)
        {
            if (namu[i] > m)
            {
                count += (namu[i] - m);
            }
        }

        if (count >= M) // 
        {
            if (H < m)
            {
                H = m;
            }

            s = m + 1;
        }

        else
        {
            e = m;
        }
    }
    cout << H;
}
