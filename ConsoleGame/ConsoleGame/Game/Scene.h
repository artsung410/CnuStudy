#pragma once

#include "Type.h"

typedef struct tagScene
{
	void (*Init)(void);		// 씬 초기화 함수
	void (*Update)(void);	// 업데이트
	void (*Render)(void);	// 렌더
	void (*Release)(void);	// 씬에서 사용한 자원정리
	void* Data;
} Scene;


typedef enum tagSceneType
{
	SCENE_NULL,
	SCENE_TITLE,
	SCENE_MAX
} ESceneType;

extern Scene g_Scene; // 현재 그리고있는 씬

/// <summary>
/// 다음 씬으로 전활될 예정인가>?
/// </summary>
/// <returns>전환될 예정이면 true, 그대로면 false</returns>
bool Scene_IsSetNextScene(void);

/// <summary>
/// 다음씬을 지정한다
/// </summary>
/// <param name="scene">씬</param>
void Scene_SetNextScene(ESceneType scene);

/// <summary>
/// 씬 전환
/// </summary>
/// <param name="scene"></param>
void Scene_Change(void);