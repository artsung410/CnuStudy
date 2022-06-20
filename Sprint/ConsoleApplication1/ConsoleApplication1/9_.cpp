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

<<<<<<< HEAD
=======
/*
	구현한것

	구현못한것

	구현이상한것

	구현잘한것?

	
*/

>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
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
<<<<<<< HEAD
	char escape = 'E';
	char store = 'S';

}tile;

struct Hero
{
	char shape = 'P';
=======
	char escape = 'E'; // 4로표시
	char store = 'S'; // 5로 표시

}tile;

struct MapSafety
{
	int safe = 0;
	int danger = 1;
	int veryDanger = 2;
}safety;

struct Hero
{
	char shape = 'P'; // 3으로 표시
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
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

<<<<<<< HEAD
	// 맵위에 상점 랜덤 생성
	// 영웅위치, 탈출위치 제외생성
	// 한번만 생성
	int storeX;
	int storeY;

=======
	int storeX;
	int storeY;
	// 맵위에 상점 랜덤 생성
	// 영웅위치, 탈출위치 제외생성
	// 한번만 생성
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
	do
	{
		storeX = rand() % (MAPSIZE);
		storeY = rand() % (MAPSIZE);

<<<<<<< HEAD
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
=======
	} while ((storeX == 0 && storeY == 0) || (storeX == 0 && storeY == (MAPSIZE - 1)));		 // 상점위치 안겹치게 구현

	COORD cur; // 좌표값 사용

	char mapArr[MAPSIZE][MAPSIZE] = { ' ' };		// 매크로써서 맵 크기 설정


	// 0 : 필드
	// 1 : 숲
	// 2 : 늪
	// 스위치문 사용해서 각 번호당 표시되는 타일이 다르게
	int mapInfo[MAPSIZE][MAPSIZE] = { 0 };			// 맵과 동일한 크기의 정보를 담는 2차원배열 
	// 맵 데이터 할당
	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			int infoNum = rand() % 3;
			mapInfo[i][j] = infoNum;			// 랜덤 숫자로 타일을 표시하기위해 이렇게 했습니다.
		}
	}
		
	//// 맵 생성 할당
	//for (int i = 0; i < MAPSIZE; i++)
	//{
	//	for (int j = 0; j < MAPSIZE; j++)
	//	{
	//		mapArr[i][j] = '!';
	//		cout << mapArr[i][j] << " ";
	//	}
	//}

	// 계속 실행중
	while (!gameOver)		// 게임 종료전까지 계속 돌아가게했습니다.
	{
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379

		// 맵위에 히어로 출력
		mapArr[hero.yPos][hero.xPos] = hero.shape;

		// 맵위에 몬스터 출력


		// 맵위에 탈출점 생성
		mapArr[MAPSIZE - 1][0] = tile.escape;

		// 맵위에 상점 표시
		mapArr[storeY][storeX] = tile.store;


<<<<<<< HEAD

		// 맵 타일 출력
		for (int i = 0; i < MAPSIZE; i++)
		{
			for (int j = 0; j < MAPSIZE; j++)
			{
				cout << mapArr[i][j] << " ";
=======
		// 맵 타일 출력
		for (int i = 0; i < MAPSIZE; i++)			// 맵 출력에 이상한점은 처음엔 타일과 영웅이 같이 출력되지않습니다. 움직이면 정상출력됩니다.
		{
			for (int j = 0; j < MAPSIZE; j++)
			{
				// 싹다 출력
				cout << mapArr[i][j] << " ";

				// 숫자에 맞는 타일 표시
				switch (mapInfo[i][j])
				{
				case 0:
					mapArr[i][j] = tile.field;
					//cout << mapArr[i][j] << " ";
					break;
				case 1:
					mapArr[i][j] = tile.forest;
					//cout << mapArr[i][j] << " ";
					break;
				case 2:
					mapArr[i][j] = tile.swamp;
					//cout << mapArr[i][j] << " ";
					break;
				default:
					break;
				}
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
			}
			cout << endl;
		}

<<<<<<< HEAD
=======
		// 아래 정보표시 부분은 하드 코딩했습니다. 
#pragma region 정보표시 

		// 화면 상단에 정보표시
		// 영웅의 정보, 현재 타일의 정보, 만난 몬스터의 정보
		// 맵의 오른쪽에 표시한다.
		cur.X = 22;
		cur.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "-영웅의 정보-";

		cur.X = 22;
		cur.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "이름: ";

		cur.X = 22;
		cur.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "체력: ";

		cur.X = 22;
		cur.Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "골드: ";

		// 현재 몬스터 정보
		cur.X = 50;
		cur.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "-몬스터의 정보-";

		cur.X = 50;
		cur.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "이름: ";

		cur.X = 50;
		cur.Y = 4;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "체력: ";

		cur.X = 50;
		cur.Y = 6;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		//cout << "골드: ";

		// 현재타일
		cur.X = 1;
		cur.Y = 11;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		cout << "<<<현재 위치>>>";

		string safetyText[3];
		cur.X = 0;
		cur.Y = 13;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
		switch (mapInfo[hero.yPos][hero.xPos])
		{
		case 0:
			safetyText[0] = "   안전합니다.";
			cout << "     -들판-" << endl;
			cout << safetyText[0];
			break;
		case 1:
			safetyText[1] = "숲이 우거져 위험합니다.";
			cout << "      -숲-" << endl;
			cout << safetyText[1];
			break;
		case 2:
			safetyText[2] = "매우 위험한 장소 입니다.";
			cout << "    -늪지대-" << endl;
			cout << safetyText[2];
			break;
		default:
			break;
		}

#pragma endregion



>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
		// 히어로 방향키 설정
		char input;
		input = _getch();
		switch (input)
		{
		case 'a':
		{
			hero.xPos--;
<<<<<<< HEAD
=======
			if (hero.xPos < 0)			// 벽에 닿으면 더이상 움직이지 않도록 구상했습니다.
			{
				hero.xPos++;		
			}
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
			break;

		}
		case 'w':
		{
			hero.yPos--;
<<<<<<< HEAD
=======
			if (hero.yPos < 0)
			{
				hero.yPos++;
			}
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
			break;

		}
		case 's':
		{
			hero.yPos++;
<<<<<<< HEAD
=======
			if (hero.yPos == MAPSIZE)
			{
				hero.yPos--;
			}
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
			break;

		}
		case 'd':
		{
			hero.xPos++;
<<<<<<< HEAD
=======
			if (hero.xPos == MAPSIZE)
			{
				hero.xPos--;
			}
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
			break;
		}
		}

		//Sleep(100);
<<<<<<< HEAD
		system("cls");
=======
		system("cls");		// 화면초기화
>>>>>>> 06c7f77224f4006e7549283fad301c03e7598379
	}

}