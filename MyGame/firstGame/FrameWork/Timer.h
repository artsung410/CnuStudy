#pragma once

/// <summary>
/// 타이머를 초기화한다.
/// </summary>
// 고정할 FPS
void Timer_Init(int32 fps);

/// <summary>
/// 타이머를 업데이트한다.
/// </summary>
/// 업데이트 성공시 true, 아니면 false
bool Timer_Update(void);

/// <summary>
/// 델타타임을 구한다.
/// </summary>
/// <return>DeltaTime : 프레임 간의 시간. 이전 프레임으로부터 현재 프레임을 시작할 때까지 걸린 시간</return>
float Timer_GetDeltaTime(void);

#define DELTA_TIME Timer_GetDeltaTime();