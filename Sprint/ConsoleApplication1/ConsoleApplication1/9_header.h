#pragma once

#include <iostream>
#include <Windows.h>
#include <string>

#define Size 10

struct Tile
{
	char field = '*';
	char forest = '#';
	char swamp = '~';
}tile;

struct Monster
{
	std::string name;
	char shape = 'M';
	int hp = 50;
	int exp = 10;
	int dorpGold = 100;
}monster;

struct Hero
{
	std::string Name;
	char shape = 'P';
	int Hp = 100;
	int Mp = 50;
	int Posion = 3;
	int gold = 0;
	int heroExp = 0;

}hero;


/// <summary>
/// 맵을 그린다
/// </summary>
void PrintMap();

/// <summary>
/// 영웅정보, 타일정보, 만난 몬스터 정보가 표시된다
/// </summary>
void Information();

/// <summary>
/// 영웅 이동관련 함수
/// </summary>
void heroMove();

/// <summary>
/// 상점 이용관련 함수
/// </summary>
void UseShop();

/// <summary>
/// 게임을 클리어 관련 함수
/// </summary>
/// <returns></returns>
bool GameEnding();

/// <summary>
/// 클리어 전 죽었을때 함수
/// </summary>
/// <returns></returns>
bool GameOver();

/// <summary>
/// 전투관련 함수
/// </summary>
void Battle();

/// <summary>
/// 전투마치고 결과 보여주는 함수
/// </summary>
void BattleResult();

// 게임 오버 관련 bool값
bool gameOver = false;