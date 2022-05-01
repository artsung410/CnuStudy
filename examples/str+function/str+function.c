#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

//char* strcpy(const char* s1, char* s2)
//{
//	while (*s1 != null)
//	{
//        *s2 = *s1; // 역참조를해서 값을 꺼내서 비교를 한다.
//
//        ++s1; ++s2; // str = str[0]이랑 같은뜻이다. 주소의 첫번째부터 1씩 더해주면 배열의 인덱스가 늘어난다.
//	}
//    return s2; // 최종적으로 str2를 반환한다.
//}
//
//char* strcat(char* s1, const char* s2)
//{
//    while (1)
//    {
//        ++s1; // 첫번째 문자열이 null을 만날때 까지 주소값을 +1씩 증가시킨다.
//        if (*s1 == null) // 첫번째 문자열의 값이 null을 만나면 
//        {
//            while (1) // 반복문에 진입을 한다.
//            {
//                *s1 = *s2; 
//                ++s1; ++s2; // 두번째 문자열의 값이 null을 만날때까지 주소값을 각각 +1씩 증가시킨다.
//                if (*s2 == null) // 두번째 문자열의 값이 null을 만나면
//                {
//                    break; // 제일 안쪽에 있는 while문을 탈출시킨다.
//                }
//            }
//            break; // 작업이 다 끝나면 바깥쪽 while문을 탈출시킨다.
//        }
//    }
//    return s1;  // 합치기가 끝나면 새로 만들어진 문자열을 반환한다.
//}

//int strlen(const char* s)
//{
//    int legnthcount = 0; // 문자하나하나 세기위한 카운트 변수 선언
//    while(*s != null) // 값이 null을 만날때까지
//    {
//        ++legnthcount; // 문자를 거치면 갯수를 세준다.
//        ++s; // 카운트가 끝나면 주소값을 +1씩 증가시킨다.
//    }
//    return legnthcount; // 작업이 완료되면 카운트된 값을 반환한다.
//}


//int strcmp(const char* s1, const char* s2)
//{
//    while(*s1 != NULL) // 값이 NULL을 만날때까지
//    {
//        ++s1; ++s2;
//        if (*s1 > *s2)
//            return 1;
//        if (*s1 < *s2)
//            return -1;
//    }
//    return 0; // 작업이 완료되면 카운트된 값을 반환한다.
//}

//char* strchr(const char* s, char ch)
//{
//    while (*s != NULL)
//    {
//        if (*s == ch)
//        {
//            return s;
//        }
//        ++s;
//    }
//    return NULL;
//}


//char* strrchr(const char* s, char ch)
//{
//    // 문자열  s = abcdefghijklmnkpop,  문자 ch = k
//
//    int arrIndex = 0;
//    int arrCount = 0;
//    while (*s != NULL)
//    {
//        if (*s == ch)
//        {
//            arrIndex = arrCount;
//        }
//        ++arrCount;
//        ++s;
//
//        if (*s == NULL)
//        {
//            return s - (arrCount - arrIndex);
//        }
//    }
//    return NULL;
//}

char* strstr(char* s1, const char* s2)
{
    // 긴문자  s1,  짧은문자 s2
    char* tmpS1 = s1;
    char* tmpS2 = s2;
    int sameCount = 0;
    int arrCount = 0;

    while (*s1 != NULL)
    {
        while (*s2 != NULL)
        {
            if (*s1 == *s2)
            {
                ++sameCount;
            }
            ++arrCount;
            ++s1; 
            ++s2;

            if (sameCount == arrCount && *s2 == NULL)
            {
                return s1 - sameCount;
            }
        }
        sameCount = 0;
        arrCount = 0;
        tmpS1 += 1;
        s1 = tmpS1;
        s2 = tmpS2; 
    }
    return NULL;
}

int main()
{
    // [strcpy] : 문자열 복사하기
    //const char* originStr = "Hello";
    //char reusltStr[10] = "";
    //strcpy(originStr, reusltStr);
    //printf("%s", reusltStr);


    // [strcat] : 문자열 이어붙이기
    //char addStr[100] = "abcdefg";
    //const char* originStr = "Hello";
    //strcat(addStr, originStr);
    //printf("%s", addStr);


    // [strlen] : 문자열의 길이 반환
    //int legnth;
    //const char* str = "asdfasdfasdf";
    //legnth = strlen(str);
    //printf("%d", legnth);
    

    // [strcmp] : 문자열 끼리 비교해서 문자끼리 같으면 0, 작으면 -1, 크면 1을 반환
    //const char* str1 = "abcda";
    //const char* str2 = "abcdw";
    //int result;
    //result = strcmp(str1, str2);
    //printf("%d", result);
    

    // [strchr] : 문자열에서 특정 문자 찾기 (최초 발견시 결과값 도출)
    //const char* str = "abcdefghijklmn";
    //char ch = 'k';
    //printf("%s", strchr(str, ch));


    // [strrchr] : 문자열에서 특정 문자 찾기 (전체 탐색후 결과값 도출)
    //const char* str = "abcdefghijklmnkpop";
    //char ch = 'k';
    //printf("%s", strrchr(str, ch));


    // [strstr] : 문자열에서 특정 단어 찾기
    char* str1 = "abcdefghijklmn";
    const char* str2 = "ijk";
    printf("%s", strstr(str1, str2));

    return 0;
}

