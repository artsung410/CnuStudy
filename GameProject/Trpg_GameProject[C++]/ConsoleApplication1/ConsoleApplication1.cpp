#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <vector>

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

    // 전투씬
    COMBAT,
    COMBATRESULT,

    // 게임종료
    EXIT
};

enum weapon
{
    FireSword,
    FishSpike,
    ChainSaw,
    SilverDawn,
};

enum Portion
{
    HpPortion,
    MpPortion,
    StrongMilk,
    ManaElixir
};

class player
{
    player() = default;
    player(const player& other) = delete;
    player& operator=(const player& other) = delete;
    ~player() = default;

    int getPlayerHP()
    {
        return _hp;
    }

    int getPlayerMp()
    {
        return _mp;
    }

private:
    int _gold = 1000;
    int _hp = 50;
    int _mp = 50;
    int _Experience = 0;
    int _Level = 0;
    bool _isPosion[4]; //1. HP포션, 2. MP포션, 3. 힘쎈우유, 4. 마나엘릭서
    bool _isWeapon[4]; //1. 화염검, 2. 물고기작살, 3. 전기톱, 4. 은빛여명
    bool _isEpicWeapon[10];

};

enum textIndex
{
    SWORD,
    WIZARD,
    PUNCH
};

struct GameData
{
    std::string HeroName[3];
    int HeroLevel[3];
    int HeroCurrentExperience[3];
    int HeroTotalExperience[3];
    int HeroHealth[3];
    int HeroMana[3];
    int PlayerGold;
    int HeroInfoPosCount;
    std::vector<std::string> playerItem;
    std::string SceneName[14];

    bool isNoMoney;
};

static SceneType s_currentScene;
static SceneType s_prevScene;

GameData Data;
textIndex hDataindex;

void Init()
{
    // 신 데이터 초기화
    s_currentScene = VILIAGE;
    s_prevScene = VILIAGE; 
    // 현재 캐릭터 정보 초기화
    hDataindex = SWORD; 

    // 캐릭터 정보 초기화
    Data.HeroName[SWORD] = " 검사 ";
    Data.HeroName[WIZARD] = "마법사";
    Data.HeroName[PUNCH] = "격투가";
    Data.PlayerGold = 1500;

    for (int i = 0; i < 3; i++) { Data.HeroLevel[i] = 1; }
    for (int i = 0; i < 3; i++) { Data.HeroCurrentExperience[i] = 0; }
    for (int i = 0; i < 3; i++) { Data.HeroTotalExperience[i] = 1000; }
    for (int i = 0; i < 3; i++) { Data.HeroHealth[i] = 60; }
    for (int i = 0; i < 3; i++) { Data.HeroMana[i] = 60; }

    Data.HeroInfoPosCount = 0;

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
    Data.SceneName[10] = "전투";
    Data.SceneName[11] = "전투 결과";
}

void Render()
{

}

void Release()
{

}

int main()
{
    // 타이틀 창 띄우기.
    std::cout << "아트리아 대륙전기." << std::endl;

    Sleep(2000);

    // 게임 데이터 초기화
    Init();

    while (true)
    {
        system("cls");
        switch (s_currentScene)
        {
// 마을
#pragma region VILIAGE
        case VILIAGE:
            s_prevScene = VILIAGE;
            std::cout << "[[[[[" << Data.SceneName[VILIAGE] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "a. 포션상점" << std::endl;
            std::cout << "b. 무기상점" << std::endl;
            std::cout << "c. 사냥터" << std::endl;
            std::cout << "d. 메인메뉴" << std::endl;

            switch (_getch())
            {
            case 'a':
                s_currentScene = PORTION_SHOP;
                break;
            case 'b':
                s_currentScene = WEAPON_SHOP;
                break;
            case 'c':
                s_currentScene = GRASSLAND;
                break;
            case 'd':
                s_currentScene = MENU;
                break;
            }
            break;
#pragma endregion

// 상점
#pragma region [Viliage] PORTION_SHOP
        case PORTION_SHOP:
            std::cout << "[[[[[" << Data.SceneName[PORTION_SHOP] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "a. HP포션 50 GOLD" << "            " << "현재 보유 골드 : "<< Data.PlayerGold << std::endl;
            std::cout << "b. MP포션 50 GOLD" << std::endl;
            std::cout << "c. 힘쎈우유 500 GOLD" << std::endl;
            std::cout << "d. 마나엘릭서 500 GOLD" << std::endl;
            std::cout << "e. 나가기" << std::endl;

            switch (_getch())
            {
            case 'a':
                if (Data.PlayerGold > 50) { Data.PlayerGold -= 50; }
                break;
            case 'b':
                if (Data.PlayerGold > 50){ Data.PlayerGold -= 50; }
                break;
            case 'c':
                if (Data.PlayerGold > 500){ Data.PlayerGold -= 500; }
                break;
            case 'd':
                if (Data.PlayerGold > 500){ Data.PlayerGold -= 500; }
                break;
            case 'e':
                s_currentScene = VILIAGE;
                break;
            }
            break;

            if (Data.isNoMoney)
            {
               std::cout << "소지금액이 부족합니다" << std::endl;
            }

#pragma endregion

#pragma region [Viliage] WEAPON_SHOP
        case WEAPON_SHOP:

            std::cout << "[[[[[" << Data.SceneName[WEAPON_SHOP] << "]]]]]" << std::endl;
            std::cout << std::endl;
            std::cout << "a. 화염검 500 GOLD" << std::endl;
            std::cout << "b. 물고기 작살 1000 GOLD" << std::endl;
            std::cout << "c. 전기톱 1500 GOLD" << std::endl;
            std::cout << "d. 은빛 여명 2000GOLD" << std::endl;
            std::cout << "e. 나가기" << std::endl;

            switch (_getch())
            {
            case 'a':
                break;
            case 'b':
                break;
            case 'c':
                break;
            case 'd':
                break;
            case 'e':
                s_currentScene = VILIAGE;
                break;
            }
            break;
#pragma endregion


// 사냥터
#pragma region [Hunting Ground] GRASSLAND 
        case GRASSLAND:

            s_prevScene = GRASSLAND;
            std::cout << "[[[[[" << Data.SceneName[GRASSLAND] << "]]]]]" << std::endl;
            std::cout << std::endl;

            // 영웅 정보 q키 누를때마다 띄우기
            for (int i = 0; i < 3; i++)
            {
                if (hDataindex == i)
                {
                    std::cout << "INFO: <" << Data.HeroName[i] << ">" << " 레벨 " << Data.HeroLevel[i] << " | " << "경험치 " << Data.HeroCurrentExperience[i]
                        << " / " << Data.HeroTotalExperience[i] << " | " << "체력 " << Data.HeroHealth[i] << " | " << "마나 " << Data.HeroMana[i] << " | " << "골드 " << Data.PlayerGold << std::endl;
                }
            }

            std::cout << std::endl;
            std::cout << "####&#####" << std::endl;
            std::cout << "#######M##" << std::endl;
            std::cout << "##########" << std::endl;
            std::cout << "&########&" << std::endl;
            std::cout << "##P#######" << std::endl;
            std::cout << "##########" << std::endl;
            std::cout << "####&#####" << std::endl;

            std::cout << std::endl;

            std::cout << "a. 인벤토리" << std::endl;
            std::cout << "b. 마을로 돌아가기" << std::endl;
            std::cout << "c. 메인메뉴" << std::endl;
            std::cout << "d. 다른용사 정보" << std::endl;

            switch (_getch())
            {
            case 'a':
                s_currentScene = INVENTORY;
                break;
            case 'b':
                s_currentScene = VILIAGE;
                break;
            case 'c':
                s_currentScene = MENU;
            case 'd':
                ++Data.HeroInfoPosCount;

                if (Data.HeroInfoPosCount == 3)
                {
                    Data.HeroInfoPosCount = 0;
                }

                hDataindex = (textIndex)Data.HeroInfoPosCount;
                break;
            }
            break;
#pragma endregion

//메인메뉴
#pragma region MENU
        case MENU:

            switch (s_prevScene)
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

            std::cout << "a. 돌아가기" << std::endl;
            std::cout << "b. 게임저장" << std::endl;
            std::cout << "c. 종료" << std::endl;

            switch (_getch())
            {
            case 'a':
                s_currentScene = s_prevScene;
                break;

            case 'b':
                break;
            case 'c':
                return 0;
                break;
            }
#pragma endregion

//인벤토리
#pragma region INVENTORY
        case INVENTORY:
            switch (s_prevScene)
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
            std::cout << "[장비]" << std::endl;
            std::cout << "상의 : 허름한 가죽 소매" << std::endl;
            std::cout << "하의 : 허름한 가죽 바지" << std::endl;
            std::cout << "무기 : 야구방망이" << std::endl;
            std::cout << std::endl;
            std::cout << "[아이템]" << std::endl;
            std::cout << "HP포션 15" << std::endl;
            std::cout << "MP포션 5" << std::endl;
            std::cout << std::endl;
            std::cout << "a.돌아가기" << std::endl;

            switch (_getch())
            {
            case 'a':
                s_currentScene = s_prevScene;
                break;
            }
#pragma endregion

        }
    }

    return 0;
}
