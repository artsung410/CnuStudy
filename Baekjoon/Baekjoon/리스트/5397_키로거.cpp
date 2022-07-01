/*
첫째줄
	테스트 케이스 개수

각 테스트 케이스는 한줄
입력한 순서대로 길이 L인 문자열

백스페이스 '-' 
	커서 바로 앞에 글자 존재하면 지운다

화살표 '<', '>'
	커서이동가능시 왼쪽 오른쪽으로 1만큼 이동

만약 커서의 위치가 줄의 마지막이 아니라면,
커서 및 커서 오른쪽에있는 모든 문자는 오른쪽으로 한 칸 이동

<<BP<A>>Cd-		=>      BAPC
*/

		// 빈 리스트를 만든다
		// 반복자 만든다
		// 문장이 입력된 문자열만든다
		// 문자는 빈 리스트에 저장한다
		// 명령어를 만나면 반복자가 움직인다
		// 위 과정을 반복한다

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	// 1. 입출력
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int testCase;
	cin >> testCase;
	while (testCase--)
	{
		// 1. 문자열 입력받기
		string input;
		cin >> input;
		
		/*
		// 새로운 문법 range-based for loop
		for (char ch : input)
		{
			// 컨테이너를 수정하면 x
			// 컨테이너에 데이터를 삽입하거나 삭제하면 x

			// 오직 순회의 목적이다.
		}
		*/

		// 컨테이너 2개 생성
		// 하나는 커서 왼편에 존재하는 문자열로 정방향으로 저장
		// 다른 하나는 커서 오른편에 존재하는 문자열로 역방향으로 저장
		vector<char> left, rightReversed;

		// 2. 각 문자를 적절하게 처리
		for (char ch : input)
		{
			switch (ch)
			{
				case '<':
					if (false == left.empty())
					{
						rightReversed.push_back(left.back());
						left.pop_back();
					}
					break;
				case '>':
					if (false == rightReversed.empty())
					{
						left.push_back(rightReversed.back());
						rightReversed.pop_back();
					}
					break;
				case '-':
					if (false == left.empty())
					{
						left.pop_back();
					}
					break;
				default:
					left.push_back(ch);
					break;
			}
		}
		
		cout << string(left.begin(), left.end()) << string(rightReversed.rbegin(), rightReversed.rend()) << "\n";
	}
}