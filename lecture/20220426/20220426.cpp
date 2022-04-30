#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int diceA;
    int diceB;
    int diceC;

    scanf("%d %d %d", &diceA, &diceB, &diceC);
    

    if ((diceA == diceB) && (diceB == diceC))
    {
        printf("%d", diceA * 1000 + 10000);
    }

    else if (diceA == diceB || diceC == diceA)
    {
        printf("%d", diceA * 100 + 1000);
    }

    else if (diceB == diceC)
    {
        printf("%d", diceB * 100 + 1000);
    }
    else
    {
        if (diceA > diceB && diceA > diceC)
        {
            printf("%d", diceA * 100);
        }
        else if (diceB > diceC)
        {
            printf("%d", diceB * 100);
        }
        else
        {
            printf("%d", diceC * 100);
        }
    }
}
