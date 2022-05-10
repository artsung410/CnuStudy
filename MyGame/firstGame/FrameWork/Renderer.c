#include "Renderer.h"
#include "Common.h"

HANDLE s_consoleHandle;
HANDLE s_screens[2];
int32 s_backIndex;

bool Renderer_Init(void)
{
	//1. 콘솔에대한 핸들울 얻는다
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

	//2. 스크린만든다 더블버퍼를위한 화면 두개 생성
	for (int32 i = 0; i < 2; i++)
	{
		s_screens[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	}
}

void Renderer_Cleanup(void)
{
	CloseHandle(s_consoleHandle);
	CloseHandle(s_screens[0]);
	CloseHandle(s_screens[1]);
}

void clear(HANDLE consoleHandle)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consoleHandle, &csbi);

	SMALL_RECT scrollRect;
	scrollRect.Left = 0;
	scrollRect.Top = 0;
	scrollRect.Right = csbi.dwSize.X;
	scrollRect.Bottom = csbi.dwSize.Y;

	COORD scrollTarget;
	scrollTarget.X = 0;
	scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

	CHAR_INFO fill;
	fill.Char.UnicodeChar = TEXT(' ');
	fill.Attributes = csbi.wAttributes;

	ScrollConsoleScreenBuffer(consoleHandle, &scrollRect, NULL, scrollTarget, &fill);

	csbi.dwCursorPosition.X = 0;
	csbi.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(consoleHandle, csbi.dwCursorPosition);
}


void Renderer_Flip(void)
{
	//1. 백 버퍼로 화면지정
	SetConsoleActiveScreenBuffer(s_screens[s_backIndex]);

	//2. 백 버퍼를 바꿔준다
	s_backIndex = !s_backIndex;

	//3. 백 버퍼에 있는 화면을 지워준다. system cls쓸수없다
	clear(s_screens[s_backIndex]);
}

void Renderer_DrawText(const char* text, int32 numberOfChar)
{
	//1. 백버퍼에대한 핸들을가져온다
	HANDLE backBuffer = s_screens[s_backIndex];

	//2. 백버퍼에 텍스트 출력
	WriteConsoleA(backBuffer, text, numberOfChar, NULL, NULL); //WriteConsoleA 뒤에 A붙은건 멀티바이트 W붙으면 유니코드
}