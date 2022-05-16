#pragma once

#include "Common.h"
#include "Framework/Text.h"

typedef struct tagCard
{
	COORD	Coord;
	bool isActive;
	Text	Text;

} Card;

typedef enum cardType
{
	CARD_NULL,
	CIVILIAN,
	KIMG,
	SLAVE,
} cardType;

void Card_Init(Card* card, struct tagGun* gun);

void Card_Update(Card* card);

void Card_Render(Card* card);

void Card_Release(Card* card);