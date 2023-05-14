#pragma once

#include "3D_tools.h"

typedef struct Ball
{
	Coordinate coordinate;
	double speed_x, speed_y, speed_z;
	float size = 1.0f;
	bool isSticky = true;
} Ball;

void drawBall(Ball *ball);
void moveBall(Ball *ball);