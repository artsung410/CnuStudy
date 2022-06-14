#include <iostream>
#include <string>
#include <sstream>

using namespace std;



// 0 ~ 12 : 스페이드
// 13 ~ 25 : 클로버
// 26 ~ 38 : 하트
// 38 ~ 51 : 다이아몬드
// 52 : 조커
bool isUsedCard[53] = { false };

/// <summary>
/// 카드 7장을 뽑는다.
/// </summary>
int* PickCard()
{ //동적할당 
	int* deck = new int[7];

	for (int i = 0; i < 7; i++) // 카드를 7개 뽑는다
	{
		// 중복 처리
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

	return deck;
}

/// <summary>
/// 카드 7장을 뽑는다.
/// </summary>
/// <param name="deck">플레이어의 덱</param>
void PickCard(int* deck)
{
	// 김재민
	for (int i = 0; i < 7; i++) // 카드를 7개 뽑는다
	{
		// 중복 처리
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
}

/// <summary>
/// cardIndex를 대응되는 card 문자열로 바꾼다.
/// // 0 ~ 12 : 스페이드 => 0
	// 13 ~ 25 : 클로버 => 1
	// 26 ~ 38 : 하트 => 2
	// 38 ~ 51 : 다이아몬드 => 3
	// 52 : 조커 =>4

	// 12가 들어오면 ♠12
/// </summary>
/// <param name="cardIndex"></param>
/// <returns></returns>

std::string ConvertToCardString(int cardIndex)
{
	int cardTypeIndex = cardIndex / 13;
	int cardNumberIndex = cardIndex % 13;

	// Lookup Table
	static const string CARD_TYPE[] = { "♠", "♣", "♥", "◆" };
	static const string CARD_NUMBER[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

	string result = CARD_TYPE[cardIndex / 13];
	// CARD_TYPE[0] : "♠"
	// CARD_TYPE[1] : "♣"
	// CARD_TYPE[2] : "♥"
	// CARD_TYPE[3] : "◆"

	int cardNumber = cardIndex % 13;


	if (cardTypeIndex == 4)
	{
		return "Joker";
	}
	else
	{
		return CARD_TYPE[cardTypeIndex] + CARD_NUMBER[cardNumberIndex];
	}
}

int main()
{
	int player1Deck[7] = { 0 };
	PickCard(player1Deck);

	int* player2Deck = PickCard();

	for (int i = 0; i < 7; ++i)
	{
		cout << ConvertToCardString(player1Deck[i]) << " ";
	}
	cout << "\n";

	for (int i = 0; i < 7; ++i)
	{
		cout << ConvertToCardString(player2Deck[i]) << " ";
	}
	cout << "\n";

	delete[] player2Deck;
}