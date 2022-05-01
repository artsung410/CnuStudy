#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//1546

int main()
{
    int num;
    scanf("%d", &num);
   
    int arr[1000] = {0}; int sum = 0;
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }


    float avg;
    avg = (float)sum / num;

    int maxNum = 0;
    for (int i = 0; i < num; i++)
    {
        if (num == 1)
        {
            maxNum = arr[i];
        }

        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                maxNum = arr[i];
            }
            else
            {
                maxNum = arr[j];
            }
        }
    }

    printf("%f", avg / maxNum * 100);

    return 0;
}

