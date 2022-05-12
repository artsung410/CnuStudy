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
	bool alive;

}bullet;

int main(void)
{
	clock_t prevTic = clock(); //한번만실행
	float totalDeltaTime = 0;

	while (1)
	{
		system("cls");

#pragma region 입력
		//입력 : GetAsyncKeyState()
		if (GetAsyncKeyState(VK_DOWN))
		{
			++player.posY;
		}
		if (GetAsyncKeyState(VK_UP))
		{
			--player.posY;
		}
		if (GetAsyncKeyState(VK_LEFT))
		{
			--player.posX;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			++player.posX;
		}

#pragma endregion

#pragma region 처리?

		//움직일 문자
		COORD playerPos = { player.posX, player.posY };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), playerPos);
		printf("P");

		COORD bulletPos = { bullet.posX, bullet.posY };						// 여기가 총알 초기 좌표
		if (GetAsyncKeyState(VK_SPACE) & 0x0001 && bullet.alive == false)	// 스페이스바 입력받음 && 총알 나가는 동안 입력 안받음
		{
			bullet.posX = player.posX + 1;									// 총알은 플레이어 앞에서 나간다 여기가 총알 시작위치
			bullet.posY = player.posY;										// y좌표에 플레이어 좌표 표시해줌 
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bulletPos);
			bullet.alive = !bullet.alive;									// 스페이스바 누르면 bool값이 true로 바뀐다
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


		//델타타임 더해주는 변수추가
		totalDeltaTime += deltaTime;
		if (totalDeltaTime > 3.0f)
		{
			bullet.alive = false;
			totalDeltaTime = 0; // 다시 0으로 초기화
		}
#pragma endregion

#pragma region 출력

		if (bullet.alive)													// true로 바뀌면 여기가 실행되고
		{
			bullet.posX++;													// 여기가 x좌표가 증가하는부분이고 <- 얘가 계속 증가댐
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bulletPos); // 증가된 좌표를 여기서 다시 표시해줌
			printf("O");													// 좌표가 변화될때마다 총알 출력
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