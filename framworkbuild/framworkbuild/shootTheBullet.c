#include <stdio.h>
#include <Windows.h>
#include <time.h>
#include <stdbool.h>


struct Player
{
	int posX;
	int posY;

}player;

struct Bullet
{
	int posX;
	int posY;
	float aliveTime;
	bool shoot;
	bool alive;

}bullet;

int main(void)
{
	clock_t prevTic = clock();

	while (1)
	{
		system("cls");
		/*char map[30][120] = {""};
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 120; j++)
			{
				map[i][j] = '#';
				printf("%c", map[i][j]);
			}
				printf("\n");
		}*/
#pragma region 입력

		//입력 : GetAsyncKeyState()
		if (GetAsyncKeyState(VK_DOWN))
		{
			++player.posY;
			if (player.posY > 30)
			{
				--player.posY;
			}
		}

		if (GetAsyncKeyState(VK_UP))
		{
			--player.posY;
			if (player.posY < 0)
			{
				++player.posY;
			}
		}

		if (GetAsyncKeyState(VK_LEFT))
		{
			--player.posX;
			if (player.posX < 0)
			{
				++player.posX;
			}
		}

		if (GetAsyncKeyState(VK_RIGHT))
		{
			++player.posX;
			if (player.posX > 100)
			{
				--player.posX;
			}
		}

		if (GetAsyncKeyState(VK_SPACE) & 0x0001 && bullet.alive == false)
		{
			bullet.shoot = true;
		}

#pragma endregion

#pragma region 처리?

		COORD bulletPos = { bullet.posX, bullet.posY };						
		if (bullet.shoot)
		{
			bullet.posX = player.posX + 1;								
			bullet.posY = player.posY;										
			//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bulletPos);
			bullet.alive = true;											
			bullet.shoot = false;
		}

		// 델타타임 구현
		clock_t currntTic = clock();
		float deltaTime = (float)(currntTic - prevTic) / CLOCKS_PER_SEC;
		prevTic = currntTic;

/*
		// 최근 틱 = 0;
		// 이전 틱 = 0;

		//반복문
		// 시작
		// 최근 틱 = 현재 틱 
		// 결과 = 최근 틱 - 이전 틱
		// 이전 틱 = 최근 틱
		// 프레임 진행

		// 최근 0
		// 0 = 0 - 0
		// 이전 0 = 0

		// 최근 1
		// 결과 = 1 - 0
		//총알

*/

		if (bullet.alive == true)
		{
			//델타타임 더해주는 변수추가
			bullet.posX++;													
			bullet.aliveTime += deltaTime;
			if (bullet.aliveTime > 3.0f)
			{
				bullet.alive = false;
				bullet.aliveTime = 0;
			}
		}

#pragma endregion

#pragma region 출력

		//움직일 문자
		COORD playerPos = { player.posX, player.posY };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPos); 
		printf("P");

		if (bullet.alive)													
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bulletPos); 
			printf("총알~");													
		}

#pragma endregion

		
		// 총알의 속성
		// 모양
		// 좌표
		// 이동속도
		// 생존시간

		// 총알의 상태
		// 생성
		//  - 플레이어 위치 앞에 모양으로 생성
		// 이동
		// - 이동속도만큼 좌표가 변경
		// 삭제
		// - 생존시간이 넘으면 삭제(출력 않는다)

		//델타타임을 이용해서 1씩 움직이기

	}
}