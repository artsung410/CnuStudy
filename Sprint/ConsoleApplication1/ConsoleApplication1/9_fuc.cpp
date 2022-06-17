#include "9_header.h"

using namespace std;

bool GameEnding()
{
	// 탈출했을때
}

bool GameOver()
{
	// 영웅이 죽었을때
}

void heroMove()
{
	int xPos;
	int yPos;
	cout << hero.shape;
}

void UseShop()
{
	// 상점이용
}

void PrintMap(char **arr, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = tile.field;
			cout << arr[i][j];
		}
		cout << "\n";
	}
}

void Information()
{
	// 내 정보

}

void Battle()
{
	// 전투
}

void BattleResult()
{
	// 전투 후 결과 처리

}
