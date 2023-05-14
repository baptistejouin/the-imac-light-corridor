#pragma once

#include "3D_tools.h"

typedef struct Ball
{
	Coordinate coordinate;
	float size = 1.0f;
	bool isSticky = true;
	float speed = 0.1f;
} Ball;

void drawBall(Ball *ball);
void moveBall(Ball *ball);