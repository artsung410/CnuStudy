#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

// 랜덤 구현 : 몬스터위치, 탈출구 위치

// 몬스터(M)가 플레어어에따라 움직이도록 설정.

// 플레이어가 2번 움직였을때 몬스터가 1번움직이게

int main()
{
    char map[12][22]; // 맵 크기
    char player = 'O'; // 플레이어
    char finish = 'F'; // 목적지
    char monster = 'M'; // 몬스터
    char wall = '@'; // 벽
    char base = '^'; // 베이스
    char item = 'i';

    // 플레이어 좌표 생성하기
    int playerX = 1;
    int playerY = 1;

    // 랜덤입력을 위한 최대값 최소값 변수 선언
    srand(time(NULL));
    int sNum = 1;
    int bNum1 = 10;
    int bNum2 = 20;

    // 랜덤 탈출구 좌표 생성하기 (벽과 중복되지 않게 하기)
    int escapeI = rand() % (bNum1 - sNum + 1) + sNum;
    int escapeJ = rand() % (bNum2 - sNum + 1) + sNum;

    // 랜덤 몬스터 좌표 생성하기 (벽과 중복되지 않게 하기)
    int monsterX = rand() % (bNum2 - sNum + 1) + sNum;;
    int monsterY = rand() % (bNum1 - sNum + 1) + sNum;

    // 랜덤 아이템 좌표 생성하기 (벽과 중복되지 않게 하기)
    int item1X = rand() % (bNum2 - sNum + 1) + sNum;
    int item2X = rand() % (bNum2 - sNum + 1) + sNum;
    int item3X = rand() % (bNum2 - sNum + 1) + sNum;

    int item1Y = rand() % (bNum1 - sNum + 1) + sNum;
    int item2Y = rand() % (bNum1 - sNum + 1) + sNum;
    int item3Y = rand() % (bNum1 - sNum + 1) + sNum;

    bool isItem1 = true;

    // 게임끝낼 트리거 만들기 (while문 탈출하기 위함)
    bool gameOver = false;

    // 플레이어 턴 계산.
    int playerState = 0;

    // 스코어
    int score = 0;


    while (!gameOver)
    {
        switch (_getch())
        {
        case 'w'/*w ↑*/:
            if (playerY > 1)
            {
                --playerY;
                ++playerState;
            }
            break;

        case 'a' /*a ←*/:
            if (playerX > 1)// 범위 밖인지 체크
            {
                --playerX;
                ++playerState;
            }
            break;

        case 's' /*s ↓*/:
            if (playerY < 10) // 범위 밖인지 체크
            {
                ++playerY;
                ++playerState;
            }
            break;

        case 'd' /*d →*/:
            if (playerX < 20) // 범위 밖인지 체크
            {
                ++playerX;
                ++playerState;
            }
            break;

        default:
            break;
        }

        system("cls"); // 루프가 한번 돌면 화면을 초기화 시킨다.


        // 맵초기화
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 22; j++)
            {
                map[i][j] = base; // 배열로 선언한 map[][]에 #담기
                map[escapeI][escapeJ] = finish; // 목적이 위치 선언 (고정)
                map[playerY][playerX] = player; // 플레이어 위치 선언 (변동)
                map[monsterY][monsterX] = monster; // 몬스터 위치 선언 (변동)

                if (isItem1)
                    map[item1Y][item1X] = item;

                if (i == 0 || i == 11 || j == 0 || j == 21)
                {
                    map[i][j] = wall; // i, j가 맵 끝부분에 위치할때마다 벽 생성
                }
                cout << map[i][j]; // 담은 맵 최초 출력
            }
            cout << "" << endl; // 담은 맵 최초 출력
        }

        // 플레이어가 2턴움직이면 몬스터도 움직이도록 조건문 설정
        if (playerState == 2)
        {
            playerState = 0; // 플레이어가 2턴움직이면 playerState 를 0으로 초기화
            if ((monsterX > playerX) && !(monsterX == 1))
            {
                --monsterX;
            }
            else if ((monsterX < playerX) && !(monsterX == 20))
            {
                ++monsterX;
            }
            else if ((monsterY > playerY) && !(monsterX == 1))
            {
                --monsterY;
            }
            else if ((monsterY < playerY) && !(monsterX == 20))
            {
                ++monsterY;
            }
        }

        // 플레이어 와 몬스터의 좌표가 같으면 게임 오버.
        if (map[playerY][playerX] == map[monsterY][monsterX])
        {
            cout << "Game Over" << endl;
            gameOver = true;
        }

        // 플레이어 좌표와 목적지 좌표가 같으면 게임 승리.
        if (map[playerY][playerX] == map[escapeI][escapeJ])
        {
            cout << "게임에서 승리하셨습니다." << endl;
            gameOver = true;
        }

        if (map[playerY][playerX] == map[item1Y][item1X])
        {
            isItem1 = false;
            map[item1Y][item1X] = base;
            score += 50;
        }

        cout << "---------------------------" << endl;
        cout << "현재 턴 : " << playerState << endl;
        cout << "Score : " << score << endl;
        cout << "---------------------------" << endl;

    }
}