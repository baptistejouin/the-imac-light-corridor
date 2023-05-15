#pragma once

#include <vector>

#include "3D_tools.h"
#include "ball.h"
#include "racket.h"
#include "corridor.h"
#include "obstacle.h"

enum class GameStatus
{
	MENU,
	IN_GAME
};

typedef struct Game
{
	GameStatus status;
	Racket *racket;
	Ball *ball;
	bool isMoving;
	std::vector<Obstacle *> *obstacles;
	Cursor *cursor;
} Game;

void *initGame(Game *game);
void gameLoop(GLFWwindow *window, Game *game);