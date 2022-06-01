#include "App.h"
#include "Common.h"
#include "Renderer.h"
#include "Timer.h"
#include "Input.h"
#include "Random.h"

#include "Game/Scene.h"

bool App_Init()
{
	if (false == Renderer_Init())
	{
		return false;
	}

	Random_Init();

	return true;
}

void processInput()
{
	Input_Update();
}

void update()
{
	g_Scene.Update();
}

void render()
{
	g_Scene.Render();
	Renderer_Flip();
}

void cleanup(void)
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);

	Timer_Init(60);

	Scene_SetNextScene(SCENE_TITLE);

	while (true)
	{
		if (Scene_IsSetNextScene())
		{
			Scene_Change(); // 
		}

		if (Timer_Update())
		{
			processInput();		// 입력
			update();			// 처리
			render();			// 출력
		}
	}

	return 0;
}