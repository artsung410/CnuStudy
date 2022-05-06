#define _CRT_SECURE_NO_WARNINGS 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// 파일 입출력
int main(void)
{
    //// 1. 파일을 다루기 위한 객체 생성
    //FILE* fp = NULL;

    //// -------------------------------
    //// 텍스트 파일
    //// -------------------------------

    //// 2. 파일을 연다.
    //// 1) 텍스트 파일 : 텍스트 에디터로 열 수 있는 파일로 우리가 읽을 수 있는 문자로 구성
    //// 2) 바이너리 파일 : 그 외의 모든 파일

    //// Metaverse라는 이름을 가진 텍스트 파일을 연다.
    //if (0 != fopen_s(&fp, "Metaverse", "w"))
    //{
    //    printf("오류 발생함.");

    //    return 1;
    //}

    //// 3. 파일을 조작한다.
    //// 텍스트 파일에 작성할 수 있는 함수 : fputs() / fputc() / fprintf()
    //// 바이너리 파일에 작성할 수 있는 함수 : fwrite()
    //fputs("Hello File!", fp);
    //fputc('J', fp);
    //fprintf(fp, "\nThe name of the queen : %s\n", "퀸균지");

    //// 4. 파일을 닫는다.
    //fclose(fp);

    //if (0 != fopen_s(&fp, "Metaverse", "r"))
    //{
    //    printf("오류 발생함.");

    //    return 1;
    //}

    //// 텍스트 파일에서 읽어들일 수 있는 함수 : fgets() / fgetc() / fscanf()
    //// 바이너리 파일에서 읽어들일 수 있는 함수 : fread()
    //char ch = fgetc(fp);
    //char str[128] = "";
    //fgets(str, sizeof(str), fp); // 개행 문자까지 받아들인다.
    //char str2[128] = "";
    //fscanf_s(fp, "The name of the queen : %s", str2, sizeof(str2));

    //printf("읽어들인 문자 : %c\n", ch);
    //printf("읽어들인 문자열 : %s\n", str);
    //printf("퀸은 누구? : %s\n", str2);

    //fclose(fp);

    //// -------------------------------
    //// 바이너리 파일
    //// -------------------------------
    //if (0 != fopen_s(&fp, "Metaverse2", "wb"))
    //{
    //    printf("오류 발생함.");

    //    return 1;
    //}

    //struct Student
    //{
    //    int Age;                  // 4바이트
    //    enum { A, B, O, AB } BloodType;
    //    char Name[24];
    //};

    //struct Student s = { 20, A, "최선문" };

    //if (1 != fwrite(&s, sizeof(s), 1, fp))
    //{
    //    printf("오류 발생함.");

    //    fclose(fp);

    //    return 1;
    //}

    //fclose(fp);

    //if (0 != fopen_s(&fp, "Metaverse2", "rb"))
    //{
    //    printf("오류 발생함.");

    //    fclose(fp);

    //    return 1;
    //}

    //struct Student s2 = { 0 };
    //if (1 != fread(&s2, sizeof(s2), 1, fp))
    //{
    //    printf("오류 발생함.");

    //    fclose(fp);

    //    return 1;
    //}

    //printf("나이 : %d, 혈액형 : %d, 이름 : %s\n", s2.Age, s2.BloodType, s2.Name);

    //fclose(fp);

    //return 0;

    //const char* input = "이 시대의 진정한 퀸은 누구? 퀸균지";

    //char str[128] = "";
    //sscanf_s(input, "이 시대의 진정한 퀸은 누구? %s", str, (unsigned int)sizeof str);

    //char str2[128] = "";
    //sprintf_s(str2, sizeof(str2), "그렇다. 퀸은 %s였다.", str, sizeof str);

    //puts(str2);

    //return 0;

    printf("필요한 공간 개수를구")
    int* p = malloc(sizeof(int));


    //메모리를 수동으로 
    return 0;
}
