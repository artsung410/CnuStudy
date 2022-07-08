#include <iostream>

#include <vector>

using namespace std;

int digitCount[51];

// 각항생의 정보를 담기위한 구조체를 선언한다.
struct Student
{
	int x; // 학생의 몸무게
	int y; // 학생의 키
	int BodyRank; // 학급에서 자신의 덩치 순위

	Student(int _x, int _y, int _rank) : x(_x), y(_y), BodyRank(_rank) {} // 생성자를 만들어 데이터를 받는다.
};

vector<Student> v;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int X, Y;
		cin >> X >> Y;

		int bodyRank = 1;

		v.push_back(Student(X, Y, bodyRank)); // 일단 들어오는 학생의 정보를 컨테이너를 이용해 담는다.
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// 만약 현재 학생의 덩치가 비교대상보다 작으면 순위를 내린다.
			if (v[i].x < v[j].x && v[i].y < v[j].y)
			{
				++v[i].BodyRank;
			}

			// 그렇지 않으면 현재 순위 유지.
			else
			{
				continue;
			}

		}
	}


	for (int i = 0; i < N; i++)
	{
		cout << v[i].BodyRank << " ";
	}


	return 0;
}
