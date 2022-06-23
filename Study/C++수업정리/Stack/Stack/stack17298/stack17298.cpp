#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    std::stack<int> checkInit;
    std::vector<int> nge;

    int length; 

    // 1. 입력
    cin >> length;
    int* SeqArray = new int[length];

    for (int i = 0; i < length; i++)
    {
        cin >> SeqArray[i];

        if (i == 0)
        {
            checkInit.push(SeqArray[0]); // 맨아래층에는 무조건 쌓아둔다. 
        }

        else
        {
            for (int j = 0; j < length; j++)
            {
                if (SeqArray[j] > checkInit.top())
                {
                    checkInit.push(SeqArray[i]);
                    nge.push_back(SeqArray[i]); // 쌓아둔거 위에 큰수가 있으면, 벡터에다가 담아준다.
                }
            }
        }

    }

    // seqArray = 3, 5, 2, 7

    // 첫번째 쌓고 , 그위의 자신보다 큰수가 없으면 -1 반납 -> vector nge에 담는다. 
    // 첫번째 쌓고, 그위의 자신보다 바로 큰수가 있으면 그 큰수를 vector nge에 담는다. 


    int vecSize2 = nge.size();

    // 3. 출력
    for (int i = 0; i < vecSize2; i++)
    {
        cout << nge[i] << " ";
    }

    delete[] SeqArray;
}
