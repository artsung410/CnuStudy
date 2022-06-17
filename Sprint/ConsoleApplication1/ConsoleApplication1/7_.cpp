/*
"초당 30프레임으로 화면을 갱신하면서 현재 누르고 있는 키(A~Z)를 표시하는 코드를 작성하시오

출력 화면에는 다음 정보가 실시간으로 표시됩니다.
1. 프레임 번호( 1~30까지 늘어나며 31이 되면 다시 1로 바뀜 )
2. 프레임당 시간
3. 현재 누르고 있는 알파벳 키( 대소문자 구분 없이 알파벳 표시 )"


*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

// 매 프레임의 시작시간, 끝시간측정 필요

//프레임딜레이
// 시작시간 ~ 처리끝낸시간

int main()
{
	// 1. 초기화 진행
	clock_t startTime, endTime; // 1/1000초 단위로 시간을 숫자로 표시해주는 자료형 clock_t
	float processTime = 0.0f;
	int delayTime = 0;
	int sum = 0;
	char ch = ' ';
	int fixedFps = 30;

	while (true) // 매 프레임이 돌아가는중
	{
		system("cls");
		// 여기서 시작시간을 측정필요
		startTime = clock(); // 현재시간을 반환
		//cout << "start : " << startTime << endl;

		// 2. Input
		sum++;
		if (sum > fixedFps)
		{
			sum = 0;
		}

		// 키입력을 받으면
		if (_kbhit())
		{
			ch = _getch(); // 입력키값이 담긴다.
		}


		// 4. Render
		cout << "프레임 번호 :  " << sum << endl;

		cout << "프레임당 시간 : " << delayTime << endl;

		cout << "현재 알파벳 키 : " << ch << endl;

		// 출력끝난뒤 종료시간을 측정
		endTime = clock();
		//cout << "end : " << endTime << endl;
		
		// 종료시간 - 시작시간 = 처리하는데 걸린 시간
		processTime = (float)(endTime - startTime);
		cout << "Updating... " << processTime << endl;


		delayTime = fixedFps - processTime;
		cout << "delay... " << delayTime << endl;
		// 1/30 - (종료시간 - 시작시간)


		Sleep(delayTime);
	}

}