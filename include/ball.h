#pragma once

#include <math.h>
#include <algorithm>

#include "game.h"
#include "3D_tools.h"
#include "racket.h"
#include "obstacle.h"

struct Life;
typedef struct Ball
{
	Coordinate coordinate;
	float size;
	bool isSticky;
	Speed speed;
	Color color;
} Ball;

void drawBall(Ball *ball);
void moveBall(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstacles, GameStatus *status, Life *lifeCount);
void handleCollision(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstacles, GameStatus *status, Life *lifeCount);
void moveBallOnKey(Ball *ball);