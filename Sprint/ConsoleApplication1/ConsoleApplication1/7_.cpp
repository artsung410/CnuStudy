/*
"초당 30프레임으로 화면을 갱신하면서 현재 누르고 있는 키(A~Z)를 표시하는 코드를 작성하시오
출력 화면에는 다음 정보가 실시간으로 표시됩니다.
1. 프레임 번호( 1~30까지 늘어나며 31이 되면 다시 1로 바뀜 )
2. 초당 프레임( fps )
3. 현재 누르고 있는 알파벳 키( 대소문자 구분 없이 알파벳 표시 )"
*/

#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

int main()
{
	//float fixedTime = 1.0 / 30;
	clock_t prevTime = clock();

	while (true) // 한번실행시 1프레임
	{
		clock_t currentTime = clock();

		float elapsedTime = 0;

		// 한프레임당 걸리는 시간

		float deltaTime = (float)(currentTime - prevTime) / CLOCKS_PER_SEC;
		elapsedTime += deltaTime;

		if (elapsedTime <= 1)
		{

			cout << "프레임 번호 : " << elapsedTime << endl;

			deltaTime = 0;
		}

		/*cout << "초당 프레임 : " <<  endl;

		cout << "현재 누르고 있는 알파벳 키 : ";
		char input = _getch();
		cout << input << endl;
		system("cls");*/

		//Sleep(10);
	}

}