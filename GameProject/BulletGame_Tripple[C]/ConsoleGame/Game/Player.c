#include "Player.h"

#include "Framework/Input.h"
#include "Framework/Renderer.h"

void Player_Init(Player* player)
{
	TextCopyWithWhite(&player->Text, L"P");
	SetCoord(player->Coord, 0, 0);
	Gun_Init(&player->Gun);
}

void Player_Update(Player* player)
{
	if (Input_GetKey(VK_DOWN))
	{
		++player->Coord.Y;
	}

	if (Input_GetKey(VK_UP))
	{
		--player->Coord.Y;
	}

	if (Input_GetKey(VK_LEFT))
	{
		--player->Coord.X;
	}

	if (Input_GetKey(VK_RIGHT))
	{
		++player->Coord.X;
	}

	if (Input_GetKeyDown(0x31))
	{
		Gun_Fire_Shot(&player->Gun, player->Coord.X + 1, player->Coord.Y);
	}

	if (Input_GetKeyDown(0x32))
	{
		Gun_Poison_Shot(&player->Gun, player->Coord.X + 1, player->Coord.Y);
	}

	if (Input_GetKeyDown(0x33))
	{
		Gun_Frozen_Shot(&player->Gun, player->Coord.X + 1, player->Coord.Y);
	}
	//if (Input_GetKeyDown(VK_F1) && !isBulletYellow)
	//{
	//	isBulletYellow = true;
	//	isBulletMazenta = false;
	//}

	//if (Input_GetKeyDown(VK_F2) && !isBulletMazenta)
	//{
	//	isBulletMazenta = true;
	//	isBulletYellow = false;
	//}

	Gun_Update(&player->Gun);
}

void Player_Render(Player* player)
{
	Text* text = &player->Text;
	Renderer_DrawText(text, 1, player->Coord.X, player->Coord.Y);

	Gun_Render(&player->Gun);
}

void Player_Release(Player* player)
{
	Gun_Release(&player->Gun);
}