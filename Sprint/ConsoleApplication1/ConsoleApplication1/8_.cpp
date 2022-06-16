/*
"게임에 등장할 영웅의 수를 입력하면 입력한 수만큼 랜덤한 직업(전사,마법사,성직자 중 1 )과 랜덤한 스탯 ( 공격력, 방어력, 마력, 치유력 네 가지이며 1~10 사이 랜덤 )을 가진 영웅이 생성되도록 하시오.
생성한 모든 영웅을 화면에 표시하시오

출력 예시)
영웅의 수를 입력하시오 : 2
1번영웅 : 성직자 , 공격력 3 방어력 2 마력 8 치유력 5
2번영웅 : 전사  , 공격력 6 방어력 5 마력 3 치유력 1"

#include <iostream>
#include <time.h>
#include <string>
using namespace std;

int main()
{
	srand(time(NULL));

	cout << "영웅의 수를 입력하시오 : ";
	int InputHeroCount;
	cin >> InputHeroCount; // 2

	// 랜덤한 직업
	string* heroPtr = new string[3] {"전사", "마법사", "성직자"};

	for (int i = 0; i < InputHeroCount; i++)
	{
		int randHero = rand() % 3;
		cout << randHero + 1 << "번 영웅 : " << heroPtr[randHero] << ", ";

		// 랜덤한 스탯
		int* statPtr = new int[5]; // 공격력, 방어력, 마력, 치유력

		for (int i = 0; i < 4; i++) // 스탯 랜덤으로 넣기
		{
			statPtr[i] = rand() % 10 + 1;
		}
		cout << "공격력 : " << statPtr[0] << " 방어력 : " << statPtr[1] << " 마력 : " << statPtr[2] << " 치유력 : " << statPtr[3] << endl;

		delete[] statPtr;
	}

	delete[] heroPtr;
}
*/

#include <iostream>

using namespace std;
// 같은형식을 숫자로 모아두기위해 enum사용 swich 문에 주로 사용

// 함수에 전달
//struct HeroStat
//{
//	int ATK;
//	int DEF;
//	int MP;
//	int HEAL;
//};

void HeroStat(int* arr);

void MakeHero(int* hero, int num);

int main()
{
	// 11:10
	srand(time(NULL));

	cout << "영웅의 수를 입력하시오 : ";
	int num;
	cin >> num;
	int* heroArr = new int[num];
	MakeHero(heroArr, num);

	delete[] heroArr;
}


void MakeHero(int* hero, int num)
{
	int statArr[4] = { 0 };

	// 각 배열에 랜덤한 숫자가 담긴다. (0 ~ 2)
	for (int i = 0; i < num; i++)
	{
		int randHero = rand() % 3;
		hero[i] = randHero;
		if (hero[i] == 0)
		{
			// 전사
			cout << "전사 ,";
			HeroStat(statArr);
		}
		else if (hero[i] == 1)
		{
			// 마법사
			cout << "마법사 ,";
			HeroStat(statArr);
		}
		else
		{
			// 성직자
			cout << "성직자 ,";
			HeroStat(statArr);
		}
	}
}

void HeroStat(int* arr)
{
	// 스탯배열에 랜덤한 수를 할당
	// statArr[0] - 공격력
	// statArr[1] - 방어력
	// statArr[2] - 마력
	// statArr[3] - 치유력
	for (int i = 0; i < 4; i++)
	{
		int randStat = 1 + rand() % 10;
		arr[i] = randStat;
	}
	cout << "공격력 : " << arr[0] << ", 방어력 : " << arr[1] << ", 마력 : " << arr[2] << ", 치유력 : " << arr[3] << endl;
}