#pragma once

#include <vector>

#include "3D_tools.h"
#include "ball.h"
#include "racket.h"
#include "corridor.h"
#include "obstacle.h"

typedef struct Game
{
	GameStatus status;
	Racket *racket;
	Ball *ball;
	bool isMoving;
	int lifeCount;
	std::vector<Obstacle *> *obstacles;
	std::vector<Line *> *lines;
	Cursor *cursor;
} Game;

void *initGame(Game *game);
void gameLoop(GLFWwindow *window, Game *game);