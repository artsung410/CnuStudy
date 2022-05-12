#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <assert.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <stdbool.h>
#include <stdint.h>
#include <windows.h>

// 문자 출력 : printf() / putchar()

// 커서 이동 : SetConsoleCursorPosition

// 입력 : GetAsyncKeyState()

struct player
{
    int X; // 플레이어 초기 X좌표 선언
    int Y; // 플레이어 초기 Y좌표 선언
    COORD Pos;
    HANDLE h;

}player, bullet;

void main() 
{
    player.X = 0; // 플레이어 초기 X좌표 선언
    player.Y = 0; // 플레이어 초기 Y좌표 선언

    bullet.X = 0; // 총알초기 X좌표 선언
    bullet.Y = 0; // 총알초기 Y좌표 선언
    clock_t s_prevTick = 0; // 총알 발사 시점을 담는 변수 선언

    int bulletPosCount = 0; // 불렛 포지션을 증가시키기 위한 변수 선언
    bool isBullet = false; // 불렛이 발사 되었을때, true, 아니면 false

    while(1)
    {
        clock_t currentTick = clock(); // 현재 시간을 초기화 한다.
        system("cls"); // 화면을 초기화 시켜준다. 

        // 키를 하나만 눌렀을 때 [입력]
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) 
        { 
            player.X--;
        }

        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) 
        { 
            player.X++;
        }

        if (GetAsyncKeyState(VK_UP) & 0x8000) 
        { 
            player.Y--;
        }

        if (GetAsyncKeyState(VK_DOWN) & 0x8000) 
        { 
            player.Y++;
        }

        // 키 두개 동시에 눌렀을때 [입력]
        if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_UP))
        {
            player.X--;
            player.Y--;
        }
  
        if (GetAsyncKeyState(VK_LEFT) && GetAsyncKeyState(VK_DOWN))
        {
            player.X--;
            player.Y++;
        }

        if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_DOWN))
        {
            player.X++;
            player.Y++;
        }

        if (GetAsyncKeyState(VK_RIGHT) && GetAsyncKeyState(VK_UP))
        {
            player.X++;
            player.Y--;
        }

        // 키 두개 동시에 눌렀을때 / 총알 발사상태가 활성화 상태가 아닐때 [입력]
        if (GetAsyncKeyState(VK_SPACE) & 0x8000 && isBullet != true)
        {
            bullet.X = player.X; // 총알 초기좌표에 현재 플레이어 좌표를 저장한다.
            bullet.Y = player.Y; // 총알 초기좌표에 현재 플레이어 좌표를 저장한다.
            s_prevTick = clock(); // 총알을 처음 발사 했을때, 초기시간을 담는다.
            isBullet = true;  // 총알 발사상태를 활성화 시킨다.
        }


        // [처리]
        COORD playerPos = { player.X, player.Y }; // 포지션 업데이트
        HANDLE hPlayerPos = GetStdHandle(STD_OUTPUT_HANDLE); // 핸들값 변수 담기.
        SetConsoleCursorPosition(hPlayerPos, playerPos); // 좌표 초기화
        printf("P"); // 플레이어 좌표를 printf로 움직여 준다.[출력]


        if (isBullet) // 스페이스바가 눌리고 isBullet 상태이면
        {
            float deltatime = (float)(currentTick - s_prevTick) / CLOCKS_PER_SEC; // 총알의 현재시간에서 초기시간의 차를해서 델타 타임을 구한다

            COORD BulletPos = { bullet.X + bulletPosCount, bullet.Y }; // 불렛좌표를 더해서 실시간으로 업데이트 시킨다.
            HANDLE hBulletPos = GetStdHandle(STD_OUTPUT_HANDLE); // 핸들값 변수 담기.
            SetConsoleCursorPosition(hBulletPos, BulletPos); // 좌표 초기화
            printf("○"); // 총알을 출력해준다.[출력]

            if (deltatime > 3.0f) // 경과시간이 3초이상이 되면
            {

                bulletPosCount = 0; // bulletcount를 0으로 초기화
                s_prevTick = currentTick; // 현재시간과 초기화 시킨다.
                isBullet = false; // 총알 발사상태를 비활성화 시킨다.
            }

            ++bulletPosCount; // 3초가 될때까지 bulletPosCount를 더해준다.
        }

    }
}

