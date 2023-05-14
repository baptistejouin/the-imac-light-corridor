#pragma once

#include <vector>

#include "3D_tools.h"
#include "draw_scene.h"
#include "ball.h"
#include "racket.h"
#include "walls.h"
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
	std::vector<Obstacle *> *obstacles;
	Cursor *cursor;
} Game;

void *initGame(Game *game);
void gameLoop(GLFWwindow *window, Game *game);