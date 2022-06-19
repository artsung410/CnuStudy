#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <vector>
#include "Timer.h"

#define MAP_SIZE 10
#define GRASSLAND_PORTAL_COUNT 4


// 열거형
enum SceneType
{
    VILIAGE,
    PORTION_SHOP,
    WEAPON_SHOP,

    // 사냥터씬
    GRASSLAND,
    FOREST,
    LAVA,
    SWAMP,
    DUNGEON,

    // 메인메뉴 씬
    MENU,

    // 인벤토리 씬
    INVENTORY,

    // 마을회관 / 주점 씬
    TOWNHALL,
    PUB,
    // 전투씬
    COMBAT,
    COMBATRESULT,

    // 게임종료
    EXIT
}; // 씬 종류를 모은것.

enum Portion
{
    HP_PORTION,
    MP_PORTION,
    HP_STRONGMILK,
    MP_MANAELIXIR
};

enum Equipmnet
{
    TOP,
    BOTTOM,
    WEAPON,
};

enum weapon
{
    FIRESWORD,
    FISHSPIKE,
    CHAINSAW,
    SIVERDAWN,
};

enum Hero
{
    SWORD,
    WIZARD,
    PUNCH
};

enum Monster
{
    // 초원지대
    SLIME, // 슬라임
    GOBLIN, // 고블린
    SNAIL, // 달팽이

    // 어둠의 숲
    GROOT, // 그루트
    ELF, // 숲의 정령
    WITCH, // 어둠의 마녀

    // 늪지대
    MELTKNIGHT, // 멜트 나이트
    DRAUG, // 드라우그 
    WRAITH, // 망령

    // 용암지대
    DRAGON, // 주니어 드래곤
    BALROG, // 발록
    BRAND, // 브랜드

    // 던전
    GHOST, // 유령
    SKELETON, // 스켈레톤
    DARKNIGHT, // 어둠의 기사
};

enum QuestItem
{
    ATRIA_ITEM,
    RUNA_ITEM
};


struct GameData
{
    // 영웅 정보 데이터
    std::string HeroName[3];
    int HeroLevel[3];
    int HeroCurrentExperience[3];
    int HeroTotalExperience[3];

    int HeroHealth[3];
    int HeroTotalHealth[3];

    int HeroMana[3];
    int HeroTotalMana[3];

    int PlayerGold;
    int HeroInfoPosCount;

    // 몬스터 정보 데이터
    std::string MonsterName[15];
    int MonsterHealth[15];
    int MosterTotalHealth[15];

    int MonsterPower[15];

    // 현재 소지하고있는 아이템 데이터
    std::vector<std::string> playerItem;


    // 상점씬에서 필요한 데이터.
    bool isPurchase;
    bool isNoMoney;
    std::string PortionShopItem[4];
    std::string WeaponShopItem[4];
    std::vector<std::string> DropItem;
    std::vector<std::string> DropItemInfo;
    std::string CurrentPurchaseItem;

    // 인벤토리씬에서 필요한 데이터.
    int PlayerPortionCount[4];
    int PlayerPrevPortionCount[4];
    std::string Equipments[3];

    // 퀘스트 아이템 획득여부 데이터.
    bool isGetQuestItem[50];

    // 전투씬 현재 턴 데이터.
    int NowCombatTurn;
    int RandomMonster;
    int MonsterRandomDamage;
    int MonsterRandomPointToHero;
    bool isPlayerTurn;
    bool isPickMonster;
    bool isMonsterDied;
    std::string monsterAttacking;

    // 씬 전환 데이터.

    std::string SceneName[15];
    SceneType s_currentScene;
    SceneType s_prevScene;
};// ★★★★★

GameData Data;

Hero hero;


class Map
{
public:

    virtual void SetPlayerPos(int playerPosX, int playerPosY)
    {
        mPlayerPosX = playerPosX;
        mPlayerPosY = playerPosY;
    }

    virtual void SetMonster1Pos(int monsterPosX, int monsterPosY)
    {
        mMonster1PosX = monsterPosX;
        mMonster1PosY = monsterPosY;
    }

    virtual void SetMonster2Pos(int monsterPosX, int monsterPosY)
    {
        mMonster2PosX = monsterPosX;
        mMonster2PosY = monsterPosY;
    }

    virtual void SetMonster3Pos(int monsterPosX, int monsterPosY)
    {
        mMonster3PosX = monsterPosX;
        mMonster3PosY = monsterPosY;
    }

    virtual void UpdateMap()
    {
        for (int y = 0; y < MAP_SIZE; y++)
        {
            for (int x = 0; x < MAP_SIZE; x++)
            {
                // 타일 세팅
                mMap[y][x] = mtile;

                // 포탈 위치 세팅
                if (y == mPortalPoY && x == mPortalPosX)
                {
                    mMap[y][x] = mPortal;
                }

                // 몬스터 위치 세팅
                if (y == mMonster1PosY && x == mMonster1PosX)
                {
                    mMap[y][x] = 'M';
                }

                if (y == mMonster2PosY && x == mMonster2PosX)
                {
                    mMap[y][x] = 'M';
                }

                if (y == mMonster3PosY && x == mMonster3PosX)
                {
                    mMap[y][x] = 'M';
                }

                // 플레이어 위치 세팅
                if (y == mPlayerPosY && x == mPlayerPosX)
                {
                    mMap[y][x] = 'p';
                }
            }
        }
    }

    virtual void SetValue(int portalPosX, int portalPosY, char tile, char portal)
    {
        mPortalPosX = portalPosX;
        mPortalPoY = portalPosY;
        mPortal = portal;
        mtile = tile;
    }

    virtual int GetPortalX()
    {
        return mPortalPosX;
    }

    virtual int GetPortalY()
    {
        return mPortalPoY;
    }

    void PrintMap()
    {
        for (int y = 0; y < MAP_SIZE; y++)
        {
            for (int x = 0; x < MAP_SIZE; x++)
            {
                std::cout << mMap[y][x];
            }
            std::cout << "\n";
        }
    }

private:
    int mPortalPosX; // 포탈 X좌표
    int mPortalPoY; // 포탈 Y좌표

    int mPlayerPosX;
    int mPlayerPosY;

    int mMonster1PosX;
    int mMonster1PosY;

    int mMonster2PosX;
    int mMonster2PosY;

    int mMonster3PosX;
    int mMonster3PosY;

    char mtile; // 타일 기호
    char mPortal;
    char mMap[MAP_SIZE][MAP_SIZE]; // 맵 사이즈
};

class GrassMap : public Map
{
public:

    void SetPlayerPos(int playerPosX, int playerPosY)
    {
        mPlayerPosX = playerPosX;
        mPlayerPosY = playerPosY;
    }

    void SetMonster1Pos(int monsterPosX, int monsterPosY)
    {
        mMonster1PosX = monsterPosX;
        mMonster1PosY = monsterPosY;
    }

    void SetMonster2Pos(int monsterPosX, int monsterPosY)
    {
        mMonster2PosX = monsterPosX;
        mMonster2PosY = monsterPosY;
    }

    void SetMonster3Pos(int monsterPosX, int monsterPosY)
    {
        mMonster3PosX = monsterPosX;
        mMonster3PosY = monsterPosY;
    }

    void UpdateMap()
    {
        for (int y = 0; y < MAP_SIZE; y++)
        {
            for (int x = 0; x < MAP_SIZE; x++)
            {
                // 타일 세팅
                mMap[y][x] = mtile;

                // 포탈 위치 세팅
                if ((y == 9 && x == 4) || (y == 4 && x == 0) || (y == 4 && x == 9) || (y == 0 && x == 4))
                {
                    mMap[y][x] = mPortal;
                }

                // 몬스터 위치 세팅
                if (y == mMonster1PosY && x == mMonster1PosX)
                {
                    mMap[y][x] = 'M';
                }

                if (y == mMonster2PosY && x == mMonster2PosX)
                {
                    mMap[y][x] = 'M';
                }

                if (y == mMonster3PosY && x == mMonster3PosX)
                {
                    mMap[y][x] = 'M';
                }

                // 플레이어 위치 세팅
                if (y == mPlayerPosY && x == mPlayerPosX)
                {
                    mMap[y][x] = 'p';
                }
            }
        }
    }

    void SetValue(char tile, char portal)
    {
        mtile = tile;
        mPortal = portal;
    }

    int GetPortalX(int mapType)
    {
        switch (mapType)
        {
        case FOREST:
            return 4;
            break;
        case LAVA:
            return 9;
            break;
        case SWAMP:
            return 0;
            break;
        case DUNGEON:
            return 4;
            break;
        }
    }

    int GetPortalY(int mapType)
    {
        switch (mapType)
        {
        case FOREST:
            return 0;
            break;
        case LAVA:
            return 4;
            break;
        case SWAMP:
            return 4;
            break;
        case DUNGEON:
            return 9;
            break;
        }
    }

    int GetMonster1PosX()
    {
        return mMonster1PosX;
    }

    int GetMonster1PosY()
    {
        return mMonster1PosY;
    }

    int GetMonster2PosX()
    {
        return mMonster2PosX;
    }

    int GetMonster2PosY()
    {
        return mMonster2PosY;
    }

    int GetMonster3PosX()
    {
        return mMonster3PosX;
    }

    int GetMonster3PosY()
    {
        return mMonster3PosY;
    }

    void PrintMap()
    {
        for (int y = 0; y < MAP_SIZE; y++)
        {
            for (int x = 0; x < MAP_SIZE; x++)
            {
                std::cout << mMap[y][x];
            }
            std::cout << "\n";
        }
    }

private:
    int mPortalPosX; // 포탈 X좌표
    int mPortalPoY; // 포탈 Y좌표
    int mPlayerPosX;
    int mPlayerPosY;

    int mMonster1PosX;
    int mMonster1PosY;

    int mMonster2PosX;
    int mMonster2PosY;

    int mMonster3PosX;
    int mMonster3PosY;

    char mtile; // 타일 기호
    char mPortal;
    char mMap[MAP_SIZE][MAP_SIZE]; // 맵 사이즈
};

class MiniMapCharacter
{
public:

    void SetValue(int PosX, int PosY)
    {
        mPosX = PosX;
        mPosY = PosY;
    }

    void SetShape(char shape)
    {
        mShape = shape;
    }

public:
    int mPosX;
    int mPosY;
    int mPrevPosX;
    int mPrevPosY;
    char mShape;
};


// 맵 인스턴스
GrassMap Grass;
Map Forest;
Map Lava;
Map Swamp;
Map Dungeon;

MiniMapCharacter Player;
MiniMapCharacter MiniMonster1;
MiniMapCharacter MiniMonster2;
MiniMapCharacter MiniMonster3;

void CombatDataInit()
{
    // 전투 관리
    Data.NowCombatTurn = SWORD;
    Data.RandomMonster = SLIME;
    Data.isPlayerTurn = true; // 턴 구분.
    Data.isPickMonster = false; // 몬스터가 랜덤으로 뽑혔는지 여부.
    Data.isMonsterDied = false; // 몬스터가 죽었는지 여부.

    // 플레이어 피통 초기화
    for (int i = 0; i < 3; i++)
    {
        Data.HeroHealth[i] = Data.HeroTotalHealth[i];
    }

    // 플레이어 마나통 초기화

    for (int i = 0; i < 3; i++)
    {
        Data.HeroMana[i] = Data.HeroTotalMana[i];
    }

    // 몬스터 피통 초기화
    for (int i = 0; i < 15; i++)
    {
        Data.MonsterHealth[i] = (50 + i * 10);
    }

    for (int i = 0; i < 15; i++)
    {
        Data.MosterTotalHealth[i] = (50 + i * 10);
    }

    // 플레이어 미니맵 초기화.
    Player.SetValue(3, 5);
    Player.SetShape('P');

}


void DataInit()
{
    // 신 데이터 초기화
    Data.s_currentScene = VILIAGE;
    Data.s_prevScene = VILIAGE;
    // 현재 캐릭터 정보 초기화 
    hero = SWORD;

    // 영웅 정보 초기화
    Data.HeroName[SWORD] = " 검사 ";
    Data.HeroName[WIZARD] = "마법사";
    Data.HeroName[PUNCH] = "격투가";
    Data.PlayerGold = 1500;

    for (int i = 0; i < 3; i++) { Data.HeroLevel[i] = 1; }
    for (int i = 0; i < 3; i++) { Data.HeroCurrentExperience[i] = 0; }
    for (int i = 0; i < 3; i++) { Data.HeroTotalExperience[i] = 1000; }
    for (int i = 0; i < 3; i++) { Data.HeroHealth[i] = 60; }
    for (int i = 0; i < 3; i++) { Data.HeroTotalHealth[i] = 60; }
    for (int i = 0; i < 3; i++) { Data.HeroMana[i] = 60; }
    for (int i = 0; i < 3; i++) { Data.HeroTotalMana[i] = 60; }

    // 몬스터 정보 초기화
    // 0 , 1 , 2
    Data.MonsterName[SLIME] = "슬라임";
    Data.MonsterName[GOBLIN] = "고블린";
    Data.MonsterName[SNAIL] = "달팽이";

    // 3, 4, 5
    Data.MonsterName[GROOT] = "그루트";
    Data.MonsterName[ELF] = "흑마법사";
    Data.MonsterName[WITCH] = "위치";

    // 6, 7, 8
    Data.MonsterName[MELTKNIGHT] = "멜트 나이트";
    Data.MonsterName[DRAUG] = "드라우그";
    Data.MonsterName[WRAITH] = "망령";

    // 9, 10, 11
    Data.MonsterName[DRAGON] = "주니어 드래곤";
    Data.MonsterName[BALROG] = "발록";
    Data.MonsterName[BRAND] = "브랜드";

    // 12, 13, 14
    Data.MonsterName[GHOST] = "유령";
    Data.MonsterName[SKELETON] = "스켈레톤";
    Data.MonsterName[DARKNIGHT] = "어둠의 기사";




    // 상점 구매상태 초기화
    Data.isNoMoney = false;
    Data.isPurchase = false;

    // 맵 이름 초기화
    Data.SceneName[0] = "마을";
    Data.SceneName[1] = "포션 상점";
    Data.SceneName[2] = "무기 상점";
    Data.SceneName[3] = "초원 지대";
    Data.SceneName[4] = "어둠의 숲";
    Data.SceneName[5] = "용암 지대";
    Data.SceneName[6] = "늪 지대";
    Data.SceneName[7] = "던전";
    Data.SceneName[8] = "메뉴";
    Data.SceneName[9] = "인벤토리";
    Data.SceneName[10] = "마을회관";
    Data.SceneName[11] = "단란주점";
    Data.SceneName[12] = "전투";
    Data.SceneName[13] = "전투 결과";

    // 샵 아이템 초기화.
    Data.PortionShopItem[HP_PORTION] = "HP 포션";
    Data.PortionShopItem[MP_PORTION] = "MP 포션";
    Data.PortionShopItem[HP_STRONGMILK] = "힘쎈우유";
    Data.PortionShopItem[MP_MANAELIXIR] = "마나엘릭서";

    Data.WeaponShopItem[FIRESWORD] = "불검";
    Data.WeaponShopItem[FISHSPIKE] = "물고기작살";
    Data.WeaponShopItem[CHAINSAW] = "전기톱";
    Data.WeaponShopItem[SIVERDAWN] = "은빛 여명";

    // 초기 장착 장비 초기화.
    Data.Equipments[TOP] = "허름한 가죽 상의";
    Data.Equipments[BOTTOM] = "허름한 가죽 바지";
    Data.Equipments[WEAPON] = "야구 방망이";

    // 미니맵 초기화
    Grass.SetValue('#', '@');
    Forest.SetValue(4, 9, 'T', '@');
    Lava.SetValue(0, 4, '^', '@');
    Swamp.SetValue(9, 4, '~', '@');
    Dungeon.SetValue(4, 0, '*', '@');

    // 미니맵 상 플레이어 위치 초기화



    CombatDataInit();

}

void DotEffet()
{
    Sleep(100); std::cout << ".";
    Sleep(100); std::cout << ".";
    Sleep(100); std::cout << ".";
    Sleep(100); std::cout << ".";
    Sleep(100); std::cout << ".";
    Sleep(100); std::cout << ".";
    Sleep(100); std::cout << ".";
    Sleep(100); std::cout << ".";
    Sleep(100); std::cout << ".";
    Sleep(100); std::cout << ".";
    Sleep(100); std::cout << ".";
}

void Title()
{
    Sleep(100); std::cout << "아";
    Sleep(100); std::cout << "트";
    Sleep(100); std::cout << "리";
    Sleep(100); std::cout << "아";
    Sleep(100); std::cout << " ";
    Sleep(100); std::cout << "대";
    Sleep(100); std::cout << "륙";
    Sleep(100); std::cout << "전";
    Sleep(100); std::cout << "기";
    Sleep(100);
    std::cout << std::endl;
    std::cout << std::endl;
    Sleep(400); std::cout << "로딩중";
    DotEffet();
}


int main()
{
    // 타이틀 화면 띄우기.
    Title();

    // 게임 데이터 초기화
    DataInit();

    while (true)
    {
        system("cls");
        switch (Data.s_currentScene)
        {
// 마을
#pragma region VILIAGE
        case VILIAGE:
            Data.s_prevScene = VILIAGE;
            std::cout << "[[[[[" << Data.SceneName[VILIAGE] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "1. 포션상점" << std::endl;
            std::cout << "2. 무기상점" << std::endl;
            std::cout << "3. 마을회관" << std::endl;
            std::cout << "4. 단란주점" << std::endl;
            std::cout << "5. 사냥터" << std::endl;
            std::cout << "6. 메인메뉴" << std::endl;

            switch (_getch())
            {
            case '1':
                Data.s_currentScene = PORTION_SHOP;
                break;
            case '2':
                Data.s_currentScene = WEAPON_SHOP;
                break;
            case '3':
                Data.s_currentScene = TOWNHALL;
                break;
            case '4':
                Data.s_currentScene = PUB;
                break;
            case '5':
                Data.s_currentScene = GRASSLAND;
                break;
            case '6':
                Data.s_currentScene = MENU;
                break;
            }
            break;
#pragma endregion

// 마을회관
#pragma region TOWNHALL
        case TOWNHALL:
            Data.s_prevScene = TOWNHALL;
            std::cout << "[[[[[" << Data.SceneName[TOWNHALL] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "1. [바론]와 대화하기." << std::endl;
            std::cout << "2. [미트라]와 대화하기" << std::endl;
            std::cout << "3. [바이슨]와 대화하기" << std::endl;
            std::cout << "4. [암흑기사 ???]와 대화하기" << std::endl;
            std::cout << "5. 마을회관 나가기" << std::endl;

            switch (_getch())
            {
            case '1':
                system("cls");
                std::cout << "[[[[[" << "[바론]" << "]]]]]" << std::endl;
                std::cout << std::endl;
                std::cout << "제발 우리들을 도와주게나. 우리들은 그들과 싸울 힘이 없네." << std::endl; Sleep(700);
                std::cout << std::endl;
                std::cout << "1. 돌아가기" << std::endl;
                if (_getch() == '1')
                {
                    Data.s_currentScene = TOWNHALL;
                }
                break;
            case '2':
                system("cls");
                std::cout << "[[[[[" << "[미트라]" << "]]]]]" << std::endl;
                std::cout << std::endl;
                std::cout << "당신들도 마법에 관심있소? 마법은 잘쓰면 좋은거지만 잘못쓰면 흉기야.. 잘쓰길 바래" << std::endl; Sleep(700);
                std::cout << std::endl;
                std::cout << "1. 돌아가기" << std::endl;
                if (_getch() == '1')
                {
                    Data.s_currentScene = TOWNHALL;
                }
                break;
            case '3':
                system("cls");
                std::cout << "[[[[[" << "[바이슨]" << "]]]]]" << std::endl;
                std::cout << std::endl;
                std::cout << "누군가가 마을을 휩쓸고 갔어..." << std::endl; Sleep(700);
                std::cout << "자네도 조심하게, 밤 마다 이 마을에 폭풍이 몰아치고 있으니.." << std::endl; Sleep(700);
                std::cout << "그럼... 이만 가보게..." << std::endl; Sleep(700);
                std::cout << std::endl;
                std::cout << "1. 돌아가기" << std::endl;
                if (_getch() == '1')
                {
                    Data.s_currentScene = TOWNHALL;
                }
                break;
            case '4':
                system("cls");
                std::cout << "[[[[[" << "[암흑기사 ???]" << "]]]]]" << std::endl;
                std::cout << std::endl;
                std::cout << "자네에게 기운이 느껴져, 역시 그 봉인과 관련이 있었군" << std::endl; Sleep(700);
                std::cout << "저 사악한 기운이 봉인에 풀려서 좋을 것은 없겠지...." << std::endl; Sleep(700);
                std::cout << "어둠의 숲의 마법사를 조심하게 툭하면 언데드 몬스터들을 소환하니.." << std::endl; Sleep(700);
                std::cout << std::endl;
                std::cout << "1. 돌아가기" << std::endl;
                if (_getch() == '1')
                {
                    Data.s_currentScene = TOWNHALL;
                }
                break;
            case '5':
                Data.s_currentScene = VILIAGE;
                break;
            }
            break;
#pragma endregion

// 단란주점
#pragma region PUB
        case PUB:
            Data.s_prevScene = PUB;
            std::cout << "[[[[[" << Data.SceneName[PUB] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "1. [루나]와 대화하기." << std::endl;
            std::cout << "2. [트리거]와 대화하기" << std::endl;
            std::cout << "3. [마구누스]와 대화하기" << std::endl;
            std::cout << "4. [아트리아]와 대화하기" << std::endl;
            std::cout << "5. 단란주점 나가기" << std::endl;

            switch (_getch())
            {
            case '1':
                system("cls");
                std::cout << "[[[[[" << "[루나]" << "]]]]]" << std::endl;
                std::cout << std::endl;
                std::cout << "[권도형] 이자식... 마을의 보물을 들고 쥐도새도 모르게 사라져버렸어" << std::endl; Sleep(700);
                std::cout << "혹시... 자네..." << std::endl; Sleep(700);
                std::cout << "[권도형] 을 찾아줄 수 있나?" << std::endl; Sleep(700);
                std::cout << "그 자를 데려오면 진귀한걸 자네에게 주겠네..." << std::endl; Sleep(700);
                std::cout << std::endl;
                std::cout << "1. 돌아가기" << std::endl;
                std::cout << "2. 퀘스트 수락" << std::endl;
                switch (_getch())
                {
                case '1':
                    Data.s_currentScene = PUB;
                    break;
                case '2':
                    system("cls");
                    std::cout << "퀘스트 수락 완료" << std::endl; Sleep(700);
                    std::cout << "──────[퀘스트 이름]───────" << std::endl;
                    std::cout << "<q. 권도형 NPC 찾기>" << std::endl; Sleep(700);
                    std::cout << std::endl;
                    std::cout << "──────[퀘스트 보상]───────" << std::endl;
                    std::cout << "비트코인 1EA" << std::endl;
                    std::cout << std::endl;
                    std::cout << "1. 돌아가기" << std::endl;
                    switch (_getch())
                    {
                    case '1':
                        Data.s_currentScene = PUB;
                        break;
                    }
                    break;
                }
                break;
            case '2':
                system("cls");
                std::cout << "[[[[[" << "[트리거]" << "]]]]]" << std::endl;
                std::cout << std::endl;
                std::cout << "특별한 목적지는 없고 그냥 여기저기 재미난 일을 찾아 떠돌아다니는것.." << std::endl; Sleep(700);
                std::cout << "그것이.. 낭만이야" << std::endl; Sleep(700);
                std::cout << std::endl;
                std::cout << "1. 돌아가기" << std::endl;
                std::cout << std::endl;
                switch (_getch())
                {
                case '1':
                    Data.s_currentScene = PUB;
                    break;
                }
                break;
            case '3':
                system("cls");
                std::cout << "[[[[[" << "[마구누스]" << "]]]]]" << std::endl;
                std::cout << std::endl;
                std::cout << "뭔가 나의 용기를 시험해 볼 방법이 없을까?" << std::endl; Sleep(700);
                std::cout << "던전에서 나의 용기를 시험해 봐야지......." << std::endl; Sleep(700);
                std::cout << std::endl;
                std::cout << "1. 돌아가기" << std::endl;
                std::cout << std::endl;
                switch (_getch())
                {
                case '1':
                    Data.s_currentScene = PUB;
                    break;
                }
                break;
            case '4':
                system("cls");
                std::cout << "[[[[[" << "[아트리아]" << "]]]]]" << std::endl;
                std::cout << std::endl;
                if (Data.isGetQuestItem[ATRIA_ITEM] == false)
                {
                    std::cout << "자네 이 마을을 지키러온 용사인가?" << std::endl; Sleep(700);
                    std::cout << "그렇다면 환영이네!" << std::endl; Sleep(700);
                    std::cout << "받게나. 우리 가문 대대로 전해오는 권법 책이야..." << std::endl; Sleep(700);
                    std::cout << "단시간 내에 배우기는 힘들겠지만..." << std::endl; Sleep(700);
                    std::cout << "꾸준히 연마하면 자네에겐 많은 도움이 될껄세." << std::endl; Sleep(700);
                    std::cout << std::endl;
                    std::cout << "1. 돌아가기" << std::endl;
                    std::cout << "2. [권법 책] 획득하기" << std::endl;
                }
                else
                {
                    std::cout << "그럼 ..." << std::endl; Sleep(700);
                    std::cout << "자네의 모험을 위해서 건투를 빌겠네.." << std::endl; Sleep(700);
                    std::cout << std::endl;
                    std::cout << "1. 돌아가기" << std::endl;
                }
                std::cout << std::endl;
                switch (_getch())
                {
                case '1':
                    Data.s_currentScene = PUB;
                    break;
                case '2':                    
                    if (Data.isGetQuestItem[ATRIA_ITEM] == false)
                    {
                        system("cls");
                        std::cout << "아이템 획득 완료!" << std::endl; Sleep(700);
                        std::cout << "                " << std::endl;
                        std::cout << "──────[아이템 이름]───────" << std::endl;
                        std::cout << "<권 법 책>" << std::endl; Sleep(700);
                        std::cout << "                " << std::endl;
                        std::cout << "──────[설 명]───────" << std::endl;
                        std::cout << "\"아트리아 가문의 대대로 전해오는 권법 책\", 격투가의 마나를 50올려준다." << std::endl; Sleep(700);
                        std::cout << "                " << std::endl;
                        std::cout << "1. 돌아가기" << std::endl;

                        Data.DropItem.push_back("권법 책");
                        Data.DropItemInfo.push_back("\"아트리아 가문의 대대로 전해오는 권법 책\", 격투가의 마나를 50올려준다.");
                        Data.HeroMana[2] += 50;
                        Data.HeroTotalMana[2] += 50;

                        switch (_getch())
                        {
                        case '1':
                            Data.isGetQuestItem[ATRIA_ITEM] = true;
                            Data.s_currentScene = PUB;
                            break;
                        }
                        break;
                    }
                }
                break;
            case '5':
                Data.s_currentScene = VILIAGE;
                break;
            }
            break;
#pragma endregion

// 포션 상점
#pragma region PORTION_SHOP
        case PORTION_SHOP:
            std::cout << "[[[[[" << Data.SceneName[PORTION_SHOP] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "1. HP포션 50 GOLD" << std::endl;
            std::cout << "2. MP포션 50 GOLD" << std::endl;
            std::cout << "3. 힘쎈우유 500 GOLD" << std::endl;
            std::cout << "4. 마나엘릭서 500 GOLD" << std::endl;
            std::cout << "5. 나가기" << std::endl;
            std::cout << std::endl;
            std::cout << "________________________" << std::endl;
            std::cout << "현재 보유 골드 : " << Data.PlayerGold << std::endl;

            if (Data.isPurchase)
            {
                std::cout << Data.CurrentPurchaseItem << "구입 완료!" << std::endl;
            }

            if (Data.isNoMoney)
            {
                std::cout << "소지금액이 부족합니다" << std::endl;
            }

            switch (_getch())
            {
            case '1':
                if (Data.PlayerGold > 50) 
                { 

                    Data.CurrentPurchaseItem = Data.PortionShopItem[HP_PORTION];
                    Data.playerItem.push_back(Data.PortionShopItem[HP_PORTION]);
                    Data.PlayerGold -= 50; 
                    ++Data.PlayerPortionCount[HP_PORTION];
                    ++Data.PlayerPrevPortionCount[HP_PORTION];
                    Data.isPurchase = true;
                    Data.isNoMoney = false; 
                }
                else 
                { 
                    Data.isNoMoney = true; 
                    Data.isPurchase = false;
                }
                break;
            case '2':
                if (Data.PlayerGold > 50)
                { 
                    Data.CurrentPurchaseItem = Data.PortionShopItem[MP_PORTION];
                    Data.playerItem.push_back(Data.PortionShopItem[MP_PORTION]);
                    Data.PlayerGold -= 50; 
                    ++Data.PlayerPortionCount[MP_PORTION];
                    ++Data.PlayerPrevPortionCount[MP_PORTION];
                    Data.isPurchase = true;
                    Data.isNoMoney = false; 
                }
                else 
                { 
                    Data.isNoMoney = true; 
                    Data.isPurchase = false;
                }
                break;
            case '3':
                if (Data.PlayerGold > 500) 
                { 
                    Data.CurrentPurchaseItem = Data.PortionShopItem[HP_STRONGMILK];
                    Data.playerItem.push_back(Data.PortionShopItem[HP_STRONGMILK]);
                    Data.PlayerGold -= 500; 
                    ++Data.PlayerPortionCount[HP_STRONGMILK];
                    ++Data.PlayerPrevPortionCount[HP_STRONGMILK];
                    Data.isPurchase = true;
                    Data.isNoMoney = false; 
                }
                else 
                { 
                    Data.isNoMoney = true; 
                    Data.isPurchase = false;
                }
                break;
            case '4':
                if (Data.PlayerGold > 500)
                { 
                    Data.CurrentPurchaseItem = Data.PortionShopItem[MP_MANAELIXIR];
                    Data.playerItem.push_back(Data.PortionShopItem[MP_MANAELIXIR]);
                    Data.PlayerGold -= 500; 
                    ++Data.PlayerPortionCount[MP_MANAELIXIR];
                    ++Data.PlayerPrevPortionCount[MP_MANAELIXIR];
                    Data.isPurchase = true;
                    Data.isNoMoney = false;
                }
                else 
                { 
                    Data.isNoMoney = true; 
                    Data.isPurchase = false;
                }
                break;
            case '5':
                Data.isNoMoney = false;
                Data.isPurchase = false;
                Data.s_currentScene = VILIAGE;
                break;
            }

            break;

#pragma endregion


// 무기 상점
#pragma region WEAPON_SHOP
        case WEAPON_SHOP:

            std::cout << "[[[[[" << Data.SceneName[WEAPON_SHOP] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "1. 화염검 500 GOLD" << std::endl;
            std::cout << "2. 물고기 작살 1000 GOLD" << std::endl;
            std::cout << "3. 전기톱 1500 GOLD" << std::endl;
            std::cout << "4. 은빛 여명 2000 GOLD" << std::endl;
            std::cout << "5. 나가기" << std::endl;
            std::cout << std::endl;
            std::cout << "________________________" << std::endl;
            std::cout << "현재 보유 골드 : " << Data.PlayerGold << std::endl;

            if (Data.isPurchase)
            {
                std::cout << Data.CurrentPurchaseItem << "구입 완료!" << std::endl;
            }

            if (Data.isNoMoney)
            {
                std::cout << "소지금액이 부족합니다" << std::endl;
            }

            switch (_getch())
            {
            case '1':
                if (Data.PlayerGold > 500)
                {
                    Data.PlayerGold -= 500;
                    Data.CurrentPurchaseItem = Data.WeaponShopItem[FIRESWORD];
                    Data.Equipments[WEAPON] = Data.WeaponShopItem[FIRESWORD];
                    Data.isPurchase = true;
                    Data.isNoMoney = false;
                }
                else
                {
                    Data.isNoMoney = true;
                }
                break;
            case '2':
                if (Data.PlayerGold > 1000)
                {
                    Data.PlayerGold -= 1000;
                    Data.CurrentPurchaseItem = Data.WeaponShopItem[FISHSPIKE];
                    Data.Equipments[WEAPON] = Data.WeaponShopItem[FISHSPIKE];
                    Data.isPurchase = true;
                    Data.isNoMoney = false;
                }
                else
                {
                    Data.isNoMoney = true;
                }
                break;
            case '3':
                if (Data.PlayerGold > 1500)
                {
                    Data.PlayerGold -= 1500;
                    Data.CurrentPurchaseItem = Data.WeaponShopItem[CHAINSAW];
                    Data.Equipments[WEAPON] = Data.WeaponShopItem[CHAINSAW];
                    Data.isPurchase = true;
                    Data.isNoMoney = false;
                }
                else
                {
                    Data.isNoMoney = true;
                }
                break;
            case '4':
                if (Data.PlayerGold > 2000)
                {
                    Data.PlayerGold -= 2000;
                    Data.CurrentPurchaseItem = Data.WeaponShopItem[SIVERDAWN];
                    Data.Equipments[WEAPON] = Data.WeaponShopItem[SIVERDAWN];
                    Data.isPurchase = true;
                    Data.isNoMoney = false;
                }
                else
                {
                    Data.isNoMoney = true;
                }
                break;
            case '5':
                Data.isNoMoney = false;
                Data.isPurchase = false;
                Data.s_currentScene = VILIAGE;
                break;
            }

            break;
#pragma endregion


// 사냥터
#pragma region GRASSLAND 
        case GRASSLAND:
            /*
                이곳은 초원 지대, 
                특징은 맵 중에서 유일하게 마을로 이동할 수 있는 필드입니다.
                이곳의 출현 몬스터는 슬라임, 고블린, 달팽이입니다.
                포탈은 동서남북 총 4개가 있으며 북쪽부터 시계방향으로, 어둠의 숲, 용암지대, 던전, 늪 지대로 구성되어있습니다.
            */

            // 이전 맵에서 GrassLand로 넘어온 플레이어 위치 좌표 초기화
            if (Data.s_prevScene == FOREST || Data.s_prevScene == LAVA || Data.s_prevScene == DUNGEON || Data.s_prevScene == SWAMP)
            {
                Player.mPosX = Player.mPrevPosX; 
                Player.mPosY = Player.mPrevPosY;
            }

            // 씬 저장
            Data.s_prevScene = GRASSLAND;

            // [d키] 영웅 정보 출력하기
            for (int i = 0; i < 3; i++)
            {
                if (hero == i)
                {
                    std::cout << "INFO: <" << Data.HeroName[i] << ">" << " 레벨 " << Data.HeroLevel[i] << " | " << "경험치 " << Data.HeroCurrentExperience[i]
                        << " / " << Data.HeroTotalExperience[i] << " | " << "체력 " << Data.HeroHealth[i] << " | " << "마나 " << Data.HeroMana[i] << " | " << "골드 " << Data.PlayerGold << std::endl;
                }
            }
            std::cout << std::endl;

            // 현재 씬(맵) 정보 출력하기
            std::cout << "───────────── [ " << Data.SceneName[GRASSLAND] << " ]───────────────────────────────────────" << std::endl;
            std::cout << std::endl;
            std::cout << "| W : ↑ |" << " A : ← |" << " S : ↓ |" << " D : → |" << " Q : 용사 정보 바꾸기" << std::endl;
            std::cout << std::endl;

            // 입력에 따라 맵을 한번 업데이트 시켜준다.
            Grass.SetPlayerPos(Player.mPosX, Player.mPosY);
            Grass.SetMonster1Pos(7, 3);
            Grass.SetMonster2Pos(3, 7);
            Grass.UpdateMap();
            Grass.PrintMap(); 

            std::cout << std::endl;
            std::cout << "──────────────────────────────────────────────────────────────────" << std::endl;

            // 선택지 출력
            std::cout << "1. 인벤토리" << std::endl;
            std::cout << "2. 마을로 돌아가기" << std::endl;
            std::cout << "3. 메인메뉴" << std::endl;

            // 입력부
            switch (_getch())
            {
            case '1':
                Data.s_currentScene = INVENTORY;
                break;
            case '2':
                Data.s_currentScene = VILIAGE;
                break;
            case '3':
                Data.s_currentScene = MENU;
                break;
            case 'w':
                if (Player.mPosY > 0) { --Player.mPosY;  }
                break;
            case 's':
                if (Player.mPosY < 9) { ++Player.mPosY; }
                break;
            case 'a':
                if (Player.mPosX > 0) { --Player.mPosX; }
                break;
            case 'd':
                if (Player.mPosX < 9) { ++Player.mPosX; }
                break;

            case 'q':
                // d키를 누르면 HeroInfoPosCount수에따라 영웅 정보가 바뀐다.
                ++Data.HeroInfoPosCount;

                if (Data.HeroInfoPosCount == 3)
                {
                    Data.HeroInfoPosCount = 0;
                }

                hero = (Hero)Data.HeroInfoPosCount;
                break;
            }

            // 플레이어좌표가 포탈좌표랑 같다면 다음 필드로 이동한다.
            for (int portal = 0; portal < GRASSLAND_PORTAL_COUNT; portal++)
            {
                if (Player.mPosX == Grass.GetPortalX(portal + 4) && Player.mPosY == Grass.GetPortalY(portal + 4))
                {
                    Player.mPrevPosX = Player.mPosX;
                    Player.mPrevPosY = Player.mPosY;
                    Data.s_currentScene = (SceneType)(portal + 4);
                }
            }

            if ((Player.mPosX == Grass.GetMonster1PosX() && Player.mPosY == Grass.GetMonster1PosY()) ||
                (Player.mPosX == Grass.GetMonster2PosX() && Player.mPosY == Grass.GetMonster2PosY()) ||
                (Player.mPosX == Grass.GetMonster2PosX() && Player.mPosY == Grass.GetMonster2PosY()))
            {
                Data.s_currentScene = COMBAT;
            }

            break;
#pragma endregion

#pragma region FOREST
        case FOREST:
            /*
                이곳은 어둠의 숲, 초원지대로 가는 포탈(4, 9)이 존재합니다.
            */

            // grass랜드에서 forest로 넘어온 플레이어 위치 좌표 초기화
            if (Data.s_prevScene == GRASSLAND)
            {
                Player.mPosX = 4; Player.mPosY = 8;
            }

            // 씬 저장
            Data.s_prevScene = FOREST;
 

            // [d키] 영웅 정보 출력하기
            for (int i = 0; i < 3; i++)
            {
                if (hero == i)
                {
                    std::cout << "INFO: <" << Data.HeroName[i] << ">" << " 레벨 " << Data.HeroLevel[i] << " | " << "경험치 " << Data.HeroCurrentExperience[i]
                        << " / " << Data.HeroTotalExperience[i] << " | " << "체력 " << Data.HeroHealth[i] << " | " << "마나 " << Data.HeroMana[i] << " | " << "골드 " << Data.PlayerGold << std::endl;
                }
            }
            std::cout << std::endl;


            // 현재 씬(맵) 정보 출력하기
            std::cout << "───────────── [ " << Data.SceneName[FOREST] << " ]───────────────────────────────────────" << std::endl;
            std::cout << std::endl;
            std::cout << "| W : ↑ |" << " A : ← |" << " S : ↓ |" << " D : → |" << " Q : 용사 정보 바꾸기" << std::endl;
            std::cout << std::endl;


            // 입력에 따라 맵을 한번 업데이트 시켜준다.
            Forest.SetPlayerPos(Player.mPosX, Player.mPosY);
            Forest.SetMonster1Pos(7, 3);
            Forest.SetMonster2Pos(3, 7);
            Forest.UpdateMap();
            Forest.PrintMap();      

            std::cout << std::endl;
            std::cout << "──────────────────────────────────────────────────────────────────" << std::endl;

            // 선택지 출력
            std::cout << "1. 인벤토리" << std::endl;
            std::cout << "2. 메인메뉴" << std::endl;


            // 입력부
            switch (_getch())
            {

            case '1':
                Data.s_currentScene = INVENTORY;
                break;
            case '2':
                Data.s_currentScene = MENU;
                break;
            case 'w':
                if (Player.mPosY > 0){ --Player.mPosY;}
                break;
            case 's':
                if (Player.mPosY < 9){ ++Player.mPosY;}
                break;
            case 'a':
                if (Player.mPosX > 0){ --Player.mPosX;}
                break;
            case 'd':
                if (Player.mPosX < 9){ ++Player.mPosX;}
                break;

            case 'q':
                // d키를 누르면 HeroInfoPosCount수에따라 영웅 정보가 바뀐다.
                ++Data.HeroInfoPosCount;

                if (Data.HeroInfoPosCount == 3)
                {
                    Data.HeroInfoPosCount = 0;
                }

                hero = (Hero)Data.HeroInfoPosCount;
                break;
            }

            // 플레이어좌표가 포탈좌표랑 같다면 다음 필드로 이동한다.
            if (Player.mPosX == Forest.GetPortalX() && Player.mPosY == Forest.GetPortalY())
            {
                Data.s_currentScene = GRASSLAND;
            }

            break;
#pragma endregion

#pragma region LAVA
            case LAVA:
            /*
                이곳은 어둠의 숲, 초원지대로 가는 포탈(4, 9)이 존재합니다.
            */

            // grass랜드에서 forest로 넘어온 플레이어 위치 좌표 초기화
            if (Data.s_prevScene == GRASSLAND)
            {
                Player.mPosX = 0; Player.mPosY = 4;
            }

            // 씬 저장
            Data.s_prevScene = LAVA;


            // [d키] 영웅 정보 출력하기
            for (int i = 0; i < 3; i++)
            {
                if (hero == i)
                {
                    std::cout << "INFO: <" << Data.HeroName[i] << ">" << " 레벨 " << Data.HeroLevel[i] << " | " << "경험치 " << Data.HeroCurrentExperience[i]
                        << " / " << Data.HeroTotalExperience[i] << " | " << "체력 " << Data.HeroHealth[i] << " | " << "마나 " << Data.HeroMana[i] << " | " << "골드 " << Data.PlayerGold << std::endl;
                }
            }
            std::cout << std::endl;

            // 현재 씬(맵) 정보 출력하기
            std::cout << "───────────── [ " << Data.SceneName[LAVA] << " ]───────────────────────────────────────" << std::endl;
            std::cout << std::endl;
            std::cout << "| W : ↑ |" << " A : ← |" << " S : ↓ |" << " D : → |" << " Q : 용사 정보 바꾸기" << std::endl;
            std::cout << std::endl;


            // 입력에 따라 맵을 한번 업데이트 시켜준다.
            Lava.SetPlayerPos(Player.mPosX, Player.mPosY);
            Lava.SetMonster1Pos(7, 3);
            Lava.SetMonster2Pos(3, 7);
            Lava.UpdateMap();
            Lava.PrintMap();            // 어둠의 숲 맵 출력
            std::cout << std::endl;
            std::cout << "──────────────────────────────────────────────────────────────────" << std::endl;

            // 선택지 출력
            std::cout << "1. 인벤토리" << std::endl;
            std::cout << "2. 메인메뉴" << std::endl;


            // 입력부
            switch (_getch())
            {

            case '1':
                Data.s_currentScene = INVENTORY;
                break;
            case '2':
                Data.s_currentScene = MENU;
                break;
            case 'w':
                if (Player.mPosY > 0) { --Player.mPosY; }
                break;
            case 's':
                if (Player.mPosY < 9) { ++Player.mPosY; }
                break;
            case 'a':
                if (Player.mPosX > 0) { --Player.mPosX; }
                break;
            case 'd':
                if (Player.mPosX < 9) { ++Player.mPosX; }
                break;

            case 'q':
                // d키를 누르면 HeroInfoPosCount수에따라 영웅 정보가 바뀐다.
                ++Data.HeroInfoPosCount;

                if (Data.HeroInfoPosCount == 3)
                {
                    Data.HeroInfoPosCount = 0;
                }

                hero = (Hero)Data.HeroInfoPosCount;
                break;
            }

            // 플레이어좌표가 포탈좌표랑 같다면 다음 필드로 이동한다.
            if (Player.mPosX == Lava.GetPortalX() && Player.mPosY == Lava.GetPortalY())
            {
                Data.s_currentScene = GRASSLAND;
            }

            break;
#pragma endregion

#pragma region DUNGEON
            case DUNGEON:
                /*
                    이곳은 어둠의 숲, 초원지대로 가는 포탈(4, 9)이 존재합니다.
                */

                // grass랜드에서 forest로 넘어온 플레이어 위치 좌표 초기화
                if (Data.s_prevScene == GRASSLAND)
                {
                    Player.mPosX = 4; Player.mPosY = 0;
                }

                // 씬 저장
                Data.s_prevScene = DUNGEON;


                // [d키] 영웅 정보 출력하기
                for (int i = 0; i < 3; i++)
                {
                    if (hero == i)
                    {
                        std::cout << "INFO: <" << Data.HeroName[i] << ">" << " 레벨 " << Data.HeroLevel[i] << " | " << "경험치 " << Data.HeroCurrentExperience[i]
                            << " / " << Data.HeroTotalExperience[i] << " | " << "체력 " << Data.HeroHealth[i] << " | " << "마나 " << Data.HeroMana[i] << " | " << "골드 " << Data.PlayerGold << std::endl;
                    }
                }
                std::cout << std::endl;


                // 입력에 따라 맵을 한번 업데이트 시켜준다.
                Dungeon.SetPlayerPos(Player.mPosX, Player.mPosY);
                Dungeon.SetMonster1Pos(7, 3);
                Dungeon.SetMonster2Pos(3, 7);
                Dungeon.UpdateMap();


                // 현재 씬(맵) 정보 출력하기
                std::cout << "───────────── [ " << Data.SceneName[DUNGEON] << " ]───────────────────────────────────────" << std::endl;
                std::cout << std::endl;
                std::cout << "| W : ↑ |" << " A : ← |" << " S : ↓ |" << " D : → |" << " Q : 용사 정보 바꾸기" << std::endl;


                std::cout << std::endl;
                Dungeon.PrintMap();            // 어둠의 숲 맵 출력
                std::cout << std::endl;
                std::cout << "──────────────────────────────────────────────────────────────────" << std::endl;

                // 선택지 출력
                std::cout << "1. 인벤토리" << std::endl;
                std::cout << "2. 메인메뉴" << std::endl;

                // 입력부
                switch (_getch())
                {

                case '1':
                    Data.s_currentScene = INVENTORY;
                    break;
                case '2':
                    Data.s_currentScene = MENU;
                    break;
                case 'w':
                    if (Player.mPosY > 0) { --Player.mPosY; }
                    break;
                case 's':
                    if (Player.mPosY < 9) { ++Player.mPosY; }
                    break;
                case 'a':
                    if (Player.mPosX > 0) { --Player.mPosX; }
                    break;
                case 'd':
                    if (Player.mPosX < 9) { ++Player.mPosX; }
                    break;

                case 'q':
                    // d키를 누르면 HeroInfoPosCount수에따라 영웅 정보가 바뀐다.
                    ++Data.HeroInfoPosCount;

                    if (Data.HeroInfoPosCount == 3)
                    {
                        Data.HeroInfoPosCount = 0;
                    }

                    hero = (Hero)Data.HeroInfoPosCount;
                    break;
                }

                // 플레이어좌표가 포탈좌표랑 같다면 다음 필드로 이동한다.
                if (Player.mPosX == Dungeon.GetPortalX() && Player.mPosY == Dungeon.GetPortalY())
                {
                    Data.s_currentScene = GRASSLAND;
                }

                break;
#pragma endregion

#pragma region SWAMP
            case SWAMP:
                /*
                    이곳은 어둠의 숲, 초원지대로 가는 포탈(4, 9)이 존재합니다.
                */

                // grass랜드에서 forest로 넘어온 플레이어 위치 좌표 초기화
                if (Data.s_prevScene == GRASSLAND)
                {
                    Player.mPosX = 9; Player.mPosY = 4;
                }

                // 씬 저장
                Data.s_prevScene = SWAMP;


                // [d키] 영웅 정보 출력하기
                for (int i = 0; i < 3; i++)
                {
                    if (hero == i)
                    {
                        std::cout << "INFO: <" << Data.HeroName[i] << ">" << " 레벨 " << Data.HeroLevel[i] << " | " << "경험치 " << Data.HeroCurrentExperience[i]
                            << " / " << Data.HeroTotalExperience[i] << " | " << "체력 " << Data.HeroHealth[i] << " | " << "마나 " << Data.HeroMana[i] << " | " << "골드 " << Data.PlayerGold << std::endl;
                    }
                }
                std::cout << std::endl;

                // 현재 씬(맵) 정보 출력하기
                std::cout << "───────────── [ " << Data.SceneName[SWAMP] << " ]───────────────────────────────────────" << std::endl;
                std::cout << std::endl;
                std::cout << "| W : ↑ |" << " A : ← |" << " S : ↓ |" << " D : → |" << " Q : 용사 정보 바꾸기" << std::endl;
                std::cout << std::endl;

                // 입력에 따라 맵을 한번 업데이트 시켜준다.
                Swamp.SetPlayerPos(Player.mPosX, Player.mPosY);
                Swamp.SetMonster1Pos(7, 3);
                Swamp.SetMonster2Pos(3, 7);
                Swamp.UpdateMap();

                Swamp.PrintMap();            // 어둠의 숲 맵 출력
                std::cout << std::endl;
                std::cout << "──────────────────────────────────────────────────────────────────" << std::endl;

                // 선택지 출력
                std::cout << "1. 인벤토리" << std::endl;
                std::cout << "2. 메인메뉴" << std::endl;


                // 입력부
                switch (_getch())
                {

                case '1':
                    Data.s_currentScene = INVENTORY;
                    break;
                case '2':
                    Data.s_currentScene = MENU;
                    break;
                case 'w':
                    if (Player.mPosY > 0) { --Player.mPosY; }
                    break;
                case 's':
                    if (Player.mPosY < 9) { ++Player.mPosY; }
                    break;
                case 'a':
                    if (Player.mPosX > 0) { --Player.mPosX; }
                    break;
                case 'd':
                    if (Player.mPosX < 9) { ++Player.mPosX; }
                    break;

                case 'q':
                    // d키를 누르면 HeroInfoPosCount수에따라 영웅 정보가 바뀐다.
                    ++Data.HeroInfoPosCount;

                    if (Data.HeroInfoPosCount == 3)
                    {
                        Data.HeroInfoPosCount = 0;
                    }

                    hero = (Hero)Data.HeroInfoPosCount;
                    break;
                }

                // 플레이어좌표가 포탈좌표랑 같다면 다음 필드로 이동한다.
                if (Player.mPosX == Swamp.GetPortalX() && Player.mPosY == Swamp.GetPortalY())
                {
                    Data.s_currentScene = GRASSLAND;
                }

                break;
#pragma endregion


//메인메뉴
#pragma region MENU
        case MENU:

            switch (Data.s_prevScene)
            {
            case VILIAGE:
                std::cout << "[[[[[" << Data.SceneName[VILIAGE] << "]]]]]" << std::endl;
                break;
            case GRASSLAND:
                std::cout << "[[[[[" << Data.SceneName[GRASSLAND] << "]]]]]" << std::endl;
                break;
            case FOREST:
                std::cout << "[[[[[" << Data.SceneName[FOREST] << "]]]]]" << std::endl;
                break;
            case LAVA:
                std::cout << "[[[[[" << Data.SceneName[LAVA] << "]]]]]" << std::endl;
                break;
            case SWAMP:
                std::cout << "[[[[[" << Data.SceneName[SWAMP] << "]]]]]" << std::endl;
                break;
            case DUNGEON:
                std::cout << "[[[[[" << Data.SceneName[DUNGEON] << "]]]]]" << std::endl;
                break;
            }

            std::cout << std::endl;
            std::cout << "1. 돌아가기" << std::endl;
            std::cout << "2. 종료" << std::endl;

            switch (_getch())
            {
            case '1':
                Data.s_currentScene = Data.s_prevScene;
                system("cls");
                break;

            case '2':
                return 0;
                break;

            }
            break;
#pragma endregion

//인벤토리
#pragma region INVENTORY
        case INVENTORY:
            switch (Data.s_prevScene)
            {
            case VILIAGE:
                std::cout << "[[[[[" << Data.SceneName[VILIAGE] << "]]]]]" << std::endl;
                break;
            case GRASSLAND:
                std::cout << "[[[[[" << Data.SceneName[GRASSLAND] << "]]]]]" << std::endl;
                break;
            case FOREST:
                std::cout << "[[[[[" << Data.SceneName[FOREST] << "]]]]]" << std::endl;
                break;
            case LAVA:
                std::cout << "[[[[[" << Data.SceneName[LAVA] << "]]]]]" << std::endl;
                break;
            case SWAMP:
                std::cout << "[[[[[" << Data.SceneName[SWAMP] << "]]]]]" << std::endl;
                break;
            case DUNGEON:
                std::cout << "[[[[[" << Data.SceneName[DUNGEON] << "]]]]]" << std::endl;
                break;
            }

            // 장비현황
            std::cout << std::endl;
            std::cout << "[장비]" << std::endl;
            std::cout << "상의 : " << Data.Equipments[TOP] << std::endl;
            std::cout << "하의 : " << Data.Equipments[BOTTOM] << std::endl;
            std::cout << "무기 : " << Data.Equipments[WEAPON] << std::endl;
            std::cout << std::endl;

            // 소모아이템 현황
            std::cout << "[아이템]" << std::endl;

            for (int i = 0; i < 4; i++)
            {
                if (Data.PlayerPortionCount[i] > 0)
                {
                    std::cout << Data.PortionShopItem[i] << Data.PlayerPortionCount[i] << std::endl;
                }
            }

            for (int i = 0; i < Data.DropItem.size(); i++)
            {
                std::cout << "◎" + Data.DropItem[i] << std::endl;
            }

            std::cout << std::endl;
            std::cout << "1.돌아가기" << std::endl;

            switch (_getch())
            {
            case '1':
                Data.s_currentScene = Data.s_prevScene;
                break;
            }
            break;
#pragma endregion


//전투
#pragma region COMBAT

        case COMBAT:
            // 몬스터를 랜덤으로 뽑아 주고, 만약 뽑혔으면 난수를 돌리지 않는다.
            if (Data.isPickMonster == false)
            {
                for (int i = 0; i < 5; i++)
                {
                    if (Data.s_prevScene == (i + 3))
                    {
                        Data.RandomMonster = rand() % 3 + 3 * i;
                    }
                }
                Data.isPickMonster = true;
            }

            // 현재 필드네임을 띄운다.
            switch (Data.s_prevScene)
            {
            case GRASSLAND:
                std::cout << "[[[[[" << Data.SceneName[GRASSLAND] << "]]]]]" << std::endl;
                break;
            case FOREST:
                std::cout << "[[[[[" << Data.SceneName[FOREST] << "]]]]]" << std::endl;
                break;
            case LAVA:
                std::cout << "[[[[[" << Data.SceneName[LAVA] << "]]]]]" << std::endl;
                break;
            case SWAMP:
                std::cout << "[[[[[" << Data.SceneName[SWAMP] << "]]]]]" << std::endl;
                break;
            case DUNGEON:
                std::cout << "[[[[[" << Data.SceneName[DUNGEON] << "]]]]]" << std::endl;
                break;
            }

            // 게임판을 출력한다.

            if (Data.isPlayerTurn == true)
            {
                std::cout << "─────────────────────── | " << " 현재턴 : " << Data.HeroName[Data.NowCombatTurn] << " |───────────────────────" << std::endl;
            }
            else
            {
                std::cout << "─────────────────────── | " << " 현재턴 : " << Data.MonsterName[Data.RandomMonster] << " |───────────────────────" << std::endl;
            }

            std::cout << "                                                         " << std::endl;
            std::cout << "                                                         " << std::endl;
            std::cout << "      <" << Data.HeroName[SWORD] << ">             <" << Data.HeroName[WIZARD] << ">             <" << Data.HeroName[PUNCH] << ">" << std::endl;
            std::cout << "                                                         " << std::endl;
            std::cout << "체력 : " << Data.HeroHealth[SWORD] << " / " << Data.HeroTotalHealth[SWORD] << "              " << Data.HeroHealth[WIZARD] << " / " << Data.HeroTotalHealth[WIZARD] << "              " << Data.HeroHealth[PUNCH] << " / " << Data.HeroTotalHealth[PUNCH] << std::endl;
            std::cout << "마법 : " << Data.HeroMana[SWORD] << " / " << Data.HeroTotalMana[SWORD] << "              " << Data.HeroMana[WIZARD] << " / " << Data.HeroTotalMana[WIZARD] << "              " << Data.HeroMana[PUNCH] << " / " << Data.HeroTotalMana[PUNCH] << std::endl;
            std::cout << "1.     베기                 " << "에너지볼트           " << "발차기" << std::endl;
            std::cout << "2.     초승달 베기          " << "매테오               " << "날라차기" << std::endl;
            std::cout << "3.     벽력일섬             " << "썬더스톰             " << "돌려차기" << std::endl;
            std::cout << "4.     천송이의 벚꽃경엄    " << "사건의 지평선        " << "핵펀치" << std::endl;
            std::cout << "                                                         " << std::endl;
            std::cout << "                                                         " << std::endl;
            std::cout << "──────────────────────| 보유 아이템 |─────────────────────" << std::endl;

            // 포션 아이템 수량을 업데이트 한다. 만약 인벤토리에 포션이 없으면 출력하지 않는다. 
            for (int i = 0; i < 4; i++)
            {
                if (Data.PlayerPortionCount[i] > 0)
                {
                    std::cout << 5 + i << ".      " << Data.PortionShopItem[i] << Data.PlayerPortionCount[i] << " / " << Data.PlayerPrevPortionCount[i] << " 사용" << std::endl;
                }
            }

            // 랜덤으로 뽑힌 몬스터의 정보를 업데이트한다. 몬스터는 플레이어 턴이 끝나면 공격을 한다.
            std::cout << std::endl;
            std::cout << "───────────────────────| 몬스터 정보 |──────────────────────" << std::endl;
            std::cout << "                                                         " << std::endl;
            std::cout << "                                                         " << std::endl;
            std::cout << Data.MonsterName[Data.RandomMonster] << std::endl;
            std::cout << Data.MonsterHealth[Data.RandomMonster] << " / " << Data.MosterTotalHealth[Data.RandomMonster] << std::endl;
            std::cout << "                                                         " << std::endl;

            // 1. 사용자가 공격버튼을 누르면 스킬종류에따라  몬스터의 피가 깎인다. 
            // 2. 스킬을 사용하는 즉시 각 용사의 마나가 깎인다. (1번 기본공격은 제외)
            // 3. 공격이 끝나면 플레이어 턴을 비활성화 시키고, 몬스터 턴으로 바꾼다.
            // 4. 다음 용사를 바꾼다.

            if (Data.isMonsterDied == false)
            {
                switch (_getch())
                {
                case '1':
                    Data.MonsterHealth[Data.RandomMonster] -= 5;
                    std::cout << Data.MonsterName[Data.RandomMonster] << "의 HP가 - 5 깎임" << std::endl;
                    Data.isPlayerTurn = false;
                    ++Data.NowCombatTurn;
                    break;
                case '2':
                    Data.MonsterHealth[Data.RandomMonster] -= 10;
                    Data.HeroMana[Data.NowCombatTurn] -= 10;
                    std::cout << Data.MonsterName[Data.RandomMonster] << "의 HP가 - 10 깎임" << std::endl;
                    Data.isPlayerTurn = false;
                    ++Data.NowCombatTurn;
                    break;
                case '3':
                    Data.MonsterHealth[Data.RandomMonster] -= 15;
                    Data.HeroMana[Data.NowCombatTurn] -= 20;
                    std::cout << Data.MonsterName[Data.RandomMonster] << "의 HP가 - 15 깎임" << std::endl;
                    Data.isPlayerTurn = false;
                    ++Data.NowCombatTurn;
                    break;
                case '4':
                    Data.MonsterHealth[Data.RandomMonster] -= 30;
                    Data.HeroMana[Data.NowCombatTurn] -= 40;
                    std::cout << Data.MonsterName[Data.RandomMonster] << "의 HP가 - 30 깎임" << std::endl;
                    Data.isPlayerTurn = false;
                    ++Data.NowCombatTurn;
                    break;
                }

                if (Data.MonsterHealth[Data.RandomMonster] <= 0)
                {
                    Data.isMonsterDied = true;
                    std::cout << "☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆ 전투 승리 ☆☆☆☆☆☆☆☆☆☆☆☆☆☆" << std::endl; 
                    std::cout << "화면 전환 중" << std::endl; DotEffet(); DotEffet();
                    
                    Data.s_currentScene = COMBATRESULT;
                }
            }

            // 몬스터 턴으로 전환되면, 몬스터는 공격을 한다.
            // 몬스터 공격중... 이라는 화면을 띄운다.
            // DotEffet() 함수로 일정한 시간이 지나면 플레이어턴으로 전환한다.
            if (Data.isPlayerTurn == false && Data.isMonsterDied == false)
            {
                std::cout << "몬스터 공격중"; DotEffet();

                Data.MonsterRandomDamage = rand() % 3 + 15; // 랜덤 데미지 주기
                Data.MonsterRandomPointToHero = rand() % 3; // 랜덤으로 용사 지목하기

                Data.HeroHealth[Data.MonsterRandomPointToHero] -= Data.MonsterRandomDamage;
                std::cout << std::endl;
                std::cout << std::endl;

                // 랜덤 데미지가 10이 넘어가면 치명타 발동을 띄운다.
                if (Data.MonsterRandomDamage > 15)
                {
                    std::cout << Data.MonsterName[Data.RandomMonster] << "의 치명타 발동!" << std::endl;
                }
                std::cout << std::endl;
                std::cout << Data.HeroName[Data.MonsterRandomPointToHero] << "의 HP가 " << Data.MonsterRandomDamage << " 깎임" << std::endl;

                std::cout << "플레이어 턴으로 전환중" << std::endl; DotEffet();
                std::cout << std::endl;
                Data.isPlayerTurn = true;
            }

            // 용사를 넘겼을때 일정한 인덱스를 넘겼으면, 다시 검사로 초기화 시킨다.
            if (Data.NowCombatTurn == 3)
            {
                Data.NowCombatTurn = 0;
            }

            break;
#pragma endregion

// 전투 결과

#pragma region COMBATRESULT
        case COMBATRESULT:

            // 전투결과 데이터.
            int CombatRewardMoney = 500 + (rand() % 10) * 10;

            int CombatRewardExperience1 = 200 + (rand() % 10) * 5;
            int CombatRewardExperience2 = 200 + (rand() % 10) * 5;
            int CombatRewardExperience3 = 200 + (rand() % 10) * 5;

            Data.PlayerGold += CombatRewardMoney;
            Data.HeroCurrentExperience[SWORD] += CombatRewardExperience1;
            Data.HeroCurrentExperience[WIZARD] += CombatRewardExperience2;
            Data.HeroCurrentExperience[PUNCH] += CombatRewardExperience3;

            std::cout << "◎ 획득한 골드 : " << CombatRewardMoney << std::endl;
            std::cout << std::endl;
            std::cout << "◎ 획득한 경험치 : ";
            std::cout << std::endl;
            std::cout << Data.HeroName[SWORD] << " | " << CombatRewardExperience1 << std::endl;
            std::cout << Data.HeroName[WIZARD] << " | " << CombatRewardExperience2 <<std::endl;
            std::cout << Data.HeroName[PUNCH] << " | " << CombatRewardExperience3 <<std::endl;
            std::cout << std::endl;
            DotEffet();
            std::cout << std::endl;
            std::cout << std::endl;

            CombatDataInit();

            // 데이터 초기화 작업 진행
            std::cout << "1. 사냥터로 돌아가기" << std::endl;
            switch (_getch())
            {
            case '1':
                Data.s_currentScene = Data.s_prevScene;
                break;
            }

            break;
#pragma endregion
        }

     
    }

    return 0;
}
