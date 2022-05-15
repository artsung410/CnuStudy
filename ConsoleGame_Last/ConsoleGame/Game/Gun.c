#include "Gun.h"

void Gun_Init(Gun* gun)
{
	for (int32 i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		Bullet_Init(&gun->Bullet[i], gun);
	}
	gun->BulletCount = 0;
}

void Gun_Update(Gun* gun)
{
	for (int32 i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		Bullet_Update(&gun->Bullet[i]);
	}
}

void Gun_Render(Gun* gun)
{
	for (int32 i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		Bullet_Render(&gun->Bullet[i]);
	}
}

void Gun_Release(Gun* gun)
{
	for (int32 i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		Bullet_Release(&gun->Bullet[i]);
	}
}

void Gun_Shoot(Gun* gun, int32 x, int32 y)
{
	if (MAX_BULLET_COUNT == gun->BulletCount)
	{
		return;
	}

	for (int32 i = 0; i < MAX_BULLET_COUNT; ++i)
	{
		if (false == gun->Bullet[i].IsActive)
		{
			Bullet_Spawn(&gun->Bullet[i], x, y);
			++gun->BulletCount;

			break;
		}
	}
}
