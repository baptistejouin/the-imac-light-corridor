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
void moveBall(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstacles, GameStatus *status);
void handleCollision(Ball *ball, Racket *racket, std::vector<Obstacle *> *obstacles, GameStatus *status);
void moveBallOnKey(Ball *ball);