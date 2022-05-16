#include "Gun.h"

void Gun_Init(Gun* gun)
{
	for (int32 i = 0; i < 20; ++i)
	{
		Bullet_Init(&gun->Bullet[i], gun);
	}
	gun->BulletCount = 0;
}

void Gun_Update(Gun* gun)
{
	for (int32 i = 0; i < 20; ++i)
	{
		Bullet_Update(&gun->Bullet[i]);
	}
}

void Gun_Render(Gun* gun)
{
	for (int32 i = 0; i < 20; ++i)
	{
		Bullet_Render(&gun->Bullet[i]);
	}
}

void Gun_Release(Gun* gun)
{
	for (int32 i = 0; i < 20; ++i)
	{
		Bullet_Release(&gun->Bullet[i]);
	}
}

void Gun_Fire_Shot(Gun* gun, int32 x, int32 y)
{
	if (MAX_BULLET_COUNT == gun->BulletCount)
	{
		return;
	}

	for (int32 i = 0; i < 20; ++i)
	{
		if (false == gun->Bullet[i].IsActive)
		{
			TextCopy(&gun->Bullet[i].Text, L"¡Û", TEXT_COLOR_YELLOW | TEXT_COLOR_STRONG);

			Bullet_Spawn(&gun->Bullet[i], x, y);
			++gun->BulletCount;

			break;
		}
	}
}

void Gun_Poison_Shot(Gun* gun, int32 x, int32 y)
{
	if (MAX_BULLET_COUNT == gun->BulletCount)
	{
		return;
	}

	for (int32 i = 0; i < 20; ++i)
	{
		if (false == gun->Bullet[i].IsActive)
		{
			TextCopy(&gun->Bullet[i].Text, L"¡Û", TEXT_COLOR_RED | TEXT_COLOR_BLUE | TEXT_COLOR_STRONG);

			Bullet_Spawn(&gun->Bullet[i], x, y);
			++gun->BulletCount;

			break;
		}
	}
}

void Gun_Frozen_Shot(Gun* gun, int32 x, int32 y)
{
	if (MAX_BULLET_COUNT == gun->BulletCount)
	{
		return;
	}

	for (int32 i = 0; i < 20; ++i)
	{
		if (false == gun->Bullet[i].IsActive)
		{
			TextCopy(&gun->Bullet[i].Text, L"¡Û", TEXT_COLOR_BLUE | TEXT_COLOR_STRONG);

			Bullet_Spawn(&gun->Bullet[i], x, y);
			++gun->BulletCount;

			break;
		}
	}
}