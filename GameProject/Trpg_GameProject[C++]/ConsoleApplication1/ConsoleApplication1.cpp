#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <vector>

using namespace std;

enum Scene
{
    SceneNULL,
    Title,
    Narration,
    Viliage,
    PortionShop,
    WeaponShop,

    // 사냥터씬
    Map_Grassland,
    Map_Forest,
    Map_Lava,
    Map_Swamp,
    Map_Dungeon,

    // 메인메뉴 씬
    MainMenu,
    
    // 인벤토리 씬
    Inventory,

    // 전투씬
    Combat,
    CombatResult,

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

struct HerosData
{
    string HeroName[3];
    int HeroLevel[3];
    int HeroCurrentExperience[3];
    int HeroTotalExperience[3];
    int HeroHealth[3];
    int HeroMana[3];
    int HeroGold;
};


int main()
{

    bool isMainMenu = true;

    cout << "아트리아 대륙전기." << endl;

    Sleep(1000);
    system("cls");

    cout << "태초에 영웅 3명이 존재하였다." << endl;
    cout << "이들은 검사, 마법사, 격투가로 서로 도원의 결의를 맺었다." << endl;
    cout << "이들은 던전으로 향하는데 ..갑자기 폭풍이 몰아쳤다." << endl;
    cout << "게임을 시작하려면 아무키나 누르시오. (Press Any Key)" << endl;
    Sleep(1000);
    system("cls");



    // 영웅 데이터 초기화
    HerosData hData;

    hData.HeroName[SWORD] = " 검사 ";
    hData.HeroName[WIZARD] = "마법사";
    hData.HeroName[PUNCH] = "격투가";
    hData.HeroGold = 1500;

    for (int i = 0; i < 3; i++){ hData.HeroLevel[i] = 1; }
    for (int i = 0; i < 3; i++){ hData.HeroCurrentExperience[i] = 0; }
    for (int i = 0; i < 3; i++){ hData.HeroTotalExperience[i] = 1000; }
    for (int i = 0; i < 3; i++){ hData.HeroHealth[i] = 60; }
    for (int i = 0; i < 3; i++){ hData.HeroMana[i] = 60; }
    // 영웅 데이터 초기화


    textIndex hDataindex = SWORD;

    int index = 0;

    while (true)
    {

        char inputChar = _getch();

        system("cls");


        if (inputChar == 'a')
        {
            ++index;

            if (index == 3)
            {
                index = 0;
            }

            hDataindex = (textIndex)index;
        }

        for (int i = 0; i < 3; i++)
        {
            if (hDataindex == i)
            {
                cout << "INFO: <" << hData.HeroName[i] << ">" << " 레벨 " << hData.HeroLevel[i] << " | " << "경험치 " << hData.HeroCurrentExperience[i]
                    << " / " << hData.HeroTotalExperience[i] << " | " << "체력 " << hData.HeroHealth[i] << " | " << "마나 " << hData.HeroMana[i] << " | " << "골드 " << hData.HeroGold << endl;
            }
        }

        cout << "1. 포션상점" << endl;
        cout << "2. 무기상점" << endl;
        cout << "3. 사냥터" << endl;
        cout << "4. 메인메뉴" << endl;


    }

    return 0;
}
