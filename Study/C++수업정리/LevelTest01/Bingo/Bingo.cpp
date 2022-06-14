#include <iostream>

using namespace std;

#define BLANK 0

int main()
{
	// 1. 빙고판 세팅
	bool isUsed[26] = { false };
	int board[5][5];
	for (int r = 0; r < 5; ++r)
	{
		for (int c = 0; c < 5; ++c)
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

	int bingoCount = 0;
	while (bingoCount < 12)
	{
		system("cls");

		// 2. 빙고판 출력
		for (int r = 0; r < 5; ++r)
		{
			for (int c = 0; c < 5; ++c)
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

		// 3. 사용자 입력 받음
		cout << "숫자를 입력해주세요 : ";
		int input;
		cin >> input;

		// 3-1. 오입력 처리
		if (input < 0 || input > 25)
		{
			// 2번부터 다시
			continue;
		}

		// 4. 빙고판 업데이트
		for (int r = 0; r < 5; ++r)
		{
			bool isExit = false;
			for (int c = 0; c < 5; ++c)
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

		// 5. 빙고 개수를 샌다.

		// - 가로의 모든 숫자를 지운 것
		int count = 0;

		for (int r = 0; r < 5; ++r)
		{
			bool isBingo = true;
			for (int c = 0; c < 5; ++c)
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
		for (int r = 0; r < 5; ++r)
		{
			bool isBingo = true;
			for (int c = 0; c < 5; ++c)
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
			for (int i = 0; i < 5; ++i)
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
			for (int i = 0; i < 5; ++i)
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
	// 6. 2번부터 다시 반복한다.
}