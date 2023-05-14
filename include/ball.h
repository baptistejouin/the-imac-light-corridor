#pragma once

typedef struct Ball
{
	double pos_x, pos_y, pos_z;
	double speed_x, speed_y, speed_z;
	float size = 0.5f;
	bool isSticky = true;
} Ball;

void drawBall();
void moveBall();
void collision_walls();
void collision_racket();