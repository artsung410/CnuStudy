#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    // strlen(word)
    // [입력]
    char words[16] = "";
    scanf("%s", &words);

    // [처리]
    // 1. 시간을 구하려면 숫자를 알아야함.
    // 2. 숫자를 알려면 알파벳을 대응하는 숫자로 변환.
    // W A -> 9 2 -> 10 + 3 -> 13 // U N U C I C

    // [출력]
    // 1. 그 다이얼을 걸기 위해 필요한 최소 시간
    //                   a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
    int alphabet[26] = { 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9 };

    int time = 0;
    for (int i = 0; words[i] != NULL; ++i)
    {
        for (int j = 0; words[j] != NULL; j++)
        {
            alphabet
        }
    }
}
