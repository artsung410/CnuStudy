/*
L 	 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)

D	 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)

B	 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
	 삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임

P $	 $라는 문자를 커서 왼쪽에 추가함

단, 명령어가 수행되기 전 커서는 문장의 맨뒤

첫째줄 입력되는 문자열
	길이가 N <= 100000

둘째줄 입력할 명령어 개수
	정수 1 <= M <= 500000

셋째줄 입력할 명령어 순서대로
	M개 입력한다

출력
	모든 명령어를 수행한 문자열 출력한다.
*/

#include <iostream>
#include <list>

// 선형리스트 사용시 중간임의의 곳 을 수정할때 비효율적이므로 연결리스트를 쓰자


// 알고리즘문제를 풀땐 전역변수를 사용하면 편하다
std::string s;
int M;

int main()
{
	// 입출력 속도 향상
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	// 1. 문자열을 입력받는다
	std::cin >> s;

	// 2. 명령어의 개수 입력
	std::cin >> M;

	// 3. 명령어 처리
	std::list<char> lst(s.begin(), s.end());
	std::list<char>::iterator cursor = lst.end();

	while (M--)
	{
		// 3-1 명령어 입력받는다
		char op;
		std::cin >> op;

		// 3-2 각 명령어에 맞게 실행
		switch (op)
		{
		case 'L':
			if (cursor != lst.begin())
			{
				--cursor;
			}
			break;
		case 'D':
			if (cursor != lst.end())
			{
				++cursor;
			}
			break;
		case 'B':
			if (cursor != lst.begin())
			{
				--cursor;
				cursor = lst.erase(cursor); // 반복자가 무효화 될 수 있다.
			}
			
			break;
		case 'P':
			char ch;
			std::cin >> ch;

			cursor = lst.insert(cursor, ch); //  inserts value before pos
			++cursor;

			break;
		default:
			break;
		}
	}

	for (std::list<char>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
	{
		std::cout << *iter;
	}
}