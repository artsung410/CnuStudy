#include <iostream>

using namespace std;


class Deck
{
	int deck[7] = { 0 };
	static bool isUsedCard[54];
	static int remainCard;

public:
	Deck()
	{
		Make();
	};

	Deck(const Deck& other) = delete;
	Deck& operator=(const Deck& other) = delete;
	~Deck() = default;

	/// <summary>
	/// 카드를 7장 뽑아서 덱을 구성한다.
	/// 카드는 중복되지 않아야 한다.
	/// </summary>
	/// <returns> 덱이 성공적으로 구성됐을 경우 true, 아니면 false </returns>


	void boolCheck()
	{
		for (int i = 0; i < 53; ++i)
		{
			cout << isUsedCard[i] << " ";
		}
		cout << "\n";
	}

	bool Make()
	{
		if (remainCard < 7)
		{
			return false;
		}

		srand(time(NULL));
		for (int i = 0; i < 7; i++) // 카드를 7개 뽑는다
		{
			// isUsedCard을 순회하면서 남은 카드가 7장인지 확인한다.
			int card = 0;
			do
			{
				// 랜덤하게 카드 뽑기
				card = rand() % 53; // 0~52까지 카드
			} while (isUsedCard[card]); // 카드가 있으면 게속 반복

			// 카드는 중복되지 않았다.

			deck[i] = card; // 카드53개중 내가뽑은카드 7개 저장
			isUsedCard[card] = true; // 카드가 뽑았다고 알려줌
		}

		remainCard -= 7;

		return true;
	}

	// 덱에 담긴 숫자를 매개변수를 가져온다.
	string ConvertToCardString()
	{
		if (deck[0] == 0)
		{
			return "The Card is Empty";
		}

		// CARD_TYPE[0] : "♠"   // 0 ~ 12
		// CARD_TYPE[1] : "♣"   // 13 ~ 25
		// CARD_TYPE[2] : "♥"   // 26 ~ 38
		// CARD_TYPE[3] : "◆"  // 39 ~ 53
		string result;

		// 스트링 타입의 배열 만들기
		static const string CARD_TYPE[] = { "♠", "♣", "♥", "◆" }; // 스트링 타입의 문양 배열을 만들어 준다.
		static const string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" }; // 스트링 타입의 카드넘버 배열을 만들어 준다.

		for (int i = 0; i < 7; ++i)
		{
			if (deck[i] == 53)
			{
				result += "Joker, ";
			}

			else
			{
				result += CARD_TYPE[deck[i] / 13] + CARD_NUMBER[deck[i] % 13] + ", ";
			}
		}

		return result;
		//cardTypeIndex = 0 ~ 4, cardNumberIndex = 0 ~ 12
	}

	void printCard()
	{
		cout << ConvertToCardString() << " ";
		cout << "\n";
	}

};

bool Deck::isUsedCard[54] = { false };
int Deck::remainCard = 53;


int main()
{
	Deck deck;
	Deck deck1;
	Deck deck2;
	Deck deck3;
	Deck deck4;
	Deck deck5;
	Deck deck6;
	Deck deck7;

	deck.printCard();
	cout << endl;

	deck1.printCard();
	cout << endl;

	deck2.printCard();
	cout << endl;

	deck3.printCard();
	cout << endl;

	deck4.printCard();
	cout << endl;

	deck5.printCard();
	cout << endl;

	deck6.printCard();
	cout << endl;

	deck7.printCard();
	cout << endl;

	// 총 53장의 카드. -> 14개를 뽑아야함.
	// 두명의 플레이어에게 각각 7장을 배부.

	return 0;
}