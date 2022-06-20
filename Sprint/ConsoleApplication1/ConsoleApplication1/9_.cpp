/*
10X10 타일 위에서 진행되는 영웅의 모험 게임
- 화면은 초당 30프레임으로 갱신됩니다. pass

- 게임이 시작되면 영웅은 좌상단에, 탈출점은 좌하단에, 상점은 두 지점을 제외한 지점에 생성되며 전체 맵을 4분할한 각 구역마다 랜덤한 위치로 한개씩 생성됩니다.
- 영웅은 WASD를 누르면 상하좌우로 한 칸씩 이동합니다.
- 영웅은 이 이동하면 이동한 지역의 안전도에 따라 랜덤하게 몬스터가 출몰합니다. ( 위험할 수록 출몰 확률이 높아지고 더 센 몬스터가 나옴 )
- 영웅과 몬스터는 홀/짝 맞추기 대결을 합니다. 영웅이 이기면 상대의 HP가, 상대가 이기면 영웅의 HP가 1씩 줄어듭니다.
- 영웅은 상점에서 돈을 주고 물약을 구매할 수 있습니다.
- 가능하면 전처리기를 사용해 게임의 기본 설정을 바꿀 수 있게 해 봅시다. ( 맵의 가로 세로 크기, 난이도 등 )
- 가능하면 메인 함수 외의 나머지 함수들은 소스 파일을 나누어 다른 소스 파일에 제작될 수 있게 해 봅시다.

- 다음의 항목을 가진 구조체를 사용합니다.
 1) 타일 : 타일의 타입(숲,늪,평지),안전도(안전,위험,매우위험)
 2) 몬스터 : 이름/HP/경험치/드랍하는 골드
 3) 영웅 : 이름/최대HP/HP/소유중인물약개수

- 다음은 반드시 별도의 함수로 제작합니다.
 1) 맵 그리는 함수 ( 맵 크기에 맞게 타일, 상점 랜덤 배치 ) : 타일, 상점 등을 각각의 함수로 나누어서 제작해도 됩니다.
 2) 화면 상단에 정보 표시해 주는 함수 : 화면 상단에는 영웅의 정보, 현재 타일의 정보, 만난 몬스터의 정보가 표시됩니다. ( 영웅 정보, 타일 정보 등을 각각의 함수로 나누어서 제작해도 됩니다. )
 3) 영웅 이동
 4) 상점 이용
 5) 전투
 6) 전투 후 결과 처리
 7) 게임 오버
 8) 게임 엔딩
*/

//#include "9_header.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define MAPSIZE 10

bool gameOver = false;

struct MapTile
{
	char field = '*'; // 안전
	char swamp = '~'; // 매우위험
	char forest = '#'; // 위험
	char escape = 'E';
	char store = 'S';

}tile;

struct Hero
{
	char shape = 'P';
	int xPos = 0;
	int yPos = 0;

}hero;

struct Monster
{
	char shape = 'M';

}monster;

int main()
{
	srand(time(NULL));

	// 맵위에 상점 랜덤 생성
	// 영웅위치, 탈출위치 제외생성
	// 한번만 생성
	int storeX;
	int storeY;

	do
	{
		storeX = rand() % (MAPSIZE);
		storeY = rand() % (MAPSIZE);

	} while ((storeX == 0 && storeY == 0) || (storeX == 0 && storeY == (MAPSIZE - 1)));

	while (!gameOver)
	{

		char mapArr[MAPSIZE][MAPSIZE] = { ' ' };

		// 맵 생성 할당
		for (int i = 0; i < MAPSIZE; i++)
		{
			for (int j = 0; j < MAPSIZE; j++)
			{
				mapArr[i][j] = tile.field;
			}
		}

		// 맵위에 히어로 출력
		mapArr[hero.yPos][hero.xPos] = hero.shape;

		// 맵위에 몬스터 출력


		// 맵위에 탈출점 생성
		mapArr[MAPSIZE - 1][0] = tile.escape;

		// 맵위에 상점 표시
		mapArr[storeY][storeX] = tile.store;



		// 맵 타일 출력
		for (int i = 0; i < MAPSIZE; i++)
		{
			for (int j = 0; j < MAPSIZE; j++)
			{
				cout << mapArr[i][j] << " ";
			}
			cout << endl;
		}

		// 히어로 방향키 설정
		char input;
		input = _getch();
		switch (input)
		{
		case 'a':
		{
			hero.xPos--;
			break;

		}
		case 'w':
		{
			hero.yPos--;
			break;

		}
		case 's':
		{
			hero.yPos++;
			break;

		}
		case 'd':
		{
			hero.xPos++;
			break;
		}
		}

		//Sleep(100);
		system("cls");
	}

}