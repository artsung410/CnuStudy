#pragma once

#include "Type.h"
#include "Bullet.h"

#include "Framework/Text.h"

#define MAX_BULLET_COUNT 100

typedef struct tagGun
{
	int32	BulletCount;
	Bullet	Bullet[MAX_BULLET_COUNT];
} Gun;

void Gun_Init(Gun* gun);
void Gun_Update(Gun* gun);
void Gun_Render(Gun* gun);
void Gun_Release(Gun* gun);
void Gun_Shoot(Gun* gun, int32 x, int32 y);