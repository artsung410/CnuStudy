#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char map[51][51];

#define MAX 8

// 정답1
char chess1[MAX][MAX] =
{
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};

// 정답2
const char chess2[MAX][MAX] =
{
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};

int main()
{
	int y, x;
	cin >> y >> x;
	
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> map[i][j];
		}
	}

	int k = 0;
	int s = 0;
	while (1)
	{	
		int chess1Count = 0;
		int chess2Count = 0;

		for (int i = 0; i < MAX; i++)
		{
			for (int j = 0; j < MAX; j++)
			{
				if ((j + k) < x && (j + s) < y)
				{
					if (chess1[i][j] == map[i + s][j + k])
					{
						++chess1Count;
					}

					else
					{
						++chess2Count;
					}
				}
			}
		}

		v1.push_back(chess1Count);
		v2.push_back(chess2Count);

		chess1Count = 0;
		chess2Count = 0;

		++k;

		if (k == (x - MAX + 1))
		{
			k = 0;
			++s;
		}

		if (s == (y - MAX + 1))
		{
			break;
		}

	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	if (v1[0] < v2[0])
	{
		cout << v1[0];
	}
	else
	{
		cout << v2[0];
	}


	return 0;
}