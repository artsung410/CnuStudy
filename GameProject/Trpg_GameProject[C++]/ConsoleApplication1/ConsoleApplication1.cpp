#include <iostream>
#include <time.h>

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

int main()
{

    bool isMainMenu = true;
    while (true)
    {
        int iMenu;
        cin >> iMenu;

        cout << "1. 맵" << endl;
        cout << "2. 상점" << endl;
        cout << "3. 인벤토리" << endl;
        cout << "4. 종료" << endl;

        if (iMenu == MM_MAP)
        {
            cout << "1. 사냥터1" << endl;
            cout << "2. 사냥터2" << endl;
            cout << "3. 사냥터3" << endl;
            cout << "4. 마을" << endl;
            cout << "5. 인벤토리" << endl;
        }
        if (iMenu == MM_STORE)


        if (iMenu == MM_INVENTORY)


        if (iMenu == MM_EXIT)
            break;
    }

    return 0;
}
