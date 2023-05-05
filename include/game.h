#pragma once

#include "draw_scene.h"
#include "ball.h"

enum class GameStatus
{
	MENU,
	IN_GAME
};

struct Game
{
	GameStatus status;
};

void initGame();
void gameLoop();