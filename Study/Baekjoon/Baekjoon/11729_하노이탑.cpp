#include <iostream>

using namespace std;

           //            1,          3,           2
void hanoi(int n, int from_pos, int to_pos, int aux_pos)
{
	if (n == 1)
	{
		// 1 - > 3
		cout << from_pos << " " << to_pos << "\n";
		return;
	}

	// 1 - > 2
	hanoi(n - 1, from_pos, aux_pos, to_pos);

	// 1 - > 3
	cout << from_pos << " " << to_pos << "\n";
	
	// 2  -> 3
	hanoi(n - 1, aux_pos, to_pos, from_pos);
}


int main()
{
	int N;
	cin >> N;

	int addNum = 1;
	int phase = 0;
	for (int i = 0; i < N; i++)
	{
		addNum *= 2;
	}

	phase = addNum - 1;

	std::cout << phase << "\n";

	hanoi(N, 1, 3, 2);

	return 0;
}