#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

#define MAXNUM 300000

int N;
stack<int> st; // 백터에서 뺀 값 넣을 스택
vector<int> vec; // 처음에 입력값 넣을 벡터
vector<int> pure; // 정렬안한 벡터


int arr[MAXNUM];
char ch[MAXNUM];


int flag; // 고정핀 조건만족할때만 올리기
int cnt; // 순회
int chCnt;
int loofChk;

//stack<int> vSt; // 정렬안하고 

int main()
{
	// 입력
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		vec.push_back(input);
		pure.push_back(input);
	}
	
	sort(vec.begin(), vec.end()); // 벡터 정렬함
	/*st.push(vec[cnt]);
	cnt++;*/

	while (flag != N)
	{
		if (loofChk > cnt)
		{
			cout << "NO";
			return 0;
		}
		while (true)
		{
			if (st.empty())
			{
				break;
			}
			if (st.top() == pure[flag])
			{
				arr[flag] = st.top();
				st.pop();
				//cout << "-\n";
				ch[chCnt] = '-';
				chCnt++;
				flag++;
			}
			else
			{
				loofChk++;
				break;
			}
		}

		if (cnt < N)
		{
			st.push(vec[cnt]);
			cnt++;
			ch[chCnt] = '+';
			++chCnt;
			//cout << "+\n";
		}
	}

	int correct = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == pure[i])
		{
			++correct;
		}
	}

	if (correct == N)
	{
		for (int i = 0; ch[i] != '\0'; i++)
		{
			cout << ch[i] << "\n";
		}
	}

}
		// 벡터 순회, 맨앞 삭제
		// 정렬된 벡터를 스택에 push
		// push도 조건필요?
		// 정렬되지않은 처음 넣은 벡터의 첫번째 인덱스를 만나면
		// 스택 top을 pop한다
		// 스택 top이 벡터 다음인덱스와 같은지 검사
		// 같으면 pop 다르면 push한다
		// 위 과정을 벡터가 빌때까지 반복한다
		// 벡터가 다 빈 상태에서 스택에 쌓인값과 순정벡터값이 다르면
		// NO를 출력한다

	// 스택에서 뽑은 순서와 기존 입력배열 순서가 다르면 NO 아니면 그대로 출력
	

	// 출력: 수열을 만들기 위해 필요한 연산 한줄에 한개씩 push == +, pop == -, else == NO

/*
     0 1 2 3 4 5 6 7
처음: 4 3 6 8 7 5 2 1 벡터
     0 1 2 3 4 5 6 7
정렬: 1 2 3 4 5 6 7 8 벡터
cnt		= 3
flag	= 2
push: 1 2  
pop	: 4 3
스택: 1 2 5 7 8 6 3 4

		+ 1
		+ 1 2
		+ 1 2 3
		+ 1 2 3 4
		- 1 2 3 [4]
		- 1 2 [4 3]
		+ 1 2 5
		+ 1 2 5 6
		- 1 2 5 [4 3 6]
		+ 1 2 5 7
		+ 1 2 5 7 8
		- 1 2 5 7 [4 3 6 8]
		- 1 2 5 [4 3 6 8 7]
		- 1 2 [4 3 6 8 7 5]
		- 1 [4 3 6 8 7 5 2]
		- [4 3 6 8 7 5 2 1] <- 처음 입력값이 나온다

처음: 1 2 5 3 4
스택: 4 3 5 2 1
정렬: 1 2 3 4 5
		+ 1
		- [1]
		+ 2 [1]
		- [1 2]
		+ 3 [1 2]
		+ 3 4 [1 2]
		+ 3 4 5 [1 2]
		- 3 4 [1 2 5]
		- 3 [1 2 5 4] <- 처음입력값이 안나옴
		
*/