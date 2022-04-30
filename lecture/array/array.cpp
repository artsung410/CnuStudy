#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// 최소값은 다른 모든 수 보다 작다.

// 최대값은 다른 모든 수 보다 크다.

// [][][][][]

// 첫 번째 원소를 후보로 등록
// 두 번째 원소부터 마지막 원소까지 비교하면서
// 1. 더 작은 애가 나오면 => 최솟값 업데이트
// 2. 더 큰 애가 나오면 -> 최댓값 업데이트
int main()
{
    int num; int minNum; int maxNum;

    scanf("%d", &num);
    int arr[num];
    int inputNum;

    for (int i = 0; i < num; i++)
    {
        scanf("%d", &inputNum);
        arr[i] = inputNum;
    }

    minNum = arr[0];
    maxNum = arr[0];

    for (int i = 0; i < num; i++)
    {
        if (minNum > arr[i])
        {
            minNum = arr[i];
        }

        else if (maxNum < arr[i])
        {
            maxNum = arr[i];
        }
    }
    printf("%d %d", minNum, maxNum);

    return 0;
}

