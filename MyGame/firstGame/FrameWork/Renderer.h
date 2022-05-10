#pragma once

#include "Type.h"

// 랜더러 초기화
// 초기화성공하면 true, 아니면 false
bool Renderer_Init(void);

//랜더러 정리
void Renderer_Cleanup(void);

// 화면바꾸기
void Renderer_Flip(void);

//텍스트를 출력한다 한줄만
void  Renderer_DrawText(const char* text, int32 numberOfChar);