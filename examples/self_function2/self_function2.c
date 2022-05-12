#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>



int N;

const char* str[4] = 
{
    "\"재귀함수가 뭔가요?\"", 
    "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.", 
    "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
    "그의 답은 대부분 옳았다고 하네.그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
};

void PrintWithTab(int tabCount, const char* str)
{
    for (int i = 0; i < tabCount; ++i)
    {
        printf("____");
    }
    puts(str);
}

void Dochatbot(int count)
{
    // 기저 조건
    if (count == N)
    {
        PrintWithTab(count, str[0]);
        return;
    }

}

int main()
{
    scanf("%d", &N);

    printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
    Dochatbot(N);
}