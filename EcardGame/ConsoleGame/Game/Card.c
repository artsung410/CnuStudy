#include "Scene.h"
#include "Common.h"

#include "Framework/Text.h"
#include "Framework/Input.h"
#include "Framework/Renderer.h"
#include "Framework/Timer.h"

#include "Card.h"

void Card_Init(Card* card, struct tagGun* gun);



void Card_Update(Card* card);


void Card_Render(Card* card);


void Card_Release(Card* card);
