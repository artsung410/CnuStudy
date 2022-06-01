#include "stdafx.h"
#include "Scene.h"
#include "Framework.h"
#include "CsvParser.h"

Scene g_Scene;

static ESceneType s_nextScene = SCENE_NULL;

#pragma region TitleScene

typedef struct TitleSceneData
{
	Image	TitleBackGroundImage;
	Image	GameStartImage;
	Image	CursorImage;
	COORD	CursorPos;
	Music	BGM;
} TitleSceneData;

void init_title(void)
{
	g_Scene.Data = malloc(sizeof(TitleSceneData));
	memset(g_Scene.Data, 0, sizeof(TitleSceneData));

	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Image_LoadImage(&data->TitleBackGroundImage, "TitleImage.png");
	Image_LoadImage(&data->GameStartImage, "GameStartImage.png");
	Image_LoadImage(&data->CursorImage, "CursorImage.png");

	Audio_LoadMusic(&data->BGM, "Background.mp3");
	Audio_Play(&data->BGM, INFINITY_LOOP);
}

#define GameStartPosX 528
#define GameStartPosY 533

void update_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	if ((Input_GetKeyDown(VK_UP) || Input_GetKeyDown(VK_DOWN)) && data->CursorPos.X == 0 && data->CursorPos.Y == 0)
	{
		data->CursorPos.X = GameStartPosX;
		data->CursorPos.Y = GameStartPosY;
	}
	else if ((Input_GetKeyDown(VK_UP) || Input_GetKeyDown(VK_DOWN)) && data->CursorPos.X != 0 && data->CursorPos.Y != 0)
	{
		data->CursorPos.X = 0;
		data->CursorPos.Y = 0;
	}

	if (Input_GetKeyDown(VK_SPACE) && data->CursorPos.X == GameStartPosX && data->CursorPos.Y == GameStartPosY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
	}
}

void render_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Renderer_DrawImage(&data->TitleBackGroundImage, 0, 0);
	Renderer_DrawImage(&data->GameStartImage, 559, 545);

	if (data->CursorPos.X != 0 && data->CursorPos.Y != 0)
	{
		Renderer_DrawImage(&data->CursorImage, data->CursorPos.X, data->CursorPos.Y);
	}
}

void release_title(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Audio_FreeMusic(&data->BGM);
	SafeFree(g_Scene.Data);
}
#pragma endregion

#pragma region ContentScene
typedef struct tagConetentSceneData {
	int32		id;
	Image		BackGroundImage;
	Image		BackPaper;
	Image		CursorImage;
	Music		BGM;
	SoundEffect Effect[2];
	Text		TitleLine[1];
	Text		TextLine[TEXTLINE_COUNT];
	Text		SelectLine[3];
	int32		CursorX;
	int32		CursorY;
	int32		X;
	int32		Y;
} ContentSceneData;

static int32 id[83] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82};
static int32 n = 0;


#define CursorpointY 485
#define CursorpointY_1 545
#define CursorpointY_2 605 

void init_content(void)
{
	g_Scene.Data = malloc(sizeof(ContentSceneData));
	memset(g_Scene.Data, 0, sizeof(ContentSceneData));

	ContentSceneData* data = (ContentSceneData*)g_Scene.Data;

	Image_LoadImage(&data->BackGroundImage, ReturnBackGroundImage(id[n]));
	Image_LoadImage(&data->BackPaper, "BackPaper.png");
	Image_LoadImage(&data->CursorImage, ReturnCursorImageImage(id[n]));

	Audio_LoadMusic(&data->BGM, ReturnBGM(id[n]));
	Audio_Play(&data->BGM, INFINITY_LOOP);
	
	data->CursorX = 30;
	data->CursorY = 485;


	for (int32 i = 0; i < 2; i++)
	{
		if (SoundEffectExisted(id[n], i))
		{
			Audio_LoadSoundEffect(&data->Effect[i], ReturnSoundEffect(id[n], i));
			Audio_PlaySoundEffect(&data->Effect[i], INFINITY_LOOP);
		}
	}

	if (TitleExisted(id[n]))
	{
		wchar_t* title = ReturnTitleText(id[n]);
		Text_CreateText(&data->TitleLine[0], "GongGothicMedium.ttf", 40, title, wcslen(title));
	}

	for (int32 i = 0; i < TEXTLINE_COUNT; i++)
	{
		wchar_t* content = ReturnContentText(id[n], i);
		Text_CreateText(&data->TextLine[i], "GongGothicLight.ttf", 20, content, wcslen(content));
	}

	for (int32 i = 0; i < 3; i++)
	{
		if (SelectExisted(id[n], i)) 
		{
			Text_CreateText(&data->SelectLine[i], "GongGothicMedium.ttf", 30, ReturnSelect(id[n], i), wcslen(ReturnSelect(id[n], i)));
		}
	}



}
static bool a = false;
void update_content(void)
{
	ContentSceneData* data = (ContentSceneData*)g_Scene.Data;

	// 커서이동
	if ((Input_GetKeyDown(VK_DOWN)) && data->CursorX == 30 && data->CursorY == CursorpointY)
	{
		data->CursorY = CursorpointY_1;
	}
	else if ((Input_GetKeyDown(VK_UP)) && data->CursorX == 30 && data->CursorY == CursorpointY_1)
	{
		data->CursorY = CursorpointY;
	}
	else if ((Input_GetKeyDown(VK_DOWN)) && data->CursorX == 30 && data->CursorY == CursorpointY_1)
	{
		data->CursorY = CursorpointY_2;
	}
	else if ((Input_GetKeyDown(VK_UP)) && data->CursorX == 30 && data->CursorY == CursorpointY_2)
	{
		data->CursorY = CursorpointY_1;
	}

	if (Input_GetKeyDown(VK_SPACE) && id[n] == 1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 1;
	}

	if (id[n] == 2 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 2;
	}

	if (id[n] == 3 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 3;
	}

	if (id[n] == 4 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 6;
	}
	if (id[n] == 4 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 7;
	}
	if (id[n] == 4 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 4;
	}

	if (id[n] == 7 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 3;
	}

	if (id[n] == 8 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 3;
	}

	if (id[n] == 5 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 8;
	}

	if (id[n] == 5 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 9;
	}

	if (id[n] == 5 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 5;
	}

	if (id[n] == 6 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 10;
	}

	if (id[n] == 6 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 3;
	}

	if (id[n] == 6 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_2)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 11;
	}

	if (id[n] == 8 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 4;
	}

	if (id[n] == 9 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 4;
	}

	if (id[n] == 10 && Input_GetKeyDown(VK_SPACE))
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 4;
	}

	if (id[n] == 11 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 5;
	}

	if (id[n] == 11 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 2;
	}

	if (id[n] == 11 && Input_GetKeyDown(VK_SPACE) && data->CursorY == CursorpointY_1)
	{
		Scene_SetNextScene(SCENE_CONTENT);
		return n = 12;
	}

	


	

	


}
void render_content(void)
{
	ContentSceneData* data = (ContentSceneData*)g_Scene.Data;

	Renderer_DrawImage(&data->BackGroundImage, 0, 0);
	Renderer_DrawImage(&data->BackPaper, 0, 0);
	Renderer_DrawImage(&data->CursorImage, data->CursorX, data->CursorY);

	if (TitleExisted(id[n]))
	{
		SDL_Color color = { .r = 255, .g = 255, .b = 255, .a = 255 };
		Renderer_DrawTextSolid(&data->TitleLine[0], 100, 30, color);
	}

	for (int32 i = 0; i < TEXTLINE_COUNT; ++i)
	{
		SDL_Color color = { .r = 255, .g = 255, .b = 255, .a = 255 };
		Renderer_DrawTextSolid(&data->TextLine[i], 100, 150 + 40 * i, color);
	}

	for (int32 i = 0; i < 3; ++i) {
		if (SelectExisted(id[n], i)) {
			SDL_Color color = { .r = 255, .g = 255, .b = 255, .a = 255 };
			Renderer_DrawTextSolid(&data->SelectLine[i], 70, 500 + 60 * i, color);
		}
	}

}

void release_content(void)
{
	ContentSceneData* data = (ContentSceneData*)g_Scene.Data;

	Audio_FreeMusic(&data->BGM);
	for (int32 i = 0; i < 2; i++)
	{
		if (SoundEffectExisted(id[n], i))
		{
			Audio_FreeSoundEffect(&data->Effect[i]);
		}
	}
	
	SafeFree(g_Scene.Data);
}
#pragma endregion

#pragma region EndingScene
const wchar_t* str2[] = {
	L"김 PD 살인사건",
	L"",
	L"하이파이브",
	L"",
	L"제작",
	L"",
	L"기획",
	L"",
	L"김 태희",
	L"장 건",
	L"",
	L"프로그래밍",
	L"",
	L"박 현수",
	L"성 권문",
	L"김 동현",
	L"",
	L"The End"
};

typedef struct EndingSceneData
{
	Text		GuideLine[GUIDELINE_COUNT];
	Music		BGM;
	float		Volume;
	SoundEffect Effect;
	Image		BackGround;
	Image		BackPaper;
	float		Speed;
	int32		X;
	int32		Y;
	int32		Alpha;
} EndingSceneData;

void init_ending(void)
{
	g_Scene.Data = malloc(sizeof(EndingSceneData));
	memset(g_Scene.Data, 0, sizeof(EndingSceneData));

	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;
	Image_LoadImage(&data->BackGround, "TitleImage.png");
	Image_LoadImage(&data->BackPaper, "BackPaper.png");

	for (int32 i = 0; i < GUIDELINE_COUNT; ++i)
	{
		Text_CreateText(&data->GuideLine[i], "GongGothicBold.ttf", 30, str2[i], wcslen(str2[i]));
	}

	Audio_LoadMusic(&data->BGM, "Denouement.mp3");
	Audio_PlayFadeIn(&data->BGM, INFINITY_LOOP, 3000);

	data->Volume = 1.0f;

	data->Speed = 400.0f;
	data->X = 400;
	data->Y = 400;
	data->Alpha = 255;
}

void update_ending(void)
{
	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

}

int upPixel = 0;
int count = 0;

void render_ending(void)
{
	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

	Renderer_DrawImage(&data->BackGround, 0, 0);
	Renderer_DrawImage(&data->BackPaper, 0, 0);

	for (int32 i = 0; i < GUIDELINE_COUNT; ++i)
	{
		if (900 - upPixel > 100)
		{
			SDL_Color color = { .r = 255, .g = 255, .b = 255, .a = 255 };
			Renderer_DrawTextSolid(&data->GuideLine[i], 75, 900 + 30 * i - upPixel, color);
		}
		else
		{
			SDL_Color color = { .r = 255, .g = 255, .b = 255, .a = 255 };
			Renderer_DrawTextSolid(&data->GuideLine[i], 75, 100 + 30 * i, color);
		}
	}

	upPixel += 5;
}

void release_ending(void)
{
	EndingSceneData* data = (EndingSceneData*)g_Scene.Data;

	for (int32 i = 0; i < 10; ++i)
	{
		Text_FreeText(&data->GuideLine[i]);
	}
	Audio_FreeMusic(&data->BGM);
	Audio_FreeSoundEffect(&data->Effect);

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
	case SCENE_CONTENT:
		g_Scene.Init = init_content;
		g_Scene.Update = update_content;
		g_Scene.Render = render_content;
		g_Scene.Release = release_content;
		break;
	case SCENE_ENDING:
		g_Scene.Init = init_ending;
		g_Scene.Update = update_ending;
		g_Scene.Render = render_ending;
		g_Scene.Release = release_ending;
		break;
	}

	g_Scene.Init();

	s_nextScene = SCENE_NULL;
}