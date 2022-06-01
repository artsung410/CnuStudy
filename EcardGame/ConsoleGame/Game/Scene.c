#include "Scene.h"
#include "Common.h"

#include "Framework/Text.h"
#include "Framework/Input.h"
#include "Framework/Renderer.h"
#include "Framework/Timer.h"

#include "Player.h"

<<<<<<< HEAD
=======

bool isComputerKing = true;

>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
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
	Text TitleText[3][128]; // 텍스트 담을 배열 선언하고,
	COORD TitleCoords[3]; // 포지션 잡고
} TitleSceneData;



void reset_title(TitleSceneData* data)
{
	TextCopyWithMagenta(data->TitleText[0], L"카"); // 첫번재 텍스트 카피
	TextCopyWithMagenta(data->TitleText[1], L"이");
	TextCopyWithMagenta(data->TitleText[2], L"지");

	setCoord(&data->TitleCoords[0], 10, 0); // 첫번째 텍스트 포지션 업데이트
	setCoord(&data->TitleCoords[1], 25, 10); // 두번째 텍스트 포지션 업데이트
	setCoord(&data->TitleCoords[2], 35, 20); // 세번재 텍스트 포지션 업데이트
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
		Scene_SetNextScene(SCENE_BETTING);
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

#pragma region BettingScene
typedef struct tagBettingSceneData
{
	Text BettingText[6][128]; // 텍스트 담을 배열 선언하고,
	COORD BettingCoords[6]; // 포지션 잡고
<<<<<<< HEAD
=======

	Text PlayerTexts[2][128];
	COORD PlayerCoords[2];

>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
} BettingSceneData;


void reset_betting(BettingSceneData* data)
{
	TextCopyWithWhite(data->BettingText[0], L"1회전"); // 첫번재 텍스트 카피
<<<<<<< HEAD
	TextCopyWithWhite(data->BettingText[1], L"Computer : 황제진영");
	TextCopyWithWhite(data->BettingText[2], L"Player : 노예진영");
=======
	TextCopyWithWhite(data->BettingText[1], L"Computer : ");
	TextCopyWithWhite(data->BettingText[2], L"Player : ");
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
	TextCopyWithWhite(data->BettingText[3], L"배팅금액을 고르시오");
	TextCopyWithWhite(data->BettingText[4], L"[100만]  [200만]  [300만]  [400만]  [500만]");
	TextCopyWithWhite(data->BettingText[5], L"↑");

<<<<<<< HEAD
	setCoord(&data->BettingCoords[0], 5, 10);
	setCoord(&data->BettingCoords[1], 5, 12); 
	setCoord(&data->BettingCoords[2], 5, 14); 
	setCoord(&data->BettingCoords[3], 5, 16); 
	setCoord(&data->BettingCoords[4], 5, 18); 
	setCoord(&data->BettingCoords[5], 7, 20); 
=======
	if (isComputerKing)
	{
		TextCopyWithWhite(&data->PlayerTexts[0], L"황제");
		TextCopyWithWhite(&data->PlayerTexts[1], L"노예");
	}

	setCoord(&data->BettingCoords[0], 5, 10);
	setCoord(&data->BettingCoords[1], 5, 12); // computer :
	setCoord(&data->BettingCoords[2], 5, 14); // player :
	setCoord(&data->BettingCoords[3], 5, 16); 
	setCoord(&data->BettingCoords[4], 5, 18); 
	setCoord(&data->BettingCoords[5], 7, 20); 
	setCoord(&data->PlayerCoords[0], 20, 12);
	setCoord(&data->PlayerCoords[1], 20, 14);
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
}

void init_betting(void)
{
	g_Scene.Data = malloc(sizeof(BettingSceneData));

	BettingSceneData* data = (BettingSceneData*)g_Scene.Data;

	reset_betting(data);
}

void update_betting(void)
{
	BettingSceneData* data = (BettingSceneData*)g_Scene.Data;
	COORD coord = data->BettingCoords[5];

<<<<<<< HEAD
	if (Input_GetKeyDown(VK_LEFT))
	{
		if (coord.X > 7)
		{
			coord.X -= 9;
		}
		setCoord(&data->BettingCoords[5], coord.X, coord.Y);
=======

	if (Input_GetKeyDown(VK_LEFT))
	{
		if (data->BettingCoords[5].X > 7)
		{
			coord.X -= 9;
		}
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
	}

	if (Input_GetKeyDown(VK_RIGHT))
	{
<<<<<<< HEAD
		if (coord.X < 36)
		{
			coord.X += 9;
		}
		setCoord(&data->BettingCoords[5], coord.X, coord.Y);
=======
		if (data->BettingCoords[5].X < 43)
		{
			coord.X += 9;
		}
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
	}

	if (Input_GetKeyDown(VK_RETURN))
	{
		int32 bettingAmount;
<<<<<<< HEAD
		switch (coord.X)
=======
		switch (data->BettingCoords[5].X)
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
		{
		case(7):
			bettingAmount = 100;
			break;
		case(16):
			bettingAmount = 200;
			break;
		case(25):
			bettingAmount = 300;
			break;
		case(34):
			bettingAmount = 400;
			break;
<<<<<<< HEAD
		}
		Scene_SetNextScene(SCENE_MAIN);
	}
=======
		case(43):
			bettingAmount = 400;
			break;
		}
		Scene_SetNextScene(SCENE_MAIN);
	}

	setCoord(&data->BettingCoords[5], coord.X, coord.Y);
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
}

void render_betting(void)
{
	BettingSceneData* data = (BettingSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 6; ++i)
	{
		Text* text = data->BettingText[i];
		int32 len = TextLen(text);
		COORD coord = data->BettingCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}

<<<<<<< HEAD
=======
	for (int32 i = 0; i < 6; ++i)
	{
		Text* text = data->PlayerTexts[i];
		int32 len = TextLen(text);
		COORD coord = data->PlayerCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
}

void release_betting(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

#pragma endregion

#pragma region MainScene

typedef struct tagMainSceneData
{
<<<<<<< HEAD
	Player	Player;
} MainSceneData;

void init_main(void)
=======
	Text MainText[7][128]; // 텍스트 담을 배열 선언하고,
	COORD MainCoords[7]; // 포지션 잡고
} MainSceneData;



void reset_Main(MainSceneData* data)
{
	TextCopyWithWhite(data->MainText[0], L"┌─────────┐┌─────────┐┌─────────┐┌─────────┐┌─────────┐"); // 첫번재 텍스트 카피
	TextCopyWithWhite(data->MainText[1], L"│*********││*********││*********││*********││*********│");
	TextCopyWithWhite(data->MainText[2], L"│*********││*********││*********││*********││*********│");
	TextCopyWithWhite(data->MainText[3], L"│*********││*********││*********││*********││*********│");
	TextCopyWithWhite(data->MainText[4], L"│*********││*********││*********││*********││*********│");
	TextCopyWithWhite(data->MainText[5], L"│*********││*********││*********││*********││*********│");
	TextCopyWithWhite(data->MainText[6], L"└─────────┘└─────────┘└─────────┘└─────────┘└─────────┘");

	for (int i = 0; i < 7; i++)
	{
		setCoord(&data->MainCoords[i], 0, i);
	}
}

void init_Main(void)
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
{
	g_Scene.Data = malloc(sizeof(MainSceneData));

	MainSceneData* data = (MainSceneData*)g_Scene.Data;

<<<<<<< HEAD
	Player_Init(&data->Player);
}

void update_main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	Player_Update(&data->Player);

	//if (Input_GetKeyDown(VK_F8))
	//{
	//	Scene_SetNextScene(SCENE_ENDING);
	//}
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
=======
	reset_Main(data);
}

void update_Main(void)
{

}

void render_Main(void)
{
	MainSceneData* data = (MainSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 7; ++i)
	{
		Text* text = data->MainText[i];
		int32 len = TextLen(text);
		COORD coord = data->MainCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}

	for (int32 i = 0; i < 7; ++i)
	{
		Text* text = data->MainText[i];
		int32 len = TextLen(text);
		COORD coord = data->MainCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y + 8);
	}

}

void release_Main(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
}

#pragma endregion

#pragma region EndingScene

typedef struct tagEndingSceneData
{
	Text TitleText[3][128]; // 텍스트 담을 배열 선언하고,
	COORD TitleCoords[3]; // 포지션 잡고
} EndingSceneData;

void reset_ending(EndingSceneData* data)
{
	TextCopyWithMagenta(data->TitleText[0], L"asdfasdf"); // 첫번재 텍스트 카피
	TextCopyWithMagenta(data->TitleText[1], L"xcvxcv");
	TextCopyWithMagenta(data->TitleText[2], L"asdfasdf");

	setCoord(&data->TitleCoords[0], 10, 0); // 첫번째 텍스트 포지션 업데이트
	setCoord(&data->TitleCoords[1], 25, 10); // 두번째 텍스트 포지션 업데이트
	setCoord(&data->TitleCoords[2], 35, 20); // 세번재 텍스트 포지션 업데이트
}

void init_ending(void)
{
	g_Scene.Data = malloc(sizeof(EndingSceneData));

	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

	reset_ending(data);
}

void update_ending(void)
{
	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

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

	if (Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_MAIN);
	}
}

void render_ending(void)
{
	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 3; ++i)
	{
		Text* text = data->TitleText[i];
		int32 len = TextLen(text);
		COORD coord = data->TitleCoords[i];
		Renderer_DrawText(text, len, coord.X, coord.Y);
	}
}

void release_ending(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

#pragma endregion

<<<<<<< HEAD
=======

>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
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
	assert(SCENE_NULL < scene && scene < SCENE_MAX);

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

	case SCENE_BETTING:
		g_Scene.Init = init_betting;
		g_Scene.Update = update_betting;
		g_Scene.Render = render_betting;
		g_Scene.Release = release_betting;
		break;

	case SCENE_MAIN:
<<<<<<< HEAD
		g_Scene.Init = init_main;
		g_Scene.Update = update_main;
		g_Scene.Render = render_main;
		g_Scene.Release = release_main;
		break;
	//case SCENE_CLEAR:
	//	g_Scene.Init = init_ending;
	//	g_Scene.Update = update_ending;
	//	g_Scene.Render = render_ending;
	//	g_Scene.Release = release_ending;
	//	break;
	//case SCENE_SCOREINFO:
	//	g_Scene.Init = init_ending;
	//	g_Scene.Update = update_ending;
	//	g_Scene.Render = render_ending;
	//	g_Scene.Release = release_ending;
	//	break;
=======
		g_Scene.Init = init_Main;
		g_Scene.Update = update_Main;
		g_Scene.Render = render_Main;
		g_Scene.Release = release_Main;
		break;
	//case SCENE_GAMECLEAR:
	//	g_Scene.Init = init_gameclear;
	//	g_Scene.Update = update_gameclear;
	//	g_Scene.Render = render_gameclear;
	//	g_Scene.Release = release_gameclear;
	//	break;
	//case SCENE_SCOREINFO:
	//	g_Scene.Init = init_scoreinfo;
	//	g_Scene.Update = update_scoreinfo;
	//	g_Scene.Render = render_scoreinfo;
	//	g_Scene.Release = release_scoreinfo;


		break;
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
	}

	g_Scene.Init();

	s_nextScene = SCENE_NULL;
}