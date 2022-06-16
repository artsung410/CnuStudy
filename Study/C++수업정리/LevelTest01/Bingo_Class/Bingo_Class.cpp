#include <iostream>
#include <Windows.h>

using namespace std;
class BingGo
{
	static const int BLANK = 0;
	static const int BOARD_SIZE = 5;
	static const int BIGO_AMOUNT = 12;

	int board[BOARD_SIZE][BOARD_SIZE]; // 판 깔아줄게
	int bingoCount = 0; // 숫자 새어줄게.

public:
	BingGo()
	{
		BingoSetting();
	}

	BingGo(const BingGo& other) = delete;
	BingGo& operator=(const BingGo& other) = delete;
	~BingGo() = default;

	// 빙고판 출력 해 줄게!
	void Print()
	{
		for (int r = 0; r < BOARD_SIZE; ++r)
		{
			for (int c = 0; c < BOARD_SIZE; ++c)
			{
				if (board[r][c] == BLANK)
				{
					cout << "\t";
				}
				else
				{
					cout << board[r][c] << "\t";
				}
			}

			cout << "\n";
		}
		cout << "현재 " << bingoCount << "줄의 빙고가 완성되었습니다\n";
	}

	// 입력받은 숫자 지워 줄게!
	void Update(int input)
	{
		if (input < 0 || input > 25)
		{
			return;
		}

		for (int r = 0; r < BOARD_SIZE; ++r)
		{
			bool isExit = false;
			for (int c = 0; c < BOARD_SIZE; ++c)
			{
				if (board[r][c] == input)
				{
					board[r][c] = BLANK;
					isExit = true;

					break;
				}
			}

			if (isExit)
			{
				break;
			}
		}

		CountBingo();
	}

	// 빙고 다끝나면 알려줄게!
	bool IsCompleted()
	{
		if (bingoCount == BIGO_AMOUNT)
		{
			return true;
		}

		return false;
	} // 

private:
	// 랜덤하게 배치 해 줄게!
	void BingoSetting()
	{
		bool isUsed[26] = { false };
		for (int r = 0; r < BOARD_SIZE; ++r)
		{
			for (int c = 0; c < BOARD_SIZE; ++c)
			{
				int n = 0;
				do
				{
					n = 1 + rand() % 25;
				} while (isUsed[n]);

				board[r][c] = n;
				isUsed[n] = true;
			}
		}
	}

	// 빙고되면 숫자 새어줄게!
	void CountBingo()
	{
		// 5. 빙고 개수를 샌다
		// - 가로의 모든 숫자를 지운 것
		int count = 0;

		for (int r = 0; r < BOARD_SIZE; ++r)
		{
			bool isBingo = true;
			for (int c = 0; c < BOARD_SIZE; ++c)
			{
				if (board[r][c] != BLANK)
				{
					isBingo = false;

					break;
				}
			}
			if (isBingo)
			{
				++count;
			}
		}

		// - 세로의 모든 숫자를 지운 것
		for (int r = 0; r < BOARD_SIZE; ++r)
		{
			bool isBingo = true;
			for (int c = 0; c < BOARD_SIZE; ++c)
			{
				if (board[c][r] != BLANK)
				{
					isBingo = false;

					break;
				}
			}
			if (isBingo)
			{
				++count;
			}
		}

		// - 대각선의 모든 숫자를 지운 것
		// [0][0] / [1][1] / [2][2] / [3][3] / [4][4]
		{
			bool isBingo = true;
			for (int i = 0; i < BOARD_SIZE; ++i)
			{
				if (board[i][i] != BLANK)
				{
					isBingo = false;
					break;
				}
			}

			if (isBingo)
			{
				++count;
			}
		}

		// [0][4] / [1][3] / [2][2] / [3][1] / [4][0]
		{
			bool isBingo = true;
			for (int i = 0; i < BOARD_SIZE; ++i)
			{
				if (board[i][4 - i] != BLANK)
				{
					isBingo = false;

					break;
				}
			}

			if (isBingo)
			{
				++count;
			}
		}
		
		bingoCount = count;
	}
};


int main()
{
	BingGo myBingo;

	while (false == myBingo.IsCompleted()) // while ( false == bingo.IsCompleted() )
	{
		myBingo.Print();

		cout << "숫자를 입력해주세요 : ";
		int input;
		cin >> input;


		myBingo.Update(input);
		system("cls");
	}
}
