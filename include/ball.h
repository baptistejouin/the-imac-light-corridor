#pragma once

#include <algorithm>

#include "3D_tools.h"
#include "racket.h"

typedef struct Ball
{
	Coordinate coordinate;
	float size;
	bool isSticky;
	Speed speed;
	Color color;
} Ball;

void drawBall(Ball *ball);
void moveBall(Ball *ball, Racket *racket, bool isMoving);
void handleCollision(Ball *ball, Racket *racket);