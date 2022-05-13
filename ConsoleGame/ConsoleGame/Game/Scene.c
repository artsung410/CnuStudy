#include "Scene.h"
#include "Common.h"

#include "Framework/Text.h"
#include "Framework/Input.h"
#include "Framework/Renderer.h"

Scene g_Scene;

static ESceneType s_nextScene;

typedef struct tagTitleSceneData
{
	Text TitleText[128];
} TitleSceneData;

void titleSceneInit(void) //init 데이터로드 , 초기화 담당
{
	g_Scene.Data = malloc(sizeof (TitleSceneData));
}

Text arr[128];
void titleSceneUpdate(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	TextCopyWithWhite(data->TitleText, L"테런");

	//스페이스키 누르면 "메롱" 출력
	if (Input_GetKey(VK_SPACE))
	{
		TextCopyWithWhite(data->TitleText, L"메롱");
	}
	
}

void titleSceneRender(void)
{
	TitleSceneData* data = (TitleSceneData*)g_Scene.Data;

	Renderer_DrawText(data->TitleText, TextLen(data->TitleText), 10, 5);
}

void titleSceneRelease(void)
{
	free(g_Scene.Data);
	g_Scene.Data = NULL;
}

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
	assert(s_nextScene != SCENE_NULL);
	assert(SCENE_NULL < scene && scene < SCENE_MAX);
	//다음씬 지정하기
	s_nextScene = scene;
}

void Scene_Change(void)
{
	assert(s_nextScene == SCENE_NULL); //왜 쓰는지?
	//이전 씬정리 -> release로 호출
	

	//다음에 로드할 씬에 맞춰서 gScene을 구성
	

	//다음 씬을 초기화 -> init호출

	//s_nextscene을 0으로 초기화
	
}
