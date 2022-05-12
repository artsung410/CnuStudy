#include <iostream>



// N(1 <= N <= 20)

int N;

void CountHanoi(int count, int s, int m, int e)
{
    if (count = 1)
    {
        ++N;

        return;
    }

    CountHanoi(count - 1, s, e, m);
    CountHanoi(1, s, m, e);
    CountHanoi(count - 1, m, s, e);
}

//반환값 : 수행 횟수
int Hanoi(int numberOfDisc, int startPos, int viaPos, int targetPos)
{
    if (numberOfDisc == 1)
    {
        printf("%d %d", startPos, targetPos);
    }
    Hanoi(numberOfDisc - 1, startPos, targetPos, viaPos);
    Hanoi(1, startPos, viaPos, targetPos);
    Hanoi(numberOfDisc - 1, viaPos, startPos, targetPos);
}

int main()
{
    
}

// 7
// 1 3 arr1 -> arr2
// 1 2 arr2 -> arr3
// 3 2 arr3 -> arr2
// 1 3 arr1 -> arr3
// 2 1 arr2 -> arr1
// 2 3 arr2 -> arr3
// 1 3 arr1 -> arr3

