#pragma once

#include "Type.h"

typedef struct tagScene
{
	void (*Init)(void);		// 씬을 초기화 하는 함수
	void (*Update)(void);	// 업데이트
	void (*Render)(void);	// 렌더
	void (*Release)(void);	// 씬에서 사용한 자원을 정리
	void* Data;
} Scene;

typedef enum tagSceneType
{
	SCENE_NULL,
	SCENE_TITLE,
	SCENE_BETTING,
	SCENE_MAIN,
<<<<<<< HEAD
	SCENE_CLEAR,
=======
	SCENE_GAMECLEAR,
>>>>>>> aebd807fd3c79d2fd9a66bf19f3ffd574765bdcd
	SCENE_SCOREINFO,
	SCENE_RESULT,
	SCENE_MAX
} ESceneType;

extern Scene g_Scene;

/// <summary>
/// 다음 씬으로 전환될 예정인가?
/// </summary>
/// <returns>다음 씬으로 전환될 예정이면 true, 아니면 false</returns>
bool Scene_IsSetNextScene(void);

/// <summary>
/// 다음 씬을 지정한다.
/// </summary>
/// <param name="scene">씬</param>
void Scene_SetNextScene(ESceneType scene);

/// <summary>
/// 씬 전환
/// </summary>
/// <param name=""></param>
void Scene_Change(void);
