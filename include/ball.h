#pragma once

#include <math.h>
#include <algorithm>

#include "3D_tools.h"
#include "racket.h"
#include "obstacle.h"

typedef struct Ball
{
	Coordinate coordinate;
	float size;
	bool isSticky;
	Speed speed;
	Color color;
} Ball;

void drawBall(Ball *ball);
void moveBall(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstacles, GameStatus *status, int *lifeCount);
void handleCollision(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstacles, GameStatus *status, int *lifeCount);
void moveBallOnKey(Ball *ball);