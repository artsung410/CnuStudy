#include <iostream>

using namespace std;


class Monster
{
public:
	Monster() : Health(0) {}
	Monster(int _helath) : Health(_helath) {}

	void Heal(const int healValue)
	{
		// healValue = 100; // ERROR!!
		Health += healValue;
		cout << "몬스터가 " << healValue << "만큼 회복 했습니다." << endl;
	}

	void Attack(const int damage)
	{
		// damage = 50; // ERROR!!
		if (Health >= damage)
		{
			Health -= damage;
			cout << "몬스터가 " << damage << "만큼 공격 받았습니다." << endl;
		}
	}

	int ViewHealth() const
	{
		// Helath = 80; // ERROR!!
		return Health;
	}

	const int ViewState()
	{
		return Health;
	}

private:
	int Health;
};

int main()
{
	Monster monster(100);

	monster.Heal(100);
	monster.Attack(20);
	//monster.ViewState() += 50;// ERROR!!

	cout << "몬스터의 현재 체력 : " << monster.ViewHealth() << endl;
}