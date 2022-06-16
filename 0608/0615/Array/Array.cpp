#include <iostream>
#include <conio.h>
using namespace std;

#define MAP_SIZE 10

// 1. 플레이어는 p로 표현한다.
// 2. 플레이어의 초기 위치는 (0, 0)이다.
// 3. 맵은 10X10으로 표현한다.
// 4. 탈출지점은 E로 표현한다.
// 5. 탈출지점의 위치는 (8, 8)
// 6. 플레이어는 입력을 받는다.

// ##############
// 이동할 방향 키를 입력해 주세요.
int main()
{
	int PosX = 0;
	int PosY = 0;
	char Escape_Point = 'E';
	char tile = '#';
	char player = 'p';

	char Map[MAP_SIZE][MAP_SIZE];

	// 맵 담기.

	// 맵 출력. 반복문을통해서 바꿔줘야한다.
	while (1)
	{
		system("cls");
		for (int y = 0; y < MAP_SIZE; y++)
		{
			for (int x = 0; x < MAP_SIZE; x++)
			{
				if (y == 8 && x == 8)
				{
					Map[y][x] = Escape_Point;
				}

				else if ( y == PosY && x == PosX )
				{
					Map[y][x] = player;
				}

				else
				{
					Map[y][x] = tile;
				}
			}
		}

		for (int y = 0; y < MAP_SIZE; y++)
		{
			for (int x = 0; x < MAP_SIZE; x++)
			{
				cout << Map[y][x];
			}
			cout << "\n";
		}

		if (PosX == 8 && PosY == 8)
		{
			cout << "용준헌(님)이 솔로탈출에 성공하였습니다!" << endl;
			break;
		}
		// 화면에 띄울 텍스트를 만든다.


		cout << "이동할 방향 키를 입력해 주세요 : ";
		char inputChar = _getch();

		// 오입력인지 확인한다.

		switch(inputChar)
		{
		case 'w':
			if (PosY > 0) { PosY--; }
			break;
		case 's':
			if (PosY < 9) { PosY++; }
			break;
		case 'a':
			if (PosX > 0) { PosX--; }
			break;
		case 'd':
			if (PosX < 9) { PosX++; }
			break;
		}


	}

	return 0;
}
