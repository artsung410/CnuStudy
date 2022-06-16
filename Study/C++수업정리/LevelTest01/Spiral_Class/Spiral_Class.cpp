#include <iostream>
#include <Windows.h>

#define NOT_VISITED 0

using namespace std;

class Spiral
{

public:
	Spiral(int _size) : size(_size), arr(new int[size * size])
	{
		memset(arr, 0, sizeof(int) * size * size);
	}
	
	~Spiral()
	{
		delete[] arr;
	}

	void Update()
	{
		// 2. 달팽이 배열 세팅
		// 2-1. 달팽이 데이터 초기화
		int r = 0; // 달팽이의 위치(y 좌표)
		int c = 0; // 달팽이의 위치(x 좌표)
		int footstep = 1; // 발자국
		enum Direction { DIR_RIGHT, DIR_DOWN, DIR_LEFT, DIR_UP, DIR_MAX };
		Direction direction = DIR_RIGHT; // 달팽이가 움직이는 방향

		for (int i = 0; i < size * size; ++i)
		{
			// 2-2. 발자국을 남긴다.
			arr[r * size + c] = footstep;
			++footstep;

			// 2-3. 이동할 위치를 계산한다.
			static const int dr[] = { 0, 1, 0, -1 };
			static const int dc[] = { 1, 0, -1, 0 };

			int nr = r + dr[(int)direction];
			int nc = c + dc[(int)direction];

			// 2-4. 이동이 가능한지 판별한다. 
			// 2-4-1. 벽에 닿았을 때 => r, c의 위치가 [0, size)
			// 2-4-2. 이미 지나온 곳일 때 => arr[nr][nc] != 0
			if (nr < 0 || nr >= size || nc < 0 || nc >= size ||
				arr[nr * size + nc] != NOT_VISITED)
			{
				// 2-5. 이동이 불가능하므로 방향 전환을 한다.
				direction = (Direction)((direction + 1) % DIR_MAX);

				// 2-6. 위치값을 다시 계산한다.
				nr = r + dr[(int)direction];
				nc = c + dc[(int)direction];
			}

			// 2-7. 이동한다.
			r = nr;
			c = nc;
		}
	}

	void Renderer()
	{
		for (int r = 0; r < size; ++r)
		{
			for (int c = 0; c < size; ++c)
			{
				cout << arr[r * size + c] << "\t";
			}
			cout << "\n";
		}
	}

private:
	int size;
	int* arr = nullptr;
};

int main()
{
	while (1)
	{
		cout << "\n";
		cout << "배열의 크기를 입력하세요 : ";
		int size;
		cin >> size;

		Spiral spiral = { size };

		spiral.Update();
		system("cls");

		spiral.Renderer();
	}
}

