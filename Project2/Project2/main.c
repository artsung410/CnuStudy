#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>

#define DELTA_TIME (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC
#define BULLET_HOLDING_TIME 3.0
#define BULLET_SPEED 20
#define MAP_SIZE_MIN 0
#define MAP_SIZE_MAX 30

struct object
{
    int X;
    int Y;

}player, bullet, monster, title1, title2, title3;

int main()
{
    title1.X = 11;
    title1.Y = 0;

    title2.X = 25;
    title2.Y = 10;

    title3.X = 33;
    title3.Y = 20;

    player.X = 1;
    player.Y = 1;

    bullet.X = 0;
    bullet.Y = 0;

    clock_t s_prevTick = 0;
    clock_t currentTick = 0;

    bool isBullet = false;
    bool isMonster = false;

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD titlePos1 = { 0, 0 };
    COORD titlePos2 = { 0, 0 };
    COORD titlePos3 = { 0, 0 };

    while (1)
    {
        currentTick = clock() * 15;

        COORD titlePos1 = { title1.X, title1.Y + (int)DELTA_TIME };
        SetConsoleCursorPosition(h, titlePos1);
        printf("스페이스키를");

        COORD titlePos2 = { title2.X, title2.Y };
        SetConsoleCursorPosition(h, titlePos2);
        printf("누르면");

        COORD titlePos3 = { title3.X, title3.Y - (int)DELTA_TIME };
        SetConsoleCursorPosition(h, titlePos3);
        printf("다음으로 넘어갑니다.");

        if (title3.Y - (int)DELTA_TIME == title1.Y + (int)DELTA_TIME)
        {
            COORD pressAnyKey = { 25, 5 };
            SetConsoleCursorPosition(h, pressAnyKey);
            printf("Press Any Key");
            getch();
            break;
        }
        system("cls");
    }

    while (1)
    {
        // 방향키 [입력]

        if (GetAsyncKeyState(VK_LEFT) && (player.X > MAP_SIZE_MIN))
        {
            player.X--;
        }

        if (GetAsyncKeyState(VK_RIGHT) && (player.X < MAP_SIZE_MAX))
        {
            player.X++;
        }

        if (GetAsyncKeyState(VK_UP) && (player.Y > MAP_SIZE_MIN))
        {
            player.Y--;
        }

        if (GetAsyncKeyState(VK_DOWN) && (player.Y < MAP_SIZE_MAX))
        {
            player.Y++;
        }

        // 총알발사 [입력]
        clock_t currentTick = clock();
        if (GetAsyncKeyState(VK_SPACE) && isBullet != true)
        {
            bullet.X = player.X + 1;
            bullet.Y = player.Y;
            s_prevTick = currentTick;
            isBullet = true;
        }

        // 플레이어 이동 [처리]
        COORD playerPos = { player.X, player.Y };

        // 총알발사 [처리]
        if (isBullet)
        {
            COORD bulletPos = { bullet.X + DELTA_TIME * BULLET_SPEED, bullet.Y };
            HANDLE bulletHandle = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bulletPos);
            printf("○"); // 총알을 출력해준다.[출력]

            if (DELTA_TIME >= BULLET_HOLDING_TIME)
            {
                s_prevTick = currentTick;
                isBullet = false;
            }
        }

        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPos);
        printf("P"); // 플레이어 화면 [출력]
        //Sleep(5);

        system("cls"); // 화면을 초기화 시켜준다. 
    }

    return 0;
}
