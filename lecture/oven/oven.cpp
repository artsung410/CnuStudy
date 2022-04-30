#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int hour;
    int min;
    int min1;

    scanf("%d %d %d", &hour, &min, &min1);

    int addHour = (min + min1);

    if (addHour >= 60)
    {
        hour = hour + (addHour / 60);
        hour = hour % 24;
        addHour = addHour % 60;
    }

    printf("%d %d", hour, addHour);
}