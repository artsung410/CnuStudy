#include "Scene.h"
#include "Common.h"

#include "Text.h"
#include "Input.h"
#include "Renderer.h"
#include "Timer.h"
#include "Random.h"

Scene g_Scene;

static ESceneType s_nextScene = SCENE_NULL;

void setCoord(COORD* coord, int16 x, int16 y)
{
	coord->X = x;
	coord->Y = y;
}

#pragma region TitleScene
typedef struct tagTitleSceneData
{
	Text TitleText[3][128];
	COORD TitleCoords[3];
} TitleSceneData;

void reset_title(TitleSceneData* data)
{
	TextCopyWithWhite(data->TitleText[0], L"½ºÆäÀÌ½ºÅ°¸¦");
	TextCopyWithWhite(data->TitleText[1], L"´©¸£¸é");
	TextCopyWithWhite(data->TitleText[2], L"´ÙÀ½À¸·Î ³Ñ¾î°©´Ï´Ù.");

	setCoord(&data->TitleCoords[0], 10, 0);
	setCoord(&data->TitleCoords[1], 25, 10);
	setCoord(&data->TitleCoords[2], 35, 20);
}

void init_title(void)
{
	g_Scene.Data = malloc(sizeof(TitleSceneData));

	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	reset_title(data);
}

void update_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	if (data->TitleCoords[0].Y < 10)
	{
		static float elapsedTime;

		elapsedTime += Timer_GetDeltaTime();
		if (elapsedTime >= 0.3f)
		{
			elapsedTime = 0.0f;

			++data->TitleCoords[0].Y;
		}
	}

	if (data->TitleCoords[2].Y > 10)
	{
		static float elapsedTime;

		elapsedTime += Timer_GetDeltaTime();
		if (elapsedTime >= 0.3f)
		{
			elapsedTime = 0.0f;

			--data->TitleCoords[2].Y;
		}
	}

	if (Input_GetKeyDown('R'))
	{
		reset_title(data);
	}

	if (Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_MAIN);
	}

	if (Input_GetKeyDown('Q'))
	{
		Scene_SetNextScene(SCENE_LEESEUNGIL);
	}
}

void render_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 3; ++i)
	{
		Text* text = data->TitleText[i];
		int32 len = TextLen(text);
		COORD coord = data->TitleCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}
}

void release_title(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

#pragma endregion

#include "Game/Player.h"

#pragma region MainScene

typedef struct tagMainSceneData
{
	Player	Player;
} MainSceneData;

void init_main(void)
{
	g_Scene.Data = malloc(sizeof(MainSceneData));

	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Init(&data->Player);
}

void update_main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Update(&data->Player);
}

void render_main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Render(&data->Player);
}

void release_main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Release(&data->Player);

	SafeFree(g_Scene.Data);
}

#pragma endregion

#pragma region LeeSeungIlScene
typedef struct tagLeeSeungIlSceneData
{
	Text	SeungIlText[128];
	int32	Len;
	COORD	Coord;
} LeeSeungIlSceneData;

void init_leeseungil(void)
{
	g_Scene.Data = malloc(sizeof(LeeSeungIlSceneData));

	LeeSeungIlSceneData* data = (LeeSeungIlSceneData*)g_Scene.Data;
	TextCopy(data->SeungIlText, L"½ÂÀÏÀÌ ¿ÍÂÇ¿° »Ñ¿ì", BACK_COLOR_MAGENTA | TEXT_COLOR_CYAN | TEXT_COLOR_STRONG);
	data->Len = TextLen(data->SeungIlText);
	int32 x = Random_GetNumberFromRange(10, 30);
	int32 y = Random_GetNumberFromRange(0, 15);
	SetCoord(data->Coord, x, y);
}

void update_leeseungil(void)
{
	LeeSeungIlSceneData* data = (LeeSeungIlSceneData*)g_Scene.Data;

	static float elapsedTime;

	elapsedTime += Timer_GetDeltaTime();
	if (elapsedTime >= 0.1f)
	{
		elapsedTime = 0.0f;

		int32 x = Random_GetNumberFromRange(10, 30);
		int32 y = Random_GetNumberFromRange(0, 15);
		SetCoord(data->Coord, x, y);
	}
}

void render_leeseungil(void)
{
	LeeSeungIlSceneData* data = (LeeSeungIlSceneData*)g_Scene.Data;

	Renderer_DrawText(data->SeungIlText, data->Len, data->Coord.X, data->Coord.Y);
}

void release_leeseungil(void)
{
	SafeFree(g_Scene.Data);
}

#pragma endregion

bool Scene_IsSetNextScene(void)
{
	if (SCENE_NULL == s_nextScene)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Scene_SetNextScene(ESceneType scene)
{
	assert(s_nextScene == SCENE_NULL);
	assert(SCENE_NULL < scene&& scene < SCENE_MAX);

	s_nextScene = scene;
}

void Scene_Change(void)
{
	assert(s_nextScene != SCENE_NULL);

	if (g_Scene.Release)
	{
		g_Scene.Release();
	}

	switch (s_nextScene)
	{
	case SCENE_TITLE:
		g_Scene.Init = init_title;
		g_Scene.Update = update_title;
		g_Scene.Render = render_title;
		g_Scene.Release = release_title;
		break;
	case SCENE_MAIN:
		g_Scene.Init = init_main;
		g_Scene.Update = update_main;
		g_Scene.Render = render_main;
		g_Scene.Release = release_main;
		break;
	case SCENE_LEESEUNGIL:
		g_Scene.Init = init_leeseungil;
		g_Scene.Update = update_leeseungil;
		g_Scene.Render = render_leeseungil;
		g_Scene.Release = release_leeseungil;
		break;
	}

	g_Scene.Init();

	s_nextScene = SCENE_NULL;
}